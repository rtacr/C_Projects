#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <time.h>
#include <cmath>

using namespace std;

void AnaMenu(int iMenuDeger);
void ElementlerMenu(int iMenuDeger);
void ElementEkle(int iMenuDeger);
void ElementSil(int iMenuDeger);
void ElementGuncelle(int iMenuDeger);
void ElementAyrintisiniGosterMenusu(int iMenuDeger);
void ElementBilgisiGoster(int iMenuDeger);
void ElementBilgisiEkle(int iMenuDeger);
void ElementBilgisiSil(int iMenuDeger);
void ElementBilgisiGuncelle(int iMenuDeger);
void RaporlarMenu(int iMenuDeger);
void PeriyodikTabloyuGoster(int iMenuDeger);
void AyarlarMenu(int iMenuDeger);
void Yedekle(int iMenuDeger);
void GeriYukle(int iMenuDeger);
void Cikis(int iMenuDeger);
void Secim(int iMenuDeger,int iMenuSecim);
int funcBackup();
int funcRestore();

char elmAyrintiFile[100] = "elm_ayrinti.txt";
char elementFile[100] = "element.txt";

struct PTG
{
	char elmName[18][10][4];
	int elmNumber[18][10];
} ptgelm;

int main()
{
	AnaMenu(10);
	getch();
	return 0;
}

void AnaMenu(int iMenuDeger)
{
	int iMenuSecim;
	system("COLOR 0F");
	system("cls");
	printf("Elementler Sistemi - Ana Menu\n\n");
	printf("1) Elementler\n");
	printf("2) Raporlar\n");
	printf("3) Ayarlar\n");
	printf("4) Cikis\n\n");
	printf("Lutfen yapmak istediginiz islemi seciniz: ");
	scanf("%d",&iMenuSecim);
	Secim(iMenuDeger,iMenuSecim);	
}

void ElementlerMenu(int iMenuDeger)
{
	int iMenuSecim;
	system("COLOR 0F");
	system("cls");
	printf("Elementler Sistemi - Elementler Menusu\n\n");
	printf("1) Element Ekle\n");
	printf("2) Element Sil\n");
	printf("3) Element Guncelle\n");
	printf("4) Element Ayrintisini Goster\n");
	printf("5) Ust menuye don.\n\n");
	printf("Lutfen yapmak istediginiz islemi seciniz: ");
	scanf("%d",&iMenuSecim);
	Secim(iMenuDeger,iMenuSecim);
}

void ElementEkle(int iMenuDeger)
{
	char name[2];
	char islemSecim;
	int g,p,num;
	system("COLOR 0F");
	system("cls");
	printf("Elementler Sistemi - Element Ekle\n\n");
	FILE * fp = fopen("element.txt" , "a");
	printf("Elementin grubu : ");
	scanf("%d" , &g);
	g=g-1;
	
	printf("Elementin periyodu : ");
	scanf("%d" , &p);
	p=p-1;
	
	printf("Elementin atom numarasý : ");
	scanf("%d" , &num);
	
	printf("Elementin kisa adi : ");
	scanf("%s" , name);
	
	fprintf(fp , "%d\t%d\t%d\t%s\n" , g , p , num , name);
	
	fclose(fp);
	printf("Element eklemeye devam etmek istiyor musunuz?(E/H)");
	islemSecim=getche();
	if(islemSecim=='e' || islemSecim=='E')
	Secim(iMenuDeger,1);
	else if(islemSecim=='h' || islemSecim=='H')
	Secim(iMenuDeger,0);
	getch();
}

void ElementSil(int iMenuDeger)
{
	char name[2];
	char islemSecim;
	int g,p,num,gnum;
	int elementKontrol=0;
	system("COLOR 0F");
	system("cls");
	printf("Elementler Sistemi - Element Sil\n\n");
	FILE * fp = fopen("element.txt" , "r");
	FILE * fw = fopen("new.txt" , "w");
	printf("Elementin atom numarasi : ");
	scanf("%d" , &gnum);
	while (!feof(fp)){
		fscanf(fp , "%d\t%d\t%d\t%s\n" , &g , &p , &num , name);
		if(num==gnum){
			elementKontrol=1;
		}
		else
		fprintf(fw , "%d\t%d\t%d\t%s\n" , g , p , num , name);
	}
	if(elementKontrol==0){
		printf("Element bulunamadi.");
	}
	fclose(fp);
	fclose(fw);
	remove("element.txt");
	rename("new.txt","element.txt");
	printf("Islem tamamlandi.");
	Sleep(1500);
	Secim(iMenuDeger,0);
}

void ElementGuncelle(int iMenuDeger)
{
	char name[2];
	char islemSecim;
	int g,p,num,gnum,ynum;
	int elementKontrol=0;
	system("COLOR 0F");
	system("cls");
	printf("Elementler Sistemi - Element Guncelle\n\n");
	FILE * fp = fopen("element.txt" , "r");
	FILE * fw = fopen("new.txt" , "w");
	printf("Elementin atom numarasi : ");
	scanf("%d" , &gnum);
	while (!feof(fp)){
		fscanf(fp , "%d\t%d\t%d\t%s\n" , &g , &p , &num , name);
		if(num==gnum){
			elementKontrol=1;
			printf("Elementin guncel grubu : ");
			scanf("%d" , &g);
			g=g-1;
			
			printf("Elementin guncel periyodu : ");
			scanf("%d" , &p);
			p=p-1;
			
			printf("Elementin guncel atom numarasi : ");
			scanf("%d" , &num);
			
			printf("Elementin guncel kisa adi : ");
			scanf("%s" , name);
	
			
			fprintf(fw , "%d\t%d\t%d\t%s" , g , p , num , name);
		}
		else
		fprintf(fw , "%d\t%d\t%d\t%s\n" , g , p , num , name);
	}
	if(elementKontrol==0){
		printf("Element bulunamadi.");
	}
	fclose(fp);
	fclose(fw);
	remove("element.txt");
	rename("new.txt","element.txt");
	printf("Islem tamamlandi.");
	Sleep(1500);
	Secim(iMenuDeger,0);
}
//Elementler Menusunun Alt Menuleri
void ElementAyrintisiniGosterMenusu(int iMenuDeger)
{
	int iMenuSecim;
	system("COLOR 0F");
	system("cls");
	printf("Elementler Sistemi - Element Ayrintisini Goster Menusu\n\n");
	printf("1) Element Hakkinda Bilgi Goster\n");
	printf("2) Element Hakkinda Bilgi Ekle\n");
	printf("3) Element Hakkinda Bilgi Sil\n");
	printf("4) Element Hakkinda Bilgi Guncelle\n");
	printf("5) Ust menuye don.\n\n");
	printf("Lutfen yapmak istediginiz islemi seciniz: ");
	scanf("%d",&iMenuSecim);
	Secim(iMenuDeger,iMenuSecim);
}

void ElementBilgisiGoster(int iMenuDeger)
{
	char bilgi[100];
	int sayac = 0;
	int atomNo;
	int i = 0;
	int checkNo;
	system("COLOR 0F");
	system("cls");
	printf("Elementler Sistemi - Element Bilgisi Goster\n\n");
	FILE * fp = fopen(elmAyrintiFile , "r");
	printf("Ayrintisini Gormek Istediginiz Elementin Atom Numarasini Yaziniz : ");
	scanf("%d" , &checkNo);
	printf("\n\n");
	while(!feof(fp)){
		
		fscanf(fp ,"%d\t%s" , &atomNo , bilgi);
		if(checkNo == atomNo){
			while(1){
				if(bilgi[i] == '*'){
					printf(" ");
				}else if(bilgi[i] == '\0'){
					break;
				}else
					printf("%c" , bilgi[i]);
		    i++;
		}		
			break;
		}
		
	}
	fclose(fp);
	getch();
	Secim(iMenuDeger,0);
}

void ElementBilgisiEkle(int iMenuDeger)
{
	char bilgi[100];
	int sayac = 0;
	int atomNo;
	int i = 0;
	char c;
	system("COLOR 0F");
	system("cls");
	printf("Elementler Sistemi - Element Bilgisi Ekle\n\n");
	FILE * fs = fopen(elmAyrintiFile , "a");
	
	printf("Atom No : ");
	scanf("%d" , &atomNo);

	printf("Bilgi : " );
	getchar();
	
	while(c != '\n'){
		c = getchar();
		bilgi[i] = c;
		i++;
	}
	
	bilgi[i] = '\0';
	
	i=0;
	while(1){
		if(bilgi[i] == ' '){
			bilgi[i] = '*';
		}else if(bilgi[i] == '\0'){
			break;
		}
		i++;
	}
		
	
	fprintf(fs ,"%d\t%s\n" , atomNo , bilgi);
	
	fclose(fs);
	printf("Islem tamamlandi.");
	Sleep(1500);
	getch();
	Secim(iMenuDeger,0);
}

void ElementBilgisiSil(int iMenuDeger)
{
	int gatomNo, atomNo, yatomNo;
	char bilgi[100];
	char ybilgi[100];
	char c;
	int i = 0;
	int elementKontrol = 0;
	system("COLOR 0F");
	system("cls");
	printf("Elementler Sistemi - Element Bilgisi Sil\n\n");
	printf("Atom no giriniz: ");
	scanf("%d",&gatomNo);
	FILE * fs = fopen(elmAyrintiFile , "r");
	FILE * fw = fopen("new.txt" , "w");
	while (!feof(fs)){
		fscanf(fs , "%d\t%s\n" , &atomNo , bilgi);
		if(gatomNo==atomNo){
			elementKontrol=1;
		}
		else
		fprintf(fw , "%d\t%s\n" , atomNo , bilgi);
	}
	if(elementKontrol==0){
		printf("Element bulunamadi.");
	}
	fclose(fs);
	fclose(fw);
	remove(elmAyrintiFile);
	rename("new.txt",elmAyrintiFile);
	printf("Islem tamamlandi.");
	Sleep(1500);
	Secim(iMenuDeger,0);
}

void ElementBilgisiGuncelle(int iMenuDeger)
{
	int gatomNo, atomNo, yatomNo;
	char bilgi[100];
	char ybilgi[100];
	char c;
	int i = 0;
	int elementKontrol = 0;
	system("COLOR 0F");
	system("cls");
	printf("Elementler Sistemi - Element Bilgisi Guncelle\n\n");
	printf("Atom no giriniz: ");
	scanf("%d",&gatomNo);
	FILE * fs = fopen(elmAyrintiFile , "r");
	FILE * fw = fopen("new.txt" , "w");
	while (!feof(fs)){
		fscanf(fs , "%d\t%s\n" , &atomNo , bilgi);
		if(gatomNo==atomNo){
			elementKontrol=1;
			printf("Yeni Atom No: ");
			scanf("%d", &yatomNo);
			printf("Yeni Bilgi : " );
			getchar();
	
			while(c != '\n'){
				c = getchar();
				ybilgi[i] = c;
				i++;
			}
			
			ybilgi[i] = '\0';
			
			i=0;
			while(1){
				if(ybilgi[i] == ' '){
					ybilgi[i] = '*';
				}else if(ybilgi[i] == '\0'){
					break;
				}
				i++;
			}
			fprintf(fw , "%d\t%s" , yatomNo , ybilgi);
		}
		else
		fprintf(fw , "%d\t%s\n" , atomNo , bilgi);
	}
	if(elementKontrol==0){
		printf("Element bulunamadi.");
	}
	fclose(fs);
	fclose(fw);
	remove(elmAyrintiFile);
	rename("new.txt",elmAyrintiFile);
	printf("Islem tamamlandi.");
	Sleep(1500);
	Secim(iMenuDeger,0);
}

void RaporlarMenu(int iMenuDeger)
{
	int iMenuSecim;
	system("COLOR 0F");
	system("cls");
	printf("Elementler Sistemi - Raporlar Menusu\n\n");
	printf("1) Periyodik Tabloyu Goster\n");
	printf("2) Ust menuye don.\n\n");
	printf("Lutfen yapmak istediginiz islemi seciniz: ");
	scanf("%d",&iMenuSecim);
	Secim(iMenuDeger,iMenuSecim);
}

void PeriyodikTabloyuGoster(int iMenuDeger)
{
	system("COLOR 0F");
	system("cls");
	printf("Elementler Sistemi - Periyodik Tablo\n\n");
	char grupNo[18][3]={"A1","A2","B3","B4","B5","B6","B7","B8","B8","B8","B1","B2","A3","A4","A5","A6","A7","A8"};
	
	char luCorner = 218;
	char ldCorner = 192;
	char ruCorner = 191;
	char rdCorner = 217;
	char col = 179;
	char line = 196;
	
	int iGroupCount = 18;
	int iPeriodCount = 10;
	int tempNum;
	int g,p,num; //g = Group - p = Period - num = Atom no.
	
	char tableFileName[100] = "element.txt";
	char tempName[2];
	
	for(int i=0;i<iPeriodCount;i++){

		for(int j=0;j<iGroupCount;j++){

			ptgelm.elmNumber[j][i] = 0;

		}

	}
	
	for(int i=0;i<iPeriodCount;i++){

		for(int j=0;j<iGroupCount;j++){

			strcpy(ptgelm.elmName[j][i] , "*");

		}

	}
	
	FILE *fs = fopen(tableFileName, "r");
	
	while(!feof(fs)){

		fscanf(fs ,"%d\t%d\t%d\t%s\n" , &g , &p , &tempNum , tempName);

		if( strcmp(ptgelm.elmName[g][p], "*")==0){

			ptgelm.elmNumber[g][p] = tempNum;
		 	strcpy(ptgelm.elmName[g][p], tempName);

		}

	}
	
	fclose(fs);
	
	for(int i = 0;i < iGroupCount; i++)
	{
		printf("  %-3s", grupNo[i]);
	}
	
	printf("\n");
	
	for(int i = 0 ;i < iPeriodCount; i++){

		for(int r = 0; r < iGroupCount;r++){

			if(ptgelm.elmNumber[r][i] !=0)
				printf("%c%c%c%c%c", luCorner , line , line , line , ruCorner);
			else	
				printf("     ");
		
		}
		
		printf("\n");
		
		for(int j = 0 ;j < iGroupCount; j++){

			if(ptgelm.elmNumber[j][i] !=0)
				printf("%c%-3s%c" ,col, ptgelm.elmName[j][i] , col);
			else
				printf("     ");

		}
		
		printf("\n");
			
		for(int j = 0 ;j < iGroupCount; j++){

			if(ptgelm.elmNumber[j][i] !=0)
				printf("%c%-3d%c" ,col, ptgelm.elmNumber[j][i] , col);	
			else
				printf("     ");	

		}

		printf("\n");
		
		for(int r = 0; r < iGroupCount;r++){

			if(ptgelm.elmNumber[r][i] !=0)
				printf("%c%c%c%c%c", ldCorner , line , line , line , rdCorner);	
			else	
				printf("     ");

		}

		printf("\n");
			
	}
	getch();
	Secim(iMenuDeger,0);
}

void AyarlarMenu(int iMenuDeger)
{
	int iMenuSecim;
	system("COLOR 0F");
	system("cls");
	printf("Elementler Sistemi - Ayarlar Menusu\n\n");
	printf("1) Yedekle\n");
	printf("2) Geri Yukle\n");
	printf("3) Ust menuye don.\n\n");
	printf("Lutfen yapmak istediginiz islemi seciniz: ");
	scanf("%d",&iMenuSecim);
	Secim(iMenuDeger,iMenuSecim);
}

char destBkpRes[100] = "C:\\BACKUP";

void Yedekle(int iMenuDeger)
{
	system("COLOR 0F");
	system("cls");
	printf("Elementler Sistemi - Yedekle\n\n");
	int a=funcBackup();
	printf("\n\n");
	//printf("Yedekleme tamamlandi.");
	Sleep(1500);
	Secim(iMenuDeger,0);
}

void GeriYukle(int iMenuDeger)
{
	system("COLOR 0F");
	system("cls");
	printf("Elementler Sistemi - Geri Yukle\n\n");
	int a=funcRestore();
	printf("\n\n");
	//printf("Geri yukleme tamamlandi.");
	Sleep(1500);
	Secim(iMenuDeger,0);
}

/*void YoluDegistir(int iMenuDeger)
{
	system("COLOR 0F");
	system("cls");
	printf("Elementler Sistemi - Yolu Degistir\n\n");
	char destination[100];
	printf("Yolu giriniz: ");
	scanf("%s",destination);
	strcat(elementFile, destination);
	printf("%s",elementFile);
	strcat(destination, elmAyrintiFile);
	getch();
	Secim(iMenuDeger,0);
}*/

void Cikis(int iMenuDeger)
{
	char islemSecim;
	system("COLOR 0F");
	printf("\n\nCikmak istediginize emin misiniz?(E/H)");
	islemSecim=getche();
	if(islemSecim=='e' || islemSecim=='E')
	exit(0);
	else if(islemSecim=='h' || islemSecim=='H')
	Secim(10,0);
}

void Secim(int iMenuDeger,int iMenuSecim)
{
	if(iMenuSecim==0 && iMenuSecim>9)
	{
		system("COLOR 0C");
		printf("\a\nHatali giris yaptiniz.");
		Sleep(1000);
		iMenuSecim=0;
	}
	secimLoop:
	switch(iMenuDeger+iMenuSecim)
	{
	case 10:
		AnaMenu(10);
	case 11:
		ElementlerMenu(20);
	case 20:
		ElementlerMenu(20);
	case 21:
		ElementEkle(20);
	case 22:
		ElementSil(20);
	case 23:
		ElementGuncelle(20);
	case 24:
		ElementAyrintisiniGosterMenusu(60);
	case 25:
		AnaMenu(10);
	case 60:
		ElementAyrintisiniGosterMenusu(60);
	case 61:
		ElementBilgisiGoster(60);
	case 62:
		ElementBilgisiEkle(60);
	case 63:
		ElementBilgisiSil(60);
	case 64:
		ElementBilgisiGuncelle(60);
	case 65:
		ElementlerMenu(20);
	case 12:
		RaporlarMenu(30);
	case 30:
		RaporlarMenu(30);
	case 31:
		PeriyodikTabloyuGoster(30);
	case 32:
		AnaMenu(10);
	case 13:
		AyarlarMenu(40);
	case 40:
		AyarlarMenu(40);
	case 41:
		Yedekle(40);
	case 42:
		GeriYukle(40);
	case 43:
		AnaMenu(10);
	case 14:
		Cikis(50);
	default:
		system("COLOR 0C");
		printf("\a\nHatali giris yaptiniz.");
		Sleep(1000);
		iMenuSecim=0;
		goto secimLoop;
	}
}

int funcBackup()
{
	char name[2];
	int g,p,num;
	int atomNo;
	char bilgi[100];
	printf("\n");
	printf("Yedekleme basladi.\n\n");
	
	srand(time(0));
    int x = 0;

    for(int i = 0; i<100; i++){
        int r = rand() % 1000;
        x++;
        system("cls");
        std::cout << "\r" << "Tamamlanan %" << x;
		std::cout << "\n" << std::string(x, '|');
		std::cout.flush();
        if(i < 43){
           Sleep(r/6);
        }else if(i > 43 && i < 74){
           Sleep(r/8);
        }else if(i < 98){
           Sleep(r/5);
        }else if(i > 97 && i != 99){
           Sleep(2000);
        }
    }
	
	FILE * f1 = fopen(elementFile , "r"); 
	FILE * f2 = fopen("element.txt.bak", "w");
	FILE * f3 = fopen(elmAyrintiFile , "r");
	FILE * f4 = fopen("elm_ayrinti.txt.bak", "w");
	while (!feof(f1))
	{
		fscanf(f1 , "%d\t%d\t%d\t%s\n" , &g , &p , &num , name);
		fprintf(f2 , "%d\t%d\t%d\t%s\n" , g , p , num , name);
	}
	while (!feof(f3))
	{
		fscanf(f3 , "%d\t%s\n" , &atomNo , bilgi);
		fprintf(f4 , "%d\t%s\n" , atomNo , bilgi);
	}
	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);
	cout << endl << endl << "Yedekleme tamamlandi.\n" << flush;
	Sleep(3000);
	return 1;
}

int funcRestore()
{
	char name[2];
	int g,p,num;
	int atomNo;
	char bilgi[100];
	printf("\n");
	printf("Geri yukleme basladi.");
	
	srand(time(0));
    int x = 0;

    for(int i = 0; i<100; i++){
        int r = rand() % 1000;
        x++;
        system("cls");
        std::cout << "\r" << "Tamamlanan %" << x;
		std::cout << "\n" << std::string(x, '|');
		std::cout.flush();
        if(i < 43){
           Sleep(r/6);
        }else if(i > 43 && i < 74){
           Sleep(r/8);
        }else if(i < 98){
           Sleep(r/5);
        }else if(i > 97 && i != 99){
           Sleep(2000);
        }
    }
    
	FILE * f1 = fopen("element.txt.bak", "r"); 
	FILE * f2 = fopen(elementFile , "w");
	FILE * f3 = fopen("elm_ayrinti.txt.bak", "r");
	FILE * f4 = fopen(elmAyrintiFile , "w");
	while (!feof(f1))
	{
		fscanf(f1 , "%d\t%d\t%d\t%s\n" , &g , &p , &num , name);
		fprintf(f2 , "%d\t%d\t%d\t%s\n" , g , p , num , name);
	}
	while (!feof(f3))
	{
		fscanf(f3 , "%d\t%s\n" , &atomNo , bilgi);
		fprintf(f4 , "%d\t%s\n" , atomNo , bilgi);
	}
	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);
	cout << endl << endl << "Geri yukleme tamamlandi.\n" << flush;
	Sleep(3000);
	return 1;
}
