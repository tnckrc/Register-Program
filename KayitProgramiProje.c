#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
#include<ctype.h>


void hosgeldiniz();
void kayitYap();
void kayitBul();
void kayitlariGoruntule();
void kayitGuncelle();
void kayitSil();




struct kayit{
	
	char tcNo[50];  
	char isim[100];
	char tarih[50];
	char sonTarih[50];
	char fiyat[50];
}k;

void main(){
	setlocale(LC_ALL, "Turkish");
	int secim;
		
		do{
			hosgeldiniz();
			scanf("%d",&secim);
			
			switch(secim){
				
				case 1:
					kayitYap();
					break;
					
				case 2:
					kayitlariGoruntule();
					break;
				case 3:
					kayitBul();
					break;
					
				case 4:
					kayitGuncelle();
					break;
				
				case 5:
					kayitSil();
					break;
				
				case 0:
					exit(0);
					break;
						
				
				default:
					printf("\nHatal� Giri� Yapt�n�z, L�tfen Tekrar Deneyiniz.\n\n");
					break;
				}
				
			}while(secim!=0);
			
}

void hosgeldiniz(){


	printf("\n==================================================================================\n");
	printf("||             KARACA | SPOR SALONU KAYIT S�STEM� | HO� GELD�N�Z                ||\n");
	printf("||==============================================================================||\n");
	printf("||             1- Kay�t Yap                                                     ||\n");
	printf("||             2- Kay�tlar� G�r�nt�le                                           ||\n");
	printf("||             3- Kay�t Bul                                                     ||\n");
	printf("||             4- Kay�t G�ncelle                                                ||\n");
	printf("||             5- Kay�t Sil                                                     ||\n");
	printf("||             0- ��k��                                                         ||\n");
	printf("==================================================================================\n\n");
	printf("L�tfen Devam Etmek ��in Yapmak �stedi�iniz ��lem Numaras�n� Giriniz : "); 
}

void kayitYap(){
	
	
	
	struct kayit k;
	
	FILE *dosya;
	
	printf("\nL�tfen Kay�t Yapaca��n�z Ki�inin TC Kimlik Numaran�z� Giriniz : ");
	scanf("%s",k.tcNo);
	printf("\nL�tfen Ekranda G�z�kecek Olan Tek Kelimelik Kullan�c� Ad�n� Giriniz : ");
	scanf(" %[^\n]",k.isim);
	printf("\nL�tfen Bo�luk B�rakmayacak �ekilde ve Sadece Rakam Olarak Kay�t Ba�lang�� Tarihini Giriniz : ");
	scanf(" %[^\n]",k.tarih);
	printf("\nL�tfen Bo�luk B�rakmayacak �ekilde ve Sadece Rakam Olarak Kay�t Biti� Tarihini Giriniz : ");
	scanf(" %[^\n]",k.sonTarih);
	printf("\nL�tfen Kay�t �cretini Giriniz : ");
	scanf("%s",k.fiyat);
	
	
	
	dosya=fopen("Kayit.txt","a");
	
	if(dosya==NULL){
		printf("Dosya Bulunamad�");
	}
	else{
		fprintf(dosya,"%s\t\t %s\t\t\t\t\t %s\t\t\t\t\t %s\t\t\t\t\t %s\n",k.tcNo,k.isim,k.tarih,k.sonTarih,k.fiyat);
		printf("\nKay�t Ba�ar�l�.\n");
		
	}
		printf("\n");
	
	fclose(dosya);
	
}

void kayitBul(){
	
	struct kayit k;
	FILE *dosya;
	char secim[1000];
	
	
	dosya=fopen("Kayit.txt","r");
	
	printf("\nL�tfen Bulmak �stedi�iniz Ki�inin TC Kimlik Numaran�z� Giriniz : ");
	scanf("%s",secim);
	

	
	if(dosya==NULL){
		printf("Dosya Bulunamad�");
		exit(1);
	}
	else{
		while(!feof(dosya)){  
			
			fscanf(dosya,"%s %s %s %s %s",k.tcNo,k.isim,k.tarih,k.sonTarih,k.fiyat);
			
			if(strcmp(k.tcNo,secim) == 0){
				system("cls");
				
				printf("  . .  \t\t\t    . .  \t\t\t\t    . .  \t\t\t\t\t    . . \t\t\t\t\t . .\n");
				printf("  . .  \t\t\t    . .  \t\t\t\t    . .  \t\t\t\t\t    . . \t\t\t\t\t . .\n");
				printf(". . . . \t\t  . . . . \t\t\t\t  . . . .  \t\t\t\t\t  . . . .\t\t\t\t       . . . .\n");
				printf("  . .    \t\t    . .   \t\t\t\t    . .   \t\t\t\t\t    . .  \t\t\t\t\t . .\n\n");
				printf("TCNO\t\t\t KULLANICI ADI\t\t\t\t KAYIT BA�LANGI� TARIHI\t\t\t\t KAYIT B�T�� TAR�H�\t\t\t\tFIYAT\n");
				printf("%s\t\t %s\t\t\t\t\t %s\t\t\t\t\t %s\t\t\t\t\t %s\n",k.tcNo,k.isim,k.tarih,k.sonTarih,k.fiyat);
				
				
				break;
				
			}
		}
	}
	fclose(dosya);
}





void kayitlariGoruntule(){
	
	char secim;
	FILE *dosya;
	
	dosya=fopen("Kayit.txt","r");
	system("cls");
	
	printf("\nKay�t Bilgileri A�a��da G�z�kt��� Gibidir\n\n");
	printf("  . .  \t\t\t    . .  \t\t\t\t    . .  \t\t\t\t\t    . . \t\t\t\t\t . .\n");
	printf("  . .  \t\t\t    . .  \t\t\t\t    . .  \t\t\t\t\t    . . \t\t\t\t\t . .\n");
	printf(". . . . \t\t  . . . . \t\t\t\t  . . . .  \t\t\t\t\t  . . . .\t\t\t\t       . . . .\n");
	printf("  . .    \t\t    . .   \t\t\t\t    . .   \t\t\t\t\t    . .  \t\t\t\t\t . .\n\n");
	printf("TCNO\t\t\t KULLANICI ADI\t\t\t\t KAYIT BA�LANGI� TARIHI\t\t\t\t KAYIT B�T�� TAR�H�\t\t\t\tFIYAT\n");

	if(dosya==NULL){
		printf("Dosya Bulunamad�");
		exit(1);
	}
	else{
		while((secim=fgetc(dosya))!=EOF)
		printf("%c",secim);
	}
	
	fclose(dosya);
}

void kayitGuncelle(){
	
	FILE *dosya;
	FILE *yedek;
	
	char yeniTc[50];  
	char yeniIsim[100];
	char yeniTarih[50];
	char yeniSontarih[50];
	char yeniFiyat[50];
	
	dosya=fopen("Kayit.txt","r+");
	yedek=fopen("Yedek.txt","a+");
	
	int durum = 1;
	
	printf("\nL�tfen G�ncellemek �stedi�iniz Ki�inin TC Kimlik Numaras�n� Giriniz: ");
	scanf("%s",yeniTc);
	
	while(fscanf(dosya,"%s %s %s %s %s",k.tcNo,k.isim,k.tarih,k.sonTarih,k.fiyat)!=EOF){
		
		if(strcmp(k.tcNo,yeniTc)){
		
			fprintf(yedek,"%s\t\t %s\t\t\t\t\t %s\t\t\t\t\t %s\t\t\t\t\t %s\n",k.tcNo,k.isim,k.tarih,k.sonTarih,k.fiyat);
		}
		else{
			printf("\nL�tfen Yeni TC Kimlik Numaran�z� Giriniz : ");
			scanf("%s",yeniTc);
			printf("\nL�tfen Ekranda G�z�kecek Olan Tek Kelimelik Yeni Kullan�c� Ad�n� Giriniz : ");
			scanf(" %s",yeniIsim);
			printf("\nL�tfen Bo�luk B�rakmayacak �ekilde Sadece Rakam Olarak Yeni Kay�t Ba�lang�� Tarihini Giriniz : ");
			scanf(" %s",yeniTarih);
			printf("\nL�tfen Bo�luk B�rakmayacak �ekilde Sadece Rakam Olarak Yeni Kay�t Biti� Tarihini Giriniz : ");
			scanf(" %s",yeniSontarih);
			printf("\nL�tfen Yeni Kay�t �cretini Giriniz : ");
			scanf("%s",yeniFiyat);
			
			durum = 0;
			
			strcpy(k.tcNo,yeniTc);
			strcpy(k.isim,yeniIsim);
			strcpy(k.tarih,yeniTarih);
			strcpy(k.sonTarih,yeniSontarih);
			strcpy(k.fiyat,yeniFiyat);
			
			fprintf(yedek,"%s\t\t %s\t\t\t\t\t %s\t\t\t\t\t %s\t\t\t\t\t %s\n",k.tcNo,k.isim,k.tarih,k.sonTarih,k.fiyat);
			
		}
	}
		if(durum==0){
			printf("\n\n");
			printf("Kullan�c� G�ncellendi");
			fclose(dosya);
			fclose(yedek);
			remove("Kayit.txt");
			rename("Yedek.txt","Kayit.txt");
	}
		else{
			printf("\n\n");
			printf("Kullan�c� Bulunamad�");
			fclose(dosya);
			fclose(yedek);
			remove("Kayit.txt");
			rename("Yedek.txt","Kayit.txt");
		}
}

void kayitSil(){
	
	FILE *dosya;
	FILE *yedek;
	
	char a[100];
	
	dosya=fopen("Kayit.txt","r+");
	yedek=fopen("Yedek.txt","w+");
	
	printf("\nL�tfen Kayd� Silinecek Kullan�c�n�n TC Kimlik Numaras�n� Giriniz : ");
	scanf("%s",a);
	printf("\nKullan�c� Kayd� Ba�ar�yla Silinmi�tir.");
	
	while(fscanf(dosya,"%s %s %s %s %s",k.tcNo,k.isim,k.tarih,k.sonTarih,k.fiyat)!=EOF){
		
		if(strcmp(k.tcNo,a)){
			fprintf(yedek,"%s\t\t %s\t\t\t\t\t %s\t\t\t\t\t %s\t\t\t\t\t %s\n",k.tcNo,k.isim,k.tarih,k.sonTarih,k.fiyat);
		}
		
	}
	fclose(dosya);
	fclose(yedek);
	remove("Kayit.txt");
	rename("Yedek.txt","Kayit.txt");
	
}









