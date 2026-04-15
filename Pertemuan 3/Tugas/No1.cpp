#include<iostream>
using namespace std;

int main(){
	int data[] = {1, 3, 5, 12, 18, 24};
	int n = sizeof(data) / sizeof(data[0]);
	int cari, i;
	bool ditemukan = false;
	
	cout << "Masukkan data yang dicari: ";
	cin >> cari;
	
	for (i=0; i<n; i++) {
		if (data[i] == cari) {
			ditemukan = true;
			break;
		}
	}
	
	if (ditemukan) {
		cout << "Bilangan ditemukan!" << endl;
	} else {
		cout << "Bilangan tidak ditemukan!" << endl;
	}
	
	return 0;
}
