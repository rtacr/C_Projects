#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct node{
 	int data;
    int iSira;
 	struct node *next;
	struct node *prev;
}*head;
 
 
 void ekle(int gelen, int iSira) {
 	struct node * temp = (node *)malloc(sizeof(node));
    struct node * tempPrev;

 	temp->data = gelen;
    temp->iSira = iSira;
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

void NodeSil(int iIndex){
	struct node * temp = (node *)malloc(sizeof(node));
 	struct node * tempPrev;
 	struct node * tempFW;

    temp = head;
	tempPrev = temp;

	if(head->next == head && head->iSira == iIndex){
		head->next = NULL;
		head->prev = NULL;
		free(temp);
		return;
	}

    while(temp->next != head){

		if(temp->iSira == iIndex){
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

void basla(int iDiziBoyut){
	struct node * temp;
	struct node * temp2;

	int iDeger, iSira;

	bool cw;

	int kontrol = iDiziBoyut;
	
	FILE *fYaz = fopen("masaOut.txt", "w");

	temp = head;
	iDeger = temp->data;
	temp2 = head;

	while(iDiziBoyut > 0){
		temp = temp2;
		if(kontrol == iDiziBoyut){
		
			if(iDeger %2==0){
				cw = false;

			}else{
				cw = true; 

			}

		}else{
			if(iDeger %2==0){
				cw = true;

			}else{
				cw = false; 

			}
		}

		if(cw){
			
			for(int i = 0; i < iDeger; i++)	{
				temp = temp->next;
			}

			iDeger = temp->data;

			if(iDeger %2 == 0){
			
				temp2 = temp->prev;
				iDeger--;			
			}else{
			
				temp2 = temp->next;
				iDeger--;			
			}

			fprintf(fYaz, "%d\n", temp->iSira);
			NodeSil(temp->iSira);

		}else{

			for(int i = 0; i < iDeger; i++)	{
				temp = temp->prev;
			}
			iDeger = temp->data;

			if(iDeger %2 == 0){
				temp2 = temp->prev;
				iDeger--;
			}else{
				temp2 = temp->next;
				iDeger--;
			}
			fprintf(fYaz, "%d\n", temp->iSira);
			NodeSil(temp->iSira);
		}
		iDiziBoyut--;
	}
	fclose(fYaz);
}

void DosyadanOku() {
	int iSayi;
	int iDiziBoyut;
    int index = 1;

    FILE * fOku = fopen("masaIn.txt", "r");
    fscanf(fOku, "%d", &iDiziBoyut);
    
	while(!feof(fOku)){
		fscanf(fOku, "%d ", &iSayi);
		ekle(iSayi, index);
        index++;
	}

    fclose(fOku);

    basla(iDiziBoyut);
}

void DosyayaYaz(){
	FILE *fYaz0 = fopen("masaIn.txt", "w");
	srand(time(NULL));

	int boyut = rand()%10;
	fprintf(fYaz0, "%d\n", boyut);
	
	for(int i = 0; i < boyut; i++) {
		fprintf(fYaz0, "%d\n", rand()%10);
	}
	fclose(fYaz0);
}

int main(){
	DosyayaYaz();
	DosyadanOku();

	return 0;
}