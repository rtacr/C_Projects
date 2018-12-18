/*
	Recep Tayyip Acar
	17.01.01.001
	Bilgisayar Muhendisligi
	Programlama Dersi Final Proje Odevi
	
*/

#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <stdlib.h>
#include <fcntl.h>

void ogrencimenusu();
void derssecimmenusu();
void rapormenusu();

void intro();


FILE *fp;

char ogrisim[15];
char ogrsoyisim[15];
char ogrnum[15];
char ogrdogumyili[15];
char ogrbolum[15];


int ilkgiris = 0;

char  numara[15];
char derskodu[15];

char dersisim[15];
char derskod[15];
char dersnot[15];

int main(void)
{
	if(ilkgiris < 1)
		intro();
	
	anamenu:
	int num1;
	system("CLS");
	printf("Ogrenci Isleri Otomasyonuna Hosgeldiniz.\n\n");
	printf("(1)Ogrenci Menusu\n(2)Ders Secimi\n(3)Raporlar\n(4)Cikis\n\n");
	printf("Lutfen menuden ilgili islemi seciniz : ");
	num1 = getche();
	
	if			 (num1 == '1'){
		ogrencimenusu();
	}else if (num1 == '2'){
		derssecimmenusu();
	}else if(num1 == '3'){
		rapormenusu();
	}else if (num1 == '4'){
		char cikiskontrol;
		system("CLS");
		printf("Ogrenci Isleri Otomasyonu\n\n");
		printf("Programi Kapatmak Istediginizden Emin Misiniz? (E/H) :");
		cikiskontrol = getche();
			
		if(cikiskontrol == 'e' || cikiskontrol == 'E')
		{
			exit(0);
		}else if(cikiskontrol == 'h' || cikiskontrol == 'H'){
			goto anamenu;
		}else{
			system("CLS");
			printf("Ogrenci Isleri Otomasyonu\n\n");
			printf("Hatali Tusa Bastiniz.\nAna Menuye Yonlendiriliyorsunuz.");
			Sleep(1000);
			goto anamenu;				
		}
	}else{
		system("CLS");
		printf("Ogrenci Isleri Otomasyonu\n\n");
		printf("Hatali Tusa Bastiniz.\nLutfen menuden ilgili islemi seciniz.");
		Sleep(1000);
		goto anamenu;
	}
	return 0;
}


void ogrencimenusu()
{
	ilkgiris++;
	ogrencimenu:
	system("CLS");
	
	int num2;
	
	printf("Ogrenci Menusu\n\n(1)Yeni Kayit\n(2)Kayit Guncelleme\n(3)Ogrenci Silme\n(4)Ana Menu\n");
	num2 = getche();
	
		if 			(num2 == '1'){
			system("CLS");
			printf("Yeni Ogrenci Kayit\n\n");
			printf("Ogrenci Ismi: ");
			scanf("%s" , ogrisim);
			
			system("CLS");
			printf("Yeni Ogrenci Kayit\n\n");
			printf("Ogrenci Soyismi: ");
			scanf("%s" , ogrsoyisim);
			
			system("CLS");
			printf("Yeni Ogrenci Kayit\n\n");
			printf("Ogrenci numarasi : ");
			scanf("%s" , ogrnum);
			
			system("CLS");
			printf("Yeni Ogrenci Kayit\n\n");
			printf("Ogrenci Dogum Yili: ");
			scanf("%s" , ogrdogumyili);
			
			system("CLS");
			printf("Yeni Ogrenci Kayit\n\n");
			printf("Ogrenci Bolumu: ");
			scanf("%s" , ogrbolum);
			
			system("CLS");
			printf("Yeni Ogrenci Kayit\n\n");
			printf("Isim\tSoyisim\tNumara\t\tDogumyili\tBolum\n");
			printf("%s\t%s\t%s\t%s\t\t%s", ogrisim , ogrsoyisim , ogrnum , ogrdogumyili , ogrbolum);			
	
			fp = fopen("ogrenciler.txt" , "a");
			fprintf(fp ,"%s\t%s\t%s\t%s\t%s\n", ogrisim , ogrsoyisim , ogrnum , ogrdogumyili , ogrbolum);
			
			fclose(fp);
			
								
			printf("\n\nOgrenci Kaydedildi!");
			printf("\nUst menuye donmek icin herhangi bir tusa basiniz.");
			getch();
			
			goto ogrencimenu;						
						
			}else if	(num2 == '2'){
			
			guncloop:
			
				system("CLS");
				printf("Ogrenci Kayit Guncelleme\n\n");
				printf("Ogrencinin numarasi giriniz : ");
				scanf("%s" ,numara);
				
				
				int ogrvarmi;
				
				FILE *fp = fopen("ogrenciler.txt" , "r");
				ogrvarmi = 0;
				while (!feof(fp)){
				
					fscanf(fp ,"%s\t%s\t%s\t%s\t%s\n", ogrisim , ogrsoyisim , ogrnum , ogrdogumyili, ogrbolum);
					
					if(strcmp(ogrnum , numara)==0){
						system("CLS");
						printf("Ogrenci Kayit Guncelleme\n\n");
						printf("Ogrenci : ");
						printf("%s\t%s\t%s\t%s\t%s\n", ogrisim , ogrsoyisim , ogrnum , ogrdogumyili, ogrbolum);
						ogrvarmi++;
					}
				}
				fclose(fp);
			
				if(ogrvarmi == 0){
					system("CLS");
					printf("Ogrenci Kayit Guncelleme\n\n");
					printf("Ogrenci Bulunamadi !\n\nUst Menuye Donuluyor.");
					Sleep(1000);
					goto ogrencimenu;
				}
				
				Sleep(1500);
							
				fp = fopen ("ogrenciler.txt" ,"r");
				FILE * yfp = fopen("tempogrenciler.txt" , "w");
				
				while (!feof(fp)){
				
					fscanf(fp ,"%s\t%s\t%s\t%s\t%s\n", ogrisim , ogrsoyisim , ogrnum , ogrdogumyili, ogrbolum);
					
					if(strcmp(ogrnum , numara)==0){
						system("CLS");
						printf("Ogrenci Kayit Guncelleme\n\n");	
						printf("Ogrenci Guncel Ismi: ");
						scanf("%s" , ogrisim);
						
						system("CLS");
						printf("Ogrenci Kayit Guncelleme\n\n");
						printf("Ogrenci Guncel Soyismi: ");
						scanf("%s" , ogrsoyisim);
						
						system("CLS");
						printf("Ogrenci Kayit Guncelleme\n\n");
						printf("Ogrenci Guncel numara: ");
						scanf("%s" , ogrnum);
						
						system("CLS");
						printf("Ogrenci Kayit Guncelleme\n\n");
						printf("Ogrenci Guncel Dogum Yili: ");
						scanf("%s" , ogrdogumyili);
						
						system("CLS");
						printf("Ogrenci Kayit Guncelleme\n\n");
						printf("Ogrenci Guncel Bolumu: ");
						scanf("%s" , ogrbolum);											
					
					fprintf(yfp ,"%s\t%s\t%s\t%s\t%s\n", ogrisim , ogrsoyisim , ogrnum , ogrdogumyili, ogrbolum);
					
					}else{
						fprintf(yfp ,"%s\t%s\t%s\t%s\t%s\n", ogrisim , ogrsoyisim , ogrnum , ogrdogumyili, ogrbolum);		
					}
								
				}
				
				system("CLS");
				printf("Ogrenci Kayit Guncelleme\n\n");
				printf("Guncel Kayit : ");
				printf("%s\t%s\t%s\t%s\t%s\n", ogrisim , ogrsoyisim , ogrnum , ogrdogumyili, ogrbolum);
				
				fclose(fp);
				fclose(yfp);
				remove("ogrenciler.txt");
				rename("tempogrenciler.txt","ogrenciler.txt");
				
				
			
				printf("\n\nOgrenci Kaydedildi!");
				printf("\nUst menuye donmek icin herhangi bir tusa basiniz.");
				getch();
				
				goto ogrencimenu;
				
				
			

			}else if (num2 == '3'){
			silloop:
				system("CLS");
				
				printf("Ogrenci Silme Menusu\n\n");
				
				int ogrvarmi;
				printf("Ogrencinin numarasi giriniz : ");
				scanf("%s" ,numara);
				
				
				FILE *fp = fopen("ogrenciler.txt" , "r");
				ogrvarmi = 0;
				
				while (!feof(fp)){
				
					fscanf(fp ,"%s\t%s\t%s\t%s\t%s\n", ogrisim , ogrsoyisim , ogrnum , ogrdogumyili, ogrbolum);
					
					if(strcmp(ogrnum , numara)==0){
						system("CLS");
						printf("Ogrenci Silme Menusu\n\n");
						printf("Ogrenci : ");
						printf("%s\t%s\t%s\t%s\t%s\n", ogrisim , ogrsoyisim , ogrnum , ogrdogumyili, ogrbolum);
						ogrvarmi++;
					}
				}
				
				fclose(fp);
				
				if(ogrvarmi == 0){
					system("CLS");
					printf("Ogrenci Silme Menusu\n\n");
					printf("Ogrenci Bulunamadi !\n\nUst Menuye Donuluyor.");
					Sleep(1000);
					goto ogrencimenu;
				}
				
				char silkontrol;
				
				printf("\nOgrenciyi Silmek Istediginizden Emin Misiniz? (E/H)");
				silkontrol = getche();
				
				if(silkontrol == 'e' || silkontrol == 'E')
				{
						FILE * fp = fopen ("ogrenciler.txt" ,"r");
						FILE * yfp = fopen("tempogrenciler.txt" , "w");
						
						while (!feof(fp)){
						
							fscanf(fp ,"%s\t%s\t%s\t%s\t%s\n", ogrisim , ogrsoyisim , ogrnum , ogrdogumyili, ogrbolum);
							
							if(strcmp(ogrnum , numara)==0){
						
							}else{
								fprintf(yfp ,"%s\t%s\t%s\t%s\t%s\n", ogrisim , ogrsoyisim , ogrnum , ogrdogumyili, ogrbolum);		
							}				
					
					}
					fclose(fp);
					fclose(yfp);
					remove("ogrenciler.txt");
					rename("tempogrenciler.txt","ogrenciler.txt");
					
					system("CLS");
					printf("Ogrenci Silme Menusu\n\n");
					printf("Islem Tamamlandi.\nUst Menuye Donuluyor.");
					Sleep(1000);
					goto ogrencimenu;
				
				}else if(silkontrol == 'h' || silkontrol == 'H'){
					system("CLS");
					printf("Ogrenci Silme Menusu\n\n");
					printf("Islem Iptal Edildi.\nUst Menuye Donuluyor.");
					Sleep(1000);
					goto ogrencimenu;
				}else{
					printf("Ogrenci Silme Menusu\n\n");
					printf("Hatali Tusa Bastiniz.\nUst Menuye Yonlendiriliyorsunuz.");
					Sleep(1000);
					goto ogrencimenu;
					
				}	
					
			}else if 	(num2 == '4'){
			main();	
			}else{
				system("CLS");
				printf("Ogrenci Menusu\n\n");
				printf("Hatali Tusa Bastiniz.\nLutfen menuden ilgili islemi seciniz.");
				Sleep(1000);
				goto ogrencimenu;
			}

		
	}
	
void derssecimmenusu(){
	ilkgiris++;
	
	dersmenu:
	system("CLS");
	
	int num3;
	printf("Dersler Menusu\n\n");
	printf("(1)Ogrenci Ders Secimi Yapma\n(2)Ogrenci Ders Secimi Silme\n(3)Ogrenci Ders Notu Girisi\n(4)Ogrenci Ders Notu Goruntuleme\n(5)Ust Menuye Don\n");
	num3 = getche();
	
	if		 (num3 == '1'){
		system("CLS");
	
		printf("Ogrenci Ders Secim Menusu\n\n");
		
		int ogrvarmi;
		printf("Ogrencinin numarasi giriniz : ");
		scanf("%s" ,numara);
		system("CLS");		
			
				
		FILE *fp = fopen("ogrenciler.txt" , "r");
		
		ogrvarmi = 0;
				
		while (!feof(fp)){
				
			fscanf(fp ,"%s\t%s\t%s\t%s\t%s\n", ogrisim , ogrsoyisim , ogrnum , ogrdogumyili, ogrbolum);
					
			if(strcmp(ogrnum , numara)==0){
				printf("Ogrenci Ders Secim Menusu\n\n");
				printf("Ogrenci : ");
				printf("%s\t%s\t%s\t%s\t%s\n", ogrisim , ogrsoyisim , ogrnum , ogrdogumyili, ogrbolum);
				Sleep(1500);
				ogrvarmi++;
			}
		}
				
				fclose(fp);
				
				if(ogrvarmi == 0){
					system("CLS");
					printf("Ogrenci Ders Secim Menusu\n\n");
					printf("Ogrenci Bulunamadi !\n\nUst Menuye Donuluyor.");
					Sleep(1000);
					goto dersmenu;
				}
		Sleep(1500);
		
		system("CLS");
		printf("Ogrenci Ders Secimi Yapma\n\n");
		printf("Dersin Adini Giriniz : ");
		scanf("%s" , dersisim);
		
		system("CLS");
		printf("Ogrenci Ders Secimi Yapma\n\n");
		printf("Dersin Kodunu Giriniz : ");
		scanf("%s" , derskod);
		
		FILE *ogders = fopen("ogrenci_dersler.txt" , "a");
		
		fprintf(ogders ,"%s\t%s\t%s\n" , numara, derskod , dersisim);
		fclose(ogders);
	    
	    system("CLS");
	    printf("Ogrenci Ders Secimi Yapma\n\n");	
	    printf("Islem Tamamlandi.\nUst Menuye Donuluyor.");
	    Sleep(1000);
	    goto dersmenu;
		

	}else if (num3=='2'){
		system("CLS");  
		
		printf("Ogrenci Ders Secimi Silme Menusu\n\n");
		
		int ogrvarmi;
		
		char dsk;

		printf("Ogrencinin numarasi giriniz : ");
		scanf("%s" ,numara);
				
		
		printf("\nDers kodunu giriniz : ");
		scanf("%s" , derskodu);
		
		FILE *fp2 = fopen("ogrenci_dersler.txt" , "r");
		FILE *fp3; 
		 
		ogrvarmi = 0;
		int dersvarmi = 0;		
		while (!feof(fp2)){
				
			fscanf(fp2 ,"%s\t%s\t%s\n", ogrnum ,derskod , dersisim);
					
			if(strcmp(ogrnum , numara)==0){
				
				if(strcmp(derskod , derskodu)==0){
				system("CLS");
				printf("Ogrenci Ders Kayit Silme\n\n");
				printf("Ogrenci Ders Kaydi : ");
				printf("%s\t%s\t%s\n", ogrnum , derskod , dersisim );
								
				dersvarmi++;
				}
				
				ogrvarmi++;
			}
		}
				
				fclose(fp2);
				
				if(ogrvarmi == 0 || dersvarmi == 0){
					system("CLS");
					printf("Ogrenci Ders Kayit Silme\n\n");
					printf("Hatali Giris !\n\nUst Menuye Donuluyor.");
					Sleep(1000);
					goto dersmenu;
				}
			
		printf("\nOgrenci Kaydini silmek istediginizden emin misiniz ? (E/H)");
		dsk = getche();
		
		if (dsk == 'E' || dsk == 'e'){
		
			fp2 = fopen("ogrenci_dersler.txt" , "r");
			fp3 = fopen("tempogrenci_dersler.txt" , "w");
			
			while(!feof(fp2)){
			
				fscanf(fp2 ,"%s\t%s\t%s\n", ogrnum ,derskod , dersisim);
				
				
				if(strcmp(ogrnum , numara)==0 && strcmp(derskod , derskodu)==0){
				//0
				}else{
				
				fprintf(fp3 ,"%s\t%s\t%s\n", ogrnum , derskod , dersisim );
				
				}
				
				
			}
			
			fclose(fp3);
			fclose(fp2);	
			
			remove("ogrenci_dersler.txt");
			rename("tempogrenci_dersler.txt", "ogrenci_dersler.txt");
			
			system("CLS");
			printf("Ogrenci Ders Kayit Silme\n\n");
			printf("Islem Tamamlandi.\nUst Menuye Donuluyor.");
			Sleep(1000);
			goto dersmenu;
			
		}
		else  if (dsk == 'H' || dsk == 'h'){
			system("CLS");
			printf("Ogrenci Ders Kayit Silme\n\n");
			printf("Islem Iptal Edildi.\nUst Menuye Donuluyor.");
			Sleep(1000);
			goto dersmenu;
		}
	
	
	}else if(num3=='3'){
	
		system("CLS");  
		
		printf("Ogrenci Ders Notu Girme\n\n");		
	
		printf("Ogrencinin numarasi giriniz : ");
		scanf("%s" ,numara);				
		
		printf("\nDers kodunu giriniz : ");
		scanf("%s" , derskodu);
					
		printf("\nOgrencinin notunu giriniz : ");
		scanf("%s" , dersnot);		
				
		FILE *ogders = fopen("ogrenci_dersler.txt" , "r");
		FILE *odernot;
		
		int ogrvarmi = 0;
		int dersvarmi = 0;		
		
		while (!feof(ogders)){
				
			fscanf(ogders ,"%s\t%s\t%s\n", ogrnum ,derskod , dersisim);
					
			if(strcmp(ogrnum , numara)==0){
				
				if(strcmp(derskod , derskodu)==0){
					system("CLS");
					printf("Ogrenci Ders Notu Girme\n\n");	
					printf("Ogrenci Numara\t Dersin Kodu\t Dersin Notu\n");
					printf("%s\t %s\t\t%s\n", ogrnum , derskod , dersnot );
										
					odernot = fopen("ogrenci_ders_notlari.txt", "a");
									
					fprintf(odernot , "%s\t%s\t%s\n", ogrnum , derskod , dersnot );
												
					dersvarmi++;
				}else{
					//0
				}
				ogrvarmi++;
			}else{
				//0
			}
		}
		
		
		fclose(ogders);
		fclose(odernot);
				
		if(ogrvarmi == 0 || dersvarmi == 0){
			system("CLS");
			printf("Ogrenci Ders Notu Girme\n\n");	
			printf("Hatali Giris !\n\nUst Menuye Donuluyor.");
			Sleep(1000);
			goto dersmenu;
		}
				
		system("CLS");
		printf("Ogrenci Ders Notu Girme\n\n");	
		printf("Islem Tamamlandi.\nUst Menuye Donuluyor.");
		Sleep(1000);
		goto dersmenu;
			
		
	}else if(num3=='4'){
		system("CLS");  
		
		printf("Ogrenci Ders Notu Goruntuleme\n\n");
		
		int ogrvarmi;
		
		printf("Ogrencinin numarasi giriniz : ");
		scanf("%s" ,numara);
				
		
		printf("\nDers kodunu giriniz : ");
		scanf("%s" , derskodu);
			
	
		FILE *ogrdernotu = fopen("ogrenci_ders_notlari.txt" , "r");

		ogrvarmi = 0;
		int dersvarmi = 0;		
		while (!feof(ogrdernotu)){
				
			fscanf(ogrdernotu ,"%s\t%s\t%s\n", ogrnum ,derskod , dersnot);
					
			if(strcmp(ogrnum , numara)==0){
				
				if(strcmp(derskod , derskodu)==0){
				system("CLS");
				printf("Ogrenci Ders Notu Goruntuleme\n\n");	
				
				printf("Ogrenci Numara\tDersin Kodu\tDersin Notu\n");
				printf("%s\t%s\t\t%s\n", ogrnum , derskod , dersnot );
								
				dersvarmi++;
				}ogrvarmi++;
			}
		}
				
				fclose(ogrdernotu);
				
				if(ogrvarmi == 0 || dersvarmi == 0){
					system("CLS");
					printf("Ogrenci Ders Notu Goruntuleme\n\n");	
					printf("Hatali Giris !\n\nUst Menuye Donuluyor.");
					Sleep(1000);
					goto dersmenu;
				}
		printf("\nUst Menuye Donmek Icin Herhangi Bir Tusa Basin.");
		getch();
		goto dersmenu;		
		
	}else if (num3 == '5'){
		main();
	}else{
		system("CLS");
		printf("Dersler Menusu\n\n");
		printf("Hatali Tusa Bastiniz.\nLutfen menuden ilgili islemi seciniz.");
		Sleep(1000);
		goto dersmenu;
	}
}

void rapormenusu(){
	
	ilkgiris++;
	
	rapormenu:
		
	system("CLS");
	char num3;
	
	printf("Rapor Menusu\n\n");
	printf("(1)Ogrenci Transkripti\n(2)Tum Ogrencileri Listele\n(3)Ust Menuye Don\n");
	num3 = getche();
	
	if (num3 == '1'){
		
		system("CLS");
		printf("Ogrenci Transkripti\n\n");
				
		FILE *ogdernotu = fopen("ogrenci_ders_notlari.txt" , "r");
		
		printf("Ogrenci No\tDers Kodu\tDers Notu\n");
		
		while(!feof(ogdernotu)){
			fscanf(ogdernotu , "%s\t%s\t%s\n"  , ogrnum , derskod , dersnot);
				printf("%s\t%s\t\t%s\n"  , ogrnum , derskod , dersnot);
			
			
		}
		
		
		fclose(ogdernotu);
	
		
		printf("\nUst Menuye Donmek Icin Herhangi Bir Tusa Basin.");
		getch();
		goto rapormenu;
		
	}else if(num3 == '2'){
		
		system("CLS");
		printf("Tum Ogrencileri Listeleme\n\n");
		
		printf("Ad\tSoyad\tOgrenciNo\tDogum Yili\tBolum\n");
		
		FILE *fp = fopen("ogrenciler.txt" , "r");
		
		while(!feof(fp)){
			fscanf(fp , "%s\t%s\t%s\t%s\t%s\n"  , ogrisim , ogrsoyisim , ogrnum , ogrdogumyili , ogrbolum);
			printf("%s\t%s\t%s\t%s\t\t%s\n"  , ogrisim , ogrsoyisim , ogrnum , ogrdogumyili , ogrbolum);
		}
		
		fclose(fp);
		
		
		printf("\nUst Menuye Donmek Icin Herhangi Bir Tusa Basin.");
		getch();
		goto rapormenu;
	}else if(num3 == '3'){
		main();
	}else{
		system("CLS");
		printf("Rapor Menusu\n\n");
		printf("Hatali Tusa Bastiniz.\nLutfen menuden ilgili islemi seciniz.");
		Sleep(1000);
		goto rapormenu;
	}		
		
}
	
void intro(){

    system("cls");
	printf("           **            \n");
	Sleep(50);	
	printf("          *  *           \n");
	Sleep(50);
	printf("         *    *          \n");
	Sleep(50);
	printf("  ******       *******    \n");
	printf("  *     ****        *    \n");
	Sleep(50);
	printf("  *      *  **      *    \n");
	Sleep(50);
	printf("  *       *   *     *    \n");
	Sleep(50);
	printf(" *        ****       *   \n");
	Sleep(50);
	printf("*        * *          *  \n");
	Sleep(50);
	printf(" *      *   *    *   *   \n");
	Sleep(50);
	printf("  *    *     *  *   *    \n");
	Sleep(50);
	printf("  *   *       ***   *    \n");
	printf("  *                 *    \n");
	Sleep(50);
	printf("  ******      *******    \n");
	Sleep(50);
	printf("        *    *           \n");	                                                                                 
    printf("         *  *            \n");
	Sleep(50);
	printf("          **             \n");
	Sleep(50);
	
    
    Sleep(1000);
}
