#include<iostream>
#include<string>
using namespace std;

int main() {
	string buku[100];
	int n;
	
	cout << "Masukkan jumlah buku: ";
	cin >> n;
	cin.ignore();
	
	for(int i=0; i<n; i++) {
		cout << "Judul buku ke-" << i+1 << ": ";
		getline(cin, buku[i]);
	}
	
	cout << "\nBuku yang Didaftar:" << endl;
	for(int i=0; i<n; i++) {
		cout << buku[i] << endl;
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n-i-1; j++) {
			if(buku[j] > buku[j+1]) {
				string temp = buku[j];
				buku[j] = buku[j + 1];
				buku[j + 1] = temp;
			}
		}
	}
	
	cout << "\nSusun Alphabetical:" << endl;
	for(int i=0; i<n; i++) {
		cout << buku[i] << endl;
	}
	
	return 0;
}
