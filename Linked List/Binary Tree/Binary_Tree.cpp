#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
}*root;

void add(int x){
    struct node* temp = (node*)malloc(sizeof(node));
    struct node* travel;
    struct node* travelPrev;
    travelPrev = root;
    travel = root;

    temp->left = temp->right = NULL;
    temp->data = x;

    if(!root){
        root = temp;
        return;
    }

    while(travel){
        if(x < travel->data){
            travelPrev = travel;
            travel = travel->left;
        }else{
            travelPrev = travel;
            travel = travel->right;
        }
    }

    if(travelPrev->data < x){
        travelPrev-> right = temp;
    }else{
        travelPrev->left = temp;
    }

    return;
}

struct node *minSearch(struct node * temp){

    while(temp->left){
        temp = temp->left;
    }
    return temp;
}

struct node *removeNode(struct node * temp, int x){
    struct node * temp2;

    if(!temp)    return temp;

    if(x < temp->data)  temp->left = removeNode(temp->left, x);
    else if(x > temp->data) temp->right = removeNode(temp->right, x);
    else{
        if(!temp->left){
            temp2 = temp->right;
            free(temp);
            return temp2;
        }else if(!temp->right){
            temp2 = temp->left;
            free(temp);
            return temp2;
        }

        temp2 = minSearch(temp->right);

        temp->data = temp2->data;

        temp->right = removeNode(temp->right, temp2->data); 
    }

    return NULL;
}

void list(struct node * temp, int orderType){
    if(orderType == 1){
        if(!temp)   return;
        
        list(temp->left, 1);

        printf("%d\n" , temp->data);

        list(temp->right, 1);
    }else if(orderType == 2){
        if(!temp)   return;

        printf("%d\n" , temp->data);

        list(temp->left, 2);
        
        list(temp->right, 2);
    
    }else if(orderType == 3){
        if(!temp)   return;        

        printf("%d\n" , temp->data);

        list(temp->right, 3);
        
        list(temp->left, 3);
    }
}

void randomNumbers(int count){
    srand(time(NULL));
    
    for(int i = 0; i < count; i++){
        int x = rand()%10000;
        add(x);
    }
    

}


int main() {
    int count = 100000;
    int type = 1;
    
    randomNumbers(count);
    
    list(root, type);
    
    removeNode(root, 150);

    printf("\n1-)Inorder List\n2-)Preoder List\n3-)Postorder List\n");
    scanf("%d", &type);

    list(root, type);
    
    return 0;
}