#include<iostream>
using namespace std;

int main(){
	int Nilai[20];
	int Posisi[20];
	int i, n, Bil, jml = 0;
	bool ketemu = false;
	
	cout << "Masukkkan jumlah deret bilangan = ";
	cin >> n;
	cout << endl;
	
	for(i=0; i<n; i++){
		cout << "Nilai bilangan ke-" << i << " = ";
		cin >> Nilai[i];
	}
	
	cout << "\nDeret Bilangan = ";
	for(i=0; i<n; i++){
		cout << Nilai[i] << " ";
	}
	
	cout << "\n\nMasukkan Bilangan yang akan dicari = ";
	cin >> Bil;
	
	for(i=0; i<n; i++){
		if(Nilai[i] == Bil){
			ketemu = true;
			Posisi[jml] = i;
			jml++;
		}
	}
	
	if(ketemu){
		cout << "\nBilangan " << Bil << " ditemukan sebanyak " << jml << " kali";
		cout << "\npada posisi indeks ke = ";
		for(i=0; i<jml; i++){
			cout << Posisi[i] << " ";
		}
	} else {
		cout << "\nMaaf, bilangan " << Bil << " tidak ditemukan";
	}
	
	cout << endl;
	return 0;
}
