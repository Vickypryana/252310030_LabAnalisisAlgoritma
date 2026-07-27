#include <iostream>
using namespace std;

struct Item {
    string nama;
    int key;
    bool occupied;
    bool deleted;
};

Item* table;
int tableSize;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int nextPrime(int n) {
    while (!isPrime(n)) n++;
    return n;
}

int hashFunc(int key) {
    return key % tableSize;
}

void init(int n) {
    tableSize = nextPrime(n);
    table = new Item[tableSize];
    for (int i = 0; i < tableSize; i++) {
        table[i].occupied = false;
        table[i].deleted = false;
    }
    cout << "Jumlah data telah diatur ulang menjadi " << tableSize << " dengan prima atas." << endl;
}

void insertItem() {
    string nama;
    int key;
    cout << "Masukkan item yang ingin disimpan: ";
    cin.ignore();
    getline(cin, nama);
    cout << "Masukkan key (berupa angka) untuk hash: ";
    cin >> key;
    
    int idx = hashFunc(key);
    int i = 0;
    while (i < tableSize) {
        int pos = (idx + i) % tableSize;
        if (!table[pos].occupied || table[pos].deleted) {
            table[pos].nama = nama;
            table[pos].key = key;
            table[pos].occupied = true;
            table[pos].deleted = false;
            cout << "Data di insert dengan i: " << i << endl;
            cout << "Item berhasil disimpan." << endl;
            return;
        }
        i++;
    }
    cout << "Tabel penuh!" << endl;
}

void hapusItem() {
    int key, i;
    cout << "Masukkan key (berupa angka) untuk hash hapus item: ";
    cin >> key;
    cout << "Masukkan iterator (i) untuk hapus item: ";
    cin >> i;
    
    int pos = (hashFunc(key) + i) % tableSize;
    if (table[pos].occupied && !table[pos].deleted && table[pos].key == key) {
        table[pos].deleted = true;
        cout << "Item berhasil dihapus." << endl;
    } else {
        cout << "Item tidak ditemukan." << endl;
    }
}

void lihatItem() {
    int key, i;
    cout << "Masukkan key (berupa angka) untuk hash melihat item: ";
    cin >> key;
    cout << "Masukkan iterator (i) untuk melihat item: ";
    cin >> i;
    
    int pos = (hashFunc(key) + i) % tableSize;
    if (table[pos].occupied && !table[pos].deleted && table[pos].key == key) {
        cout << "Item dengan key = " << key << " dan i = " << i << " : " << table[pos].nama << endl;
    } else {
        cout << "Item tidak ditemukan." << endl;
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah data : ";
    cin >> n;
    init(n);
    
    int pilihan;
    do {
        cout << "- Inventori Manajemen Sederhana -" << endl;
        cout << "(1) Insert Item" << endl;
        cout << "(2) Hapus Item" << endl;
        cout << "(3) Lihat Item" << endl;
        cout << "(0) Keluar" << endl;
        cin >> pilihan;
        
        if (pilihan == 1) insertItem();
        else if (pilihan == 2) hapusItem();
        else if (pilihan == 3) lihatItem();
    } while (pilihan != 0);
    
    delete[] table;
    return 0;
}
