#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int random_number(int min_num, int max_num);
int pcmove(int k);

void karar1(int a , int b);
void acilis();

int scorex, scorey;
int tasc,kagitc,makasc;
int beraber;

int main(void)
{
	int x,y,z,ikinci;
	
	beraber = 0;
	scorex = scorey = 0;	
	makasc = tasc =  33;
	kagitc = 34;
	
	acilis();
	
	loop:
	
	printf("Tas : 1\nKagit : 2\nMakas : 3\n");
	scanf("%d" , &x);
	
	if(x == 1){
		printf("\nHamleniz : Tas\t");	
	}else if(x == 2){
		printf("\nHamleniz : Kagit\t");
	}else if(x == 3){
		printf("\nHamleniz : Makas\t");
	}else{
		printf("\nHamleniz : Gecersiz\t");
	}
	
	int uc;
	
	y = random_number(1,100);
	ikinci = random_number(1,100);
	uc = (y + ikinci)/2;

	z = pcmove(uc);
	
	if(z == 1){
		printf("Bilgisayarin Hamlesi : Tas\t");	
	}else if(z == 2){
		printf("Bilgisayarin Hamlesi : Kagit\t");
	}else if(z == 3){
		printf("Bilgisayarin Hamlesi : Makas\t");
	}
	 

	printf("\n\nSonuc : ");
	karar1 (x ,z);	
	
	
	printf("\n\nKullanici : %d \t Bilgisayar : %d\n",scorex,scorey);
	
	printf("\nOlasiliklar\nTas : %%%d \t Kagit : %%%d\tMakas : %%%d\n\n",tasc,kagitc,makasc);
	char check;
	printf("Devam Edilsin Mi(E/H)?\n");
	check = getche();
	
		if(check == 'e'){
			system("CLS");
		goto loop;		
		}else if(check == 'h') {
			printf("Oyun Bitti!\n");
			
			if(scorex>scorey){
				printf("Kullanici Kazandi !");
				getch();			
			}else if (scorey>scorex){
				printf("Bilgisayar Kazandi !");
				getch();
			}else{
				printf("Berabere!");
				getch();
			}
		}else {
			printf("Gecersiz");
		
		}
	
	
	
	return 0;
	getch();
}

int pcmove(int k){
	
	int result1 = 1 , result2 = 2,result3 = 3;
	if(k < 100 -(kagitc + makasc)){
		return result1;
	}else if (k > (tasc + kagitc )){
		return result3;
	
	}else {
		return result2;
	}
}

void karar1(int a , int b){
	
	while(beraber >= 3){
			if (b == 1){
				tasc = tasc - 4;
				kagitc = kagitc + 2;
				makasc = makasc + 2;
			}
		beraber = 0;
	}

	if(a == b){
		printf("Berabere !");
		beraber++;
	}else if(a==1 && b==2){
		printf("Bilgisayar Kazandi !");
		
		scorey++;	
		
		kagitc = kagitc+2;
		makasc = makasc-2;
	}else if(a==1 && b==3){
		printf("Kullanici Kazandi !");
		
		scorex++;
		
		makasc = makasc-2;
		tasc = tasc+2;
	}else if(a==2 && b==1){
		printf("Kullanici Kazandi !");
		
		scorex++;
		
		tasc = tasc-2;
		kagitc = kagitc+2;
	}else if(a==2 && b==3){
		printf("Bilgisayar Kazandi !");
		
		scorey++;
		
		kagitc = kagitc-2;
		makasc = makasc+2;
	}else if(a==3 && b==1){
		printf("Bilgisayar Kazandi !");
		
		scorey++;
		
		tasc = tasc+2;
		makasc = makasc-2;
	}else if(a==3 && b==2){
		printf("Kullanici Kazandi !");
		
		scorex++;
		
		kagitc = kagitc-2;
		makasc = makasc+2;
	}
}


int random_number(int min_num, int max_num)
{
	
    int result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1; // include max_num in output
    } else {
        low_num = max_num + 1; // include max_num in output
        hi_num = min_num;
    }

    srand(time(NULL));
    
    result = (rand() % (hi_num - low_num)) + low_num;

	return result;
	
	
}

void acilis(){
	
	printf("Yapay Zeka Yukleniyor\n");
	printf(" =============\n");
	printf("|             |\n");	
	printf(" =============\n");
	Sleep(100);
	
	system("CLS");
	printf("Yapay Zeka Yukleniyor\n");
	printf(" =============\n");
	printf("|*            |\n");	
	printf(" =============\n");
	Sleep(100);
	
	system("CLS");
	printf("Yapay Zeka Yukleniyor\n");
	printf(" =============\n");
	printf("|**           |\n");	
	printf(" =============\n");
	Sleep(100);
	
	system("CLS");
	printf("Yapay Zeka Yukleniyor\n");
	printf(" =============\n");
	printf("|***          |\n");	
	printf(" =============\n");
	Sleep(100);
	
	system("CLS");
	printf("Yapay Zeka Yukleniyor\n");
	printf(" =============\n");
	printf("|****         |\n");	
	printf(" =============\n");
	Sleep(100);
	
	system("CLS");
	printf("Yapay Zeka Yukleniyor\n");
	printf(" =============\n");
	printf("|*****        |\n");	
	printf(" =============\n");
	Sleep(100);
	
	system("CLS");
	printf("Yapay Zeka Yukleniyor\n");
	printf(" =============\n");
	printf("|******       |\n");	
	printf(" =============\n");
	Sleep(100);

	system("CLS");
	printf("Yapay Zeka Yukleniyor\n");
	printf(" =============\n");
	printf("|*******      |\n");	
	printf(" =============\n");
	Sleep(100);

	system("CLS");
	printf("Yapay Zeka Yukleniyor\n");
	printf(" =============\n");
	printf("|********     |\n");	
	printf(" =============\n");
	Sleep(100);

	system("CLS");
	printf("Yapay Zeka Yukleniyor\n");
	printf(" =============\n");
	printf("|*********    |\n");	
	printf(" =============\n");
	Sleep(100);
	
	system("CLS");
	printf("Yapay Zeka Yukleniyor\n");
	printf(" =============\n");
	printf("|**********   |\n");	
	printf(" =============\n");
	Sleep(100);
	
	system("CLS");
	printf("Yapay Zeka Yukleniyor\n");
	printf(" =============\n");
	printf("|***********  |\n");	
	printf(" =============\n");
	Sleep(100);
	
	system("CLS");
	printf("Yapay Zeka Yukleniyor\n");
	printf(" =============\n");
	printf("|************ |\n");	
	printf(" =============\n");
	Sleep(100);
	
	system("CLS");
	printf("Yapay Zeka Yukleniyor\n");
	printf(" =============\n");
	printf("|*************|\n");	
	printf(" =============\n");
	Sleep(100);
	
	system("CLS");
	printf("Yapay Zeka Yuklendi !\n");
	printf(" \n============\n");
	printf("*************|\n");	
	printf(" ============\n");
	Sleep(50);

	system("CLS");
	printf("Yapay Zeka Yuklendi !\n");
	printf("   =============\n");
	printf("  |*************|\n");	
	printf("   =============\n");
	Sleep(50);
	
	system("CLS");
	printf("Yapay Zeka Yuklendi !\n");
	printf(" ===========\n");
	printf("************|\n");	
	printf(" ===========\n");
	Sleep(50);

	system("CLS");
	printf("Yapay Zeka Yuklendi !\n");
	printf(" =============\n");
	printf("|             |\n");	
	printf(" =============\n");
	Sleep(50);
	
	
	system("CLS");
	printf("Yapay Zeka Yuklendi !\n");
	printf(" \n=============\n");
	printf("\n|*************|\n");	
	printf("\n =============\n");
	Sleep(100);

	system("CLS");
	printf("Yapay Zeka Yuklendi !\n");
	printf(" =============\n");
	printf(" *h*e*l*p* *m*e* *p*l*S* * \n");	
	printf(" =============\n");
	Sleep(100);
	
	system("CLS");
	
	
}
