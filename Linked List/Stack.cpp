/*
	STACK
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * next;
}*first, *last;
//first = First One To Exit

void Push(int iPush) {
	struct node * temp;
	temp = (node*)malloc(sizeof(node));
	
	temp->data = iPush;
	temp->next = NULL;

	if(!first){
		first = temp;
		last = temp;
		return;
	}
	
	temp->next = first;
	first = temp;
	return;
}

void Pop() {
	struct node * temp;
	
	if(first == last){
		first = NULL;
		last = NULL;
	
		free(temp);
		return;
	}
	
	temp = first;
	first = temp->next;
	free(temp);
	
}

void List() {
	struct node* temp;
	temp = first;
	
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

main() {
	int count = 6;
	for(int i = 0; i < count ; i++){
		Push(i);
	}
	
	List();
	printf("\n");
	Pop();Pop();Pop();Pop();Pop();Pop();
	printf("\n");
	List();
}
