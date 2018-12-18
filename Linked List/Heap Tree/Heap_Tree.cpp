#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * left;
    struct node * right;
    struct node * parent;
}*root;

int findLevel(struct node * temp){
    int count = 1;

    while(temp->left){
        temp = temp->left;
        count = count + 1;
    }
    return count;
}

struct node * bottomLeftNode(struct node *temp){
    while(temp->left){
        temp = temp->left;
    }    
    return temp;
}

void add(struct node *travel, int x){
    struct node *temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->left = temp->right = NULL;

    if(!root){
        temp->data = x;
        temp->parent = NULL;
        root = temp;
        return;
    }
    
    int level = findLevel(root);
    struct node*t = bottomLeftNode(root);
    t = t->parent;
    
    if(!t->right){
        printf("a");
        t->right = temp;
        temp->parent = t; 
    }
}

void list(struct node* temp){
    if(!temp)   return;
    list(temp->left);
    printf("%d", temp->data);
    list(temp->right);
}

int main(){
    add(root, 10);
    add(root, 15);
    add(root, 7);
    list(root);

    return 0;
}