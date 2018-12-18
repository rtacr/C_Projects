/*		
	QUEUE	
*/		

#include <stdio.h>
#include <stdlib.h>


struct node {
	int data;
	struct node * next;
}*first, *last;

void Pop() {
	struct node* temp;
	
	temp = first;
	
	if(first == last){
		first = NULL;
		last = NULL;
	
		free(temp);
		return;
	}
	
	first = temp->next;
	free(temp);
	//
	return;
}

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
		
	last->next = temp;
	last = temp;
	return;
}

void List(){
	struct node* temp;
	temp = first;
	
	while(temp){
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

main() {
	int count = 20;
	for(int i = 0; i < count ; i++){
		Push(i);
	}
	
	List();
	printf("\n");
	Pop();Pop();Pop();Pop();Pop();Pop();
	printf("\n");
	List();
}
