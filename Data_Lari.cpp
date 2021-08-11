#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>

struct pelari{
	char nama[50];
	int no;
	int usia;
	int jam, menit, dtk;
	int jumlah;
};

int main(){
	int i,j,k,l,x, total=0;
	float rata;
	printf("----------DATA PELARI-----------\n");
	printf("JUMLAH DATA YANG INGIN DIMASUKAN : ");scanf("%d", &x);
	printf("\n");
	struct pelari psrt[x], swap;
	
	for(i=0; i<x; i++){
		// 5; i=0; i<5;i++ >> i=1+1+1+....n
		printf("No.Urut \t:");
        scanf("%d", &psrt[i].no);
        printf("Nama \t\t:");
        scanf("%s", &psrt[i].nama);
        printf("Usia \t\t:");
        scanf("%d", &psrt[i].usia);
        printf("Jam \t\t:");
        scanf("%d", &psrt[i].jam);
        printf("Menit \t\t:");
        scanf("%d", &psrt[i].menit);
        printf("Detik \t\t:");
        scanf("%d", &psrt[i].dtk);
        printf("\n");
        psrt[i].jumlah=(psrt[i].jam*3600)+(psrt[i].menit*60)+(psrt[i].dtk*1);
        
	}for (j=0; j<x-1; j++){
		for (k=0; k<x-1; k++){
			 if (psrt[k].jumlah > psrt[k+1].jumlah){
				swap=psrt[k];
                psrt[k]=psrt[k+1];
                psrt[k+1]=swap;
			} 
		}
	}
	printf("----------HASIL BEDASARKAN WAKTU TERCEPAT----------\n");
    printf("\n");
    for (i=0; i<x; i++){
        printf("No \t: %d\n", psrt[i].no);
        printf("Nama \t: %s\n", psrt[i].nama);
        printf("Usia \t: %d\n",psrt[i].usia);
        printf("Jam \t: %d\n", psrt[i].jam);
        printf("Menit \t: %d\n", psrt[i].menit);
        printf("Detik \t: %d\n", psrt[i].dtk);
        printf("Jumlah \t: %d\n", psrt[i].jumlah);
        printf("===================================\n");
    }
    for (i=0; i<x; i++){
    	printf("Jumlah No.%d \t: %d \n",psrt[i].no, psrt[i].jumlah);
    	total+=psrt[i].jumlah;
	}
	printf("===================================\n");
	printf("TOTAL KESELURUHAN ADALAH %d \n",total);
	printf("===================================\n");
	rata=total/x;
	printf("RATA - RATA WAKTU PELARI ADALAH %.2f\n",rata);
}
