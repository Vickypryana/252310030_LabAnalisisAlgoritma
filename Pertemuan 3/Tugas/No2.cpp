#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct Buku {
	string judul;
	int rak;
};

bool compareBuku(Buku a, Buku b) {
	return a.judul < b.judul;
}

int binarySearch(Buku daftarBuku[], int n, string target) {
	int kiri = 0;
	int kanan = n - 1;
	
	while (kiri <= kanan) {
		int tengah = kiri + (kanan - kiri) / 2;
		
		if (daftarBuku[tengah].judul == target) {
			return daftarBuku[tengah].rak;
		}
		if (daftarBuku[tengah].judul < target) {
			kiri = tengah + 1;
		} else {
			kanan = tengah - 1;
		}
	}
	return -1;
}

int main() {
	Buku perpustakaan[5];
	perpustakaan[0].judul = "Algoritma Pemrograman";
	perpustakaan[0].rak = 5;
	perpustakaan[1].judul = "Basis Data";
	perpustakaan[1].rak = 2;
	perpustakaan[2].judul = "Jaringan Komputer";
	perpustakaan[2].rak = 1;
	perpustakaan[3].judul = "Kecerdasan Buatan";
	perpustakaan[3].rak = 3;
	perpustakaan[4].judul = "Struktur Data";
	perpustakaan[4].rak = 4;
	
	int n = sizeof(perpustakaan) / sizeof(perpustakaan[0]);
	
	sort(perpustakaan, perpustakaan + n, compareBuku);
	
	string judulCari;
	cout << "Masukkan judul buku yang dicari: ";
	getline(cin, judulCari);
	
	int hasilRak = binarySearch(perpustakaan, n, judulCari);
	
	if (hasilRak != -1) {
		cout << "Buku ditemukan di rak nomor: " << hasilRak << endl;
	} else {
		cout << "Buku tidak ditemukan." << endl;
	}
	
	return 0;
}
