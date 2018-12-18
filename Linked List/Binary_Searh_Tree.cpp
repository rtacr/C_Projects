/*
	BINARY SEARCH TREE
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * left;
	struct node * right;	
}*root;

void Push(int iPush) {
	struct node * temp;
	struct node * temp2;
	struct node * temp3;
	
	bool right = false;
	
	temp = (node *)malloc(sizeof(node));
	
	temp->data = iPush;
	temp->left = temp->right = NULL;
	
	if(!root) {
		root = temp;
		return;
	}
	temp2 = root;
	
	while(temp2){
		if(temp->data <= temp2->data) {
			temp3 = temp2;
			temp2 = temp2->left;
			right = false;
		}else if(temp->data > temp2->data){
			temp3 = temp2;
			temp2 = temp2->right;
			right = true;
		}
	}
	
	if(right){
		temp3->right = temp;
	}else{
		temp3->left = temp;
	}
}

void Pop(){
	
}

void List(){
	struct node * temp;
	
	temp = root;
	printf("\nRight\n");
	
	while(temp){
		printf("%d ", temp->data);
		temp = temp->right;
	}
	
	temp = root;
	printf("\nLeft\n");
	
	while(temp){
		printf("%d ", temp->data);
		temp = temp->left;	
	}

}

main() {
	Push(30);
	Push(15);
	Push(37);
	Push(40);
	Push(7);
	Push(2);

	List();
}
