#include<iostream>
using namespace std;

// Definisi class contoh
class contoh {
	private:
		int nilai; // Atribut private untuk menyimpan data angka
	
	public:
		// CONSTRUCTOR: Fungsi yang otomatis dipanggil saat objek dibuat
		contoh(int n) {
			nilai = n; // Inisialisasi atribut 'nilai' dengan parameter 'n'
		}
		
		// Method untuk mengambil atau mengembalikan nilai dari atribut 'nilai'
		int getNum() {
			return nilai;
		}
};

int main() {
	// Membuat objek 'obj' dari class 'contoh' dengan memberikan argumen 10
	contoh obj(10);
	
	// Menampilkan nilai yang disimpan di dalam objek ke layar
	cout << "Nilai yang diinput: " << obj.getNum() << endl;
	
	return 0;
}
