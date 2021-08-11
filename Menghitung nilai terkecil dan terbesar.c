#include <stdio.h>
#include <stdlib.h>

int main (){
	int TotalNilai ;
	printf("\n");
	printf("Masukkan berapa banyak nilai yang diinginkan :");
	scanf("%d", & TotalNilai);
	int nilai[TotalNilai];
	
	
	int a ;
	for (a=0; a<TotalNilai; a++){
		printf("Masukkan Nilai ke %d :", a+1 );
		scanf("%d", & nilai[a]);
	}
	
	double JumlahNilai = 0 ;
	for(a=0 ;a!=TotalNilai;a++){
		JumlahNilai = JumlahNilai  + nilai[a];
	}

	double ratarata;
	ratarata = JumlahNilai / TotalNilai ;
	
	
	printf("\n");
	printf("Jumlah Nilai adalah %2.f\n", JumlahNilai);
	printf("Rata Rata nilai dari %d inputan adalah %2.f\n", TotalNilai, ratarata);
	
	// MEMBUAT ARRAY BARU 
	
	int TotalNilaiBaru;
	printf("\nMasukkan berapa banyak nilai baru yang diinginkan :");
	scanf("%d", & TotalNilaiBaru);
	int nilaiBaru[TotalNilai + TotalNilaiBaru];
	
	for (a=0; a < TotalNilaiBaru; a++){
		printf("Masukkan Nilai Baru ke %d :", a+1 );
		scanf("%d", & nilaiBaru[a+TotalNilai]);
	}
	// MENAMBAHKAN ARRAY LAMA KE ARRAY BARU
	
	for (a=0; a<TotalNilai; a++){
		nilaiBaru[a] = nilai[a];
	}
	
	TotalNilaiBaru = TotalNilaiBaru + TotalNilai;
	printf("\n");
	printf("TotalNilai Baru adalah %d\n", TotalNilaiBaru);
	
	//PENJUMLAHAN ARRAY YANG BARU
	
	double JumlahNilaiBaru = 0;
	for(a=0 ;a!=TotalNilaiBaru;a++){
		JumlahNilaiBaru = JumlahNilaiBaru + nilaiBaru[a];

	}
	printf("Jumlah Nilai yang baru adalah %2.f\n", JumlahNilaiBaru);
	//HASIL HITUNG RATA-RATA DARI ARRAY LAMA DAN BARU 
	
	double ratarataBaru;
	ratarataBaru = JumlahNilaiBaru / TotalNilaiBaru;
	printf("Rata - Rata Nilai Baru adalah %2.f\n", ratarataBaru);
	
	
	return 0;
}
