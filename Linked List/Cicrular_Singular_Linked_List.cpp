#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct node{
 	int data;
 	struct node *next;
}*head;
 
 
 void ekle(int gelen) {
 	struct node * temp = (node *)malloc(sizeof(node));
    struct node * tempPrev;

 	temp->data = gelen;
 	temp->next = NULL;

 	if(!head) {
 		head = temp;
		head->next = temp;
		temp->next = head;
 		return;
 	}
    
    tempPrev = head;

    while(tempPrev->next != head){
        tempPrev = tempPrev->next;
    }

    tempPrev->next = temp;
    temp->next = head;
	return;
 }

void listele(){
	struct node * temp = (node *)malloc(sizeof(node));

		temp = head;
        printf("%d ", temp->data);
        temp = temp->next;
		while(temp != head){
			printf("%d ", temp->data);
			temp = temp->next;
		}
	
	return;
}
 
 void sil(int iHedef){
 	struct node * temp = (node *)malloc(sizeof(node));
 	struct node * tempPrev;
 	
    temp = head;
	tempPrev = temp;

	if(head->next == head && head->data == iHedef){
		head->next = NULL;
		free(temp);
		return;
	}

    while(temp->next != head){

		if(temp->data == iHedef){
	
			if(temp == head){
				while(tempPrev->next != head){
					tempPrev = tempPrev->next;
				}
				tempPrev->next = temp->next;
				head = temp->next;
				free(temp);
				return;
			}

            tempPrev->next = temp->next;
            free(temp);
            return;
        }

        tempPrev = temp;
        temp = temp->next;
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
	listele();

	printf("\nSilinecek Sayi = ");
	scanf("%d", &iSil);	
	
	sil(iSil);

	listele();

	return 0;
}