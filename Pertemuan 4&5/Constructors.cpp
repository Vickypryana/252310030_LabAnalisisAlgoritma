#include<iostream>
#include<string>
using namespace std;

class Pelajaran {
	public:
		Pelajaran() {
			cout << "Ini adalah materi C++ tentang Constructors!" << endl;
		}
};

int main() {
	Pelajaran obj;
	
	return 0;
}
