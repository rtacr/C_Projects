#include <stdio.h>
#include <stdlib.h>

struct building {
    int left;
    int height;
    int right;
};

struct node {
    struct building building;
    struct node *next;
}*head, *tail;

void add(int left, int height, int right) {
    struct node * temp = (node*)malloc(sizeof(node));
    struct building tempB;
    
    tempB.left = left;
    tempB.height = height;
    tempB.right = right;
    temp->building = tempB;
    temp->next = NULL;

    if(!head) {
        head = temp;
        tail = temp;
        head->next = NULL;
        return;
    }

    tail->next = temp;
    tail = temp;
    return;
}

int main() {
    add(2,10,5);
    add(1,2,6);

    struct node* travel;

    int maxHeight = 0; 
    int maxBuildingEnd = 0;
    int iColMax = 5;

    travel =head;
    while(travel) {
        printf("left: %d\theight: %d\tright: %d\n", travel->building.left, travel->building.height, travel->building.right);
        travel = travel->next;
    }

    for(int i=0; i<iColMax; i++) {
        
        travel = head;

        while(travel) {
            if(travel->building.left <= i && travel->building.right >= i) {
                if(i > maxBuildingEnd){
                    if(maxHeight < travel->building.height){
                        maxHeight = travel->building.height;
                        maxBuildingEnd = travel->building.right;
                        printf("left: %d\theight: %d", i, maxHeight);
                    }
                }
            }
            travel = travel->next;
        }       

    }

    return 0;
}
