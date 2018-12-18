#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct node{
 	int data;
 	struct node *next;
	struct node *prev;
}*head;
 
 
 void ekle(int gelen) {
 	struct node * temp = (node *)malloc(sizeof(node));
    struct node * tempPrev;

 	temp->data = gelen;
 	temp->next = NULL;
	temp->prev = NULL;

 	if(!head) {
 		head = temp;
		head->next = temp;
		temp->next = head;
		head->prev = head;
 		return;
 	}
    
    tempPrev = head;

    while(tempPrev->next != head){
        tempPrev = tempPrev->next;
    }

    tempPrev->next = temp;
    temp->next = head;
	head->prev = temp;
	temp->prev = tempPrev;
	return;
 }

void listele(bool duz){
	struct node * temp = (node *)malloc(sizeof(node));
	if(duz){
		temp = head;
        printf("%d ", temp->data);
        temp = temp->next;
		while(temp != head){
			printf("%d ", temp->data);
			temp = temp->next;
		}
	}else{
		temp = head;
		
		while(temp->next != head){
			temp = temp->next;
		}

		printf("%d ", temp->data);
		temp = temp->prev;
	
		while(temp != head){
			printf("%d ", temp->data);
			temp = temp->prev;
		}

	}
	return;
}
 
 void sil(int iHedef){
 	struct node * temp = (node *)malloc(sizeof(node));
 	struct node * tempPrev;
 	struct node * tempFW;

    temp = head;
	tempPrev = temp;

	if(head->next == head && head->data == iHedef){
		head->next = NULL;
		head->prev = NULL;
		free(temp);
		return;
	}

    while(temp->next != head){

		if(temp->data == iHedef){
			
			if(temp == head){
				while(tempPrev->next != head){
					tempPrev = tempPrev->next;
				}
				tempFW = temp->next;

				tempPrev->next = tempFW;
				tempFW->prev = tempPrev;
				head = tempFW;
				free(temp);
				return;
			}
			tempFW = temp->next;
            
			tempPrev->next = tempFW;
			tempFW->prev = tempPrev;

            free(temp);
            return;
        }

        tempPrev = temp;
        temp = temp->next;
    }
	tempPrev->next = head;
	head->prev = tempPrev;
	free(temp);
	return;
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
	listele(true);

	printf("\nSilinecek Sayi = ");
	scanf("%d", &iSil);	
	
	sil(iSil);

	listele(false);

	return 0;
}