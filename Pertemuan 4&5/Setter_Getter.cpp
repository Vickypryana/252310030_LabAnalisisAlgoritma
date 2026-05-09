#include<iostream>
#include<string>
using namespace std;

class Hewan {
	private:
		string nama;
		string species;
		
	public:
		void setNama(string n) {
			nama = n;
		}
		
		void setSpecies(string s) {
			species = s;
		}
		
		string getNama() {
			return nama;
		}
		
		string getSpecies() {
			return species;
		}
};

int main() {
	Hewan hewan;
	
	hewan.setNama("Kucing");
	hewan.setSpecies("Felis catus");
	
	cout << "Nama: " << hewan.getNama() << endl;
	cout << "Species: " << hewan.getSpecies() << endl;
	
	return 0;
}

