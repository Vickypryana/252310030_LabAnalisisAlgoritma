#include<iostream>
#include<string>
using namespace std;

class Elektronik {
	protected:
		string merek;
		string model;
		double harga;
		int dayaWatt;
	
	public:
		Elektronik(string m, string mod, double h, int d) {
			merek = m;
			model = mod;
			harga = h;
			dayaWatt = d;
		}
		
		virtual void tampilkanInfo() {
			cout << "--- Info Elektronik ---" << endl;
			cout << "Merek        : " << merek << endl;
			cout << "Model        : " << model << endl;
			cout << "Harga        : Rp" << harga << endl;
			cout << "Daya Listrik : " << dayaWatt << " Watt" << endl;
		}
		
		void hitungBiayaListrik(int jam) {
			double biaya = (dayaWatt / 1000.0) * jam * 1500;
			cout << "Estimasi biaya listrik (" << jam << " jam): Rp" << biaya << endl;
		}
};

class Televisi : public Elektronik {
	private:
		float ukuranLayar;
		string resolusi;
		string jenisPanel;
		bool isSmartTV;
		
	public:
		Televisi(string m, string mod, double h, int d, float uk, string res, string pan, bool smart) : Elektronik(m, mod, h, d) {
			ukuranLayar = uk;
			resolusi = res;
			jenisPanel = pan;
			isSmartTV = smart;
		}
		
		void tampilkanInfo() override {
			cout << "--- Detail Televisi ---" << endl;
			cout << "Merek      : " << merek << endl;
			cout << "Ukuran     : " << ukuranLayar << endl;
			cout << "Resolusi   : " << resolusi << endl;
			cout << "Tipe Panel : " << jenisPanel << endl;
			cout << "Smart TV   : " << (isSmartTV ? "Ya" : "Tidak") << endl;
			cout << "Harga      : Rp" << harga << endl;
		}
		
		void gantiSaluran(int nomor) {
			cout << "Televisi " << merek << " berpindah ke saluran: " << nomor << endl;
		}
};

int main() {
	Elektronik* perangkat1 = new Elektronik("Generic", "Standard-X", 500000, 50);
	Televisi* tv1 = new Televisi("Samsung", "OLED-V8", 12000000, 100, 55.5, "4K Ultra HD", "OLED", true);
	
	cout << "### OUTPUT OBJEK 1 ###" << endl;
	perangkat1 -> tampilkanInfo();
	perangkat1 -> hitungBiayaListrik(5);
	cout << endl;
	
	cout << "### OUTPUT OBJEK 2 ###" << endl;
	Elektronik* poliTV = tv1;
	poliTV -> tampilkanInfo();
	
	tv1 -> gantiSaluran(7);
	tv1 -> hitungBiayaListrik(10);
	
	delete perangkat1;
	delete tv1;
	
	return 0;
}
