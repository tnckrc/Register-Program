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
					printf("\nHatalý Giriþ Yaptýnýz, Lütfen Tekrar Deneyiniz.\n\n");
					break;
				}
				
			}while(secim!=0);
			
}

void hosgeldiniz(){


	printf("\n==================================================================================\n");
	printf("||             KARACA | SPOR SALONU KAYIT SÝSTEMÝ | HOÞ GELDÝNÝZ                ||\n");
	printf("||==============================================================================||\n");
	printf("||             1- Kayýt Yap                                                     ||\n");
	printf("||             2- Kayýtlarý Görüntüle                                           ||\n");
	printf("||             3- Kayýt Bul                                                     ||\n");
	printf("||             4- Kayýt Güncelle                                                ||\n");
	printf("||             5- Kayýt Sil                                                     ||\n");
	printf("||             0- Çýkýþ                                                         ||\n");
	printf("==================================================================================\n\n");
	printf("Lütfen Devam Etmek Ýçin Yapmak Ýstediðiniz Ýþlem Numarasýný Giriniz : "); 
}

void kayitYap(){
	
	
	
	struct kayit k;
	
	FILE *dosya;
	
	printf("\nLütfen Kayýt Yapacaðýnýz Kiþinin TC Kimlik Numaranýzý Giriniz : ");
	scanf("%s",k.tcNo);
	printf("\nLütfen Ekranda Gözükecek Olan Tek Kelimelik Kullanýcý Adýný Giriniz : ");
	scanf(" %[^\n]",k.isim);
	printf("\nLütfen Boþluk Býrakmayacak Þekilde ve Sadece Rakam Olarak Kayýt Baþlangýç Tarihini Giriniz : ");
	scanf(" %[^\n]",k.tarih);
	printf("\nLütfen Boþluk Býrakmayacak Þekilde ve Sadece Rakam Olarak Kayýt Bitiþ Tarihini Giriniz : ");
	scanf(" %[^\n]",k.sonTarih);
	printf("\nLütfen Kayýt Ücretini Giriniz : ");
	scanf("%s",k.fiyat);
	
	
	
	dosya=fopen("Kayit.txt","a");
	
	if(dosya==NULL){
		printf("Dosya Bulunamadý");
	}
	else{
		fprintf(dosya,"%s\t\t %s\t\t\t\t\t %s\t\t\t\t\t %s\t\t\t\t\t %s\n",k.tcNo,k.isim,k.tarih,k.sonTarih,k.fiyat);
		printf("\nKayýt Baþarýlý.\n");
		
	}
		printf("\n");
	
	fclose(dosya);
	
}

void kayitBul(){
	
	struct kayit k;
	FILE *dosya;
	char secim[1000];
	
	
	dosya=fopen("Kayit.txt","r");
	
	printf("\nLütfen Bulmak Ýstediðiniz Kiþinin TC Kimlik Numaranýzý Giriniz : ");
	scanf("%s",secim);
	

	
	if(dosya==NULL){
		printf("Dosya Bulunamadý");
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
				printf("TCNO\t\t\t KULLANICI ADI\t\t\t\t KAYIT BAÞLANGIÇ TARIHI\t\t\t\t KAYIT BÝTÝÞ TARÝHÝ\t\t\t\tFIYAT\n");
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
	
	printf("\nKayýt Bilgileri Aþaðýda Gözüktüðü Gibidir\n\n");
	printf("  . .  \t\t\t    . .  \t\t\t\t    . .  \t\t\t\t\t    . . \t\t\t\t\t . .\n");
	printf("  . .  \t\t\t    . .  \t\t\t\t    . .  \t\t\t\t\t    . . \t\t\t\t\t . .\n");
	printf(". . . . \t\t  . . . . \t\t\t\t  . . . .  \t\t\t\t\t  . . . .\t\t\t\t       . . . .\n");
	printf("  . .    \t\t    . .   \t\t\t\t    . .   \t\t\t\t\t    . .  \t\t\t\t\t . .\n\n");
	printf("TCNO\t\t\t KULLANICI ADI\t\t\t\t KAYIT BAÞLANGIÇ TARIHI\t\t\t\t KAYIT BÝTÝÞ TARÝHÝ\t\t\t\tFIYAT\n");

	if(dosya==NULL){
		printf("Dosya Bulunamadý");
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
	
	printf("\nLütfen Güncellemek Ýstediðiniz Kiþinin TC Kimlik Numarasýný Giriniz: ");
	scanf("%s",yeniTc);
	
	while(fscanf(dosya,"%s %s %s %s %s",k.tcNo,k.isim,k.tarih,k.sonTarih,k.fiyat)!=EOF){
		
		if(strcmp(k.tcNo,yeniTc)){
		
			fprintf(yedek,"%s\t\t %s\t\t\t\t\t %s\t\t\t\t\t %s\t\t\t\t\t %s\n",k.tcNo,k.isim,k.tarih,k.sonTarih,k.fiyat);
		}
		else{
			printf("\nLütfen Yeni TC Kimlik Numaranýzý Giriniz : ");
			scanf("%s",yeniTc);
			printf("\nLütfen Ekranda Gözükecek Olan Tek Kelimelik Yeni Kullanýcý Adýný Giriniz : ");
			scanf(" %s",yeniIsim);
			printf("\nLütfen Boþluk Býrakmayacak Þekilde Sadece Rakam Olarak Yeni Kayýt Baþlangýç Tarihini Giriniz : ");
			scanf(" %s",yeniTarih);
			printf("\nLütfen Boþluk Býrakmayacak Þekilde Sadece Rakam Olarak Yeni Kayýt Bitiþ Tarihini Giriniz : ");
			scanf(" %s",yeniSontarih);
			printf("\nLütfen Yeni Kayýt Ücretini Giriniz : ");
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
			printf("Kullanýcý Güncellendi");
			fclose(dosya);
			fclose(yedek);
			remove("Kayit.txt");
			rename("Yedek.txt","Kayit.txt");
	}
		else{
			printf("\n\n");
			printf("Kullanýcý Bulunamadý");
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
	
	printf("\nLütfen Kaydý Silinecek Kullanýcýnýn TC Kimlik Numarasýný Giriniz : ");
	scanf("%s",a);
	printf("\nKullanýcý Kaydý Baþarýyla Silinmiþtir.");
	
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









