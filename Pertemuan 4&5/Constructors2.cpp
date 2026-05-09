#include<iostream>
#include<string>
using namespace std;

class Laptop {
	private:
		string pemilik;
		string merk;
		
	public:
		Laptop(string var1, string var2) {
			pemilik = var1;
			merk = var2;
			
			cout << "Paket Laptop " << merk << " milik " << pemilik << " sudah terkirim" << endl;
		}
};

int main() {
	Laptop laptopFadlan("Fadlan", "Asus");
	Laptop laptopRisma("Risma", "Acer");
	Laptop laptopSophie("Sophie", "Lenovo");
	
	return 0;
}
