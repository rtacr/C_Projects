#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

 struct node{
 	int data;
 	struct node *next;
 	struct node *prev;
 }*head,*tail;
 
 
 void ekle(int gelen) {
 	struct node * temp = (node *)malloc(sizeof(node));
 	temp->data = gelen;
 	
 	if(!head){
 		head = temp;
 		tail = temp;
		head->prev = NULL;
		head->next = NULL;
 		return;
 	}
 	temp->prev = tail;
	 tail->next = temp;
	 tail = temp;
	 tail->next = NULL;
	 return;
 }

void listele(bool duz){
	struct node * temp = (node *)malloc(sizeof(node));

 	if(duz) {
		temp = head;
		while(temp){
			printf("%d ", temp->data);
			temp = temp->next;
		}
	}else {
		temp = tail;
		while(temp){
			printf("%d ", temp->data);
			if(temp->prev){
			}
			temp = temp->prev;
		}
	}
	
	return;
}
 
 void sil(int iHedef){
 	struct node * temp = (node *)malloc(sizeof(node));
 	struct node * tempPrev = (node *)malloc(sizeof(node));
 	struct node * tempFw = (node *)malloc(sizeof(node));
 	temp = tail;
 	while(temp){
 		tempPrev = temp->prev;
 		tempFw = temp->next;
 		
 		if(temp->data == iHedef){
 			if(temp == tail){
 				tempPrev->next = NULL;
 				tail = tempPrev;
				free(temp);
 				return;
 			}
 			
 			if(temp == head){
 				tempFw->prev = NULL;
 				head = tempFw;
				free(temp);
 				return;
 			}
 			
 			tempFw->prev = tempPrev;
 			tempPrev->next = tempFw;
 			free(temp);
			return;
 			
 		}
 		temp = temp->prev;
 	}
 }

void sayiGenerate(int iLimit) {
	FILE * fYaz = fopen("input.txt", "w");
	int iSayi, iDigit;
	srand(time(NULL));
	
	for(int i = 0; i < iLimit; i++)	{	
		iDigit = rand()%8;

		iSayi = rand()%10;
		iSayi = pow(iDigit, iSayi);

		fprintf(fYaz, "%d ", iSayi);
	}
	fclose(fYaz);

	FILE * fOku = fopen("input.txt", "r");

	while(!feof(fOku)){
		fscanf(fOku, "%d ", &iSayi);
		ekle(iSayi);
	}
}

int main(){
	int iSil;
	int iLimit;

	printf("Kac Sayi Uretilsin?\n");
	scanf("%d", &iLimit);

	sayiGenerate(iLimit);
	printf("Duz :");
	listele(true);
	printf("\n\n");
	printf("Ters : ");
	listele(false);

	printf("\nSilinecek Sayi = ");
	scanf("%d", &iSil);	
	
	sil(iSil);

	listele(true);
	printf("\n\n");
	listele(false);

	return 0;
}