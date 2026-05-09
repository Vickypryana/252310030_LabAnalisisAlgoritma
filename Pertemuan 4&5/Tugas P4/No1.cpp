#include<iostream>
#include<string>
using namespace std;

class Mahasiswa {
	private:
		string nama;
		string nim;
		
	public:
		void setNama(string n) {
			nama = n;
		}
		
		void setNim(string i) {
			nim = i;
		}
		
		string getNama() {
			return nama;
		}
		
		string getNim() {
			return nim;
		}
};

int main() {
	Mahasiswa mhs;
	string inputNama, inputNim;
	
	cout << "Input Data Mahasiswa" << endl;
	cout << "Masukkan Nama: ";
	getline(cin, inputNama);
	cout << "Masukkan NIM: ";
	cin >> inputNim;
	
	mhs.setNama(inputNama);
	mhs.setNim(inputNim);
	
	cout << "\n\nOutput Data Mahasiswa" << endl;
	cout << "Nama: " << mhs.getNama() << endl;
	cout << "NIM: " << mhs.getNim() << endl;
	
	return 0;
}
