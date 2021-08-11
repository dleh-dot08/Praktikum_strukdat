#include<iostream>
#include<string.h>

int main(){
	char huruf[100];
	int jumlah=0, jumlahstring, jHuruf;
	printf("MASUKAN NAMA : ");gets(huruf);
	printf("========== PROGRAM MENUKAR DAN MEMBALIK NAMA ==========\n\n");
	printf("NAMA YANG SUDAH DI TUKAR\t:");
	int a = strlen(huruf);
	for(int i=a-1;i>=-1;i--){ //cek dari huruf paling belakang kalimat
        if(huruf[i]==' ' || i<0){
            int j = i;
            while(j+1<=a){ //cetak dari huruf terdepan kata
                printf("%c", huruf[j+1]);
                j++;
            }
        jHuruf++;
        a = a-(a-i); //mengurangi kalimat dengan jumlah kata yang sudah di cetak
        } 
	}
	printf("\nNAMA YANG SUDAH DI BALIK\t:%s\n", strrev(huruf));
    jumlah=strlen(huruf);
    printf("\nJUMLAH KATA \t\t\t: %d", jHuruf);
    printf("\nJUMLAH HURUF\t\t\t:%d \n",jumlah);
    printf("========================================\n");

}
