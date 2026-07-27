#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX = 100;

struct Queue {
    string data[MAX];
    int front;
    int rear;
    int count;
};

void initQueue(Queue &q) {
    q.front = 0;
    q.rear = -1;
    q.count = 0;
}

bool isEmpty(Queue q) {
    return q.count == 0;
}

bool isFull(Queue q) {
    return q.count == MAX;
}

int size(Queue q) {
    return q.count;
}

void enqueue(Queue &q, string nama) {
    if (isFull(q)) {
        cout << "Antrean penuh! Tidak dapat menambah pengunjung." << endl;
        return;
    }
    q.rear = (q.rear + 1) % MAX;
    q.data[q.rear] = nama;
    q.count++;
    cout << "Pengunjung \"" << nama << "\" berhasil masuk antrean." << endl;
}

void dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Antrean kosong! Tidak ada pengunjung untuk dilayani." << endl;
        return;
    }
    cout << "Pengunjung \"" << q.data[q.front] << "\" sedang dilayani." << endl;
    q.front = (q.front + 1) % MAX;
    q.count--;
}

void peek(Queue q) {
    if (isEmpty(q)) {
        cout << "Antrean kosong!" << endl;
        return;
    }
    cout << "Pengunjung pertama: \"" << q.data[q.front] << "\"" << endl;
}

void display(Queue q) {
    if (isEmpty(q)) {
        cout << "Antrean kosong." << endl;
        return;
    }
    cout << "\n========== DAFTAR ANTRIAN ==========" << endl;
    cout << left << setw(5) << "No" << setw(30) << "Nama Pengunjung" << endl;
    cout << "------------------------------------" << endl;
    for (int i = 0; i < q.count; i++) {
        int idx = (q.front + i) % MAX;
        cout << left << setw(5) << (i + 1) << setw(30) << q.data[idx] << endl;
    }
    cout << "====================================" << endl;
    cout << "Jumlah antrian: " << size(q) << endl;
}

int main() {
    Queue q;
    initQueue(q);
    int pilihan;
    string nama;

    do {
        cout << "\n======== SISTEM ANTREAN DIGITAL LOKET PELAYANAN PUBLIK ========" << endl;
        cout << "1. Enqueue (Tambah Pengunjung)" << endl;
        cout << "2. Dequeue (Layani Pengunjung)" << endl;
        cout << "3. Peek (Lihat Pengunjung Pertama)" << endl;
        cout << "4. isFull (Cek Antrean Penuh)" << endl;
        cout << "5. isEmpty (Cek Antrean Kosong)" << endl;
        cout << "6. Size (Jumlah Antrean)" << endl;
        cout << "7. Display (Tampilkan Antrean)" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama pengunjung: ";
                getline(cin, nama);
                enqueue(q, nama);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                peek(q);
                break;
            case 4:
                cout << (isFull(q) ? "Antrean PENUH." : "Antrean BELUM penuh.") << endl;
                break;
            case 5:
                cout << (isEmpty(q) ? "Antrean KOSONG." : "Antrean TIDAK kosong.") << endl;
                break;
            case 6:
                cout << "Jumlah pengunjung dalam antrean: " << size(q) << endl;
                break;
            case 7:
                display(q);
                break;
            case 0:
                cout << "Terima kasih telah menggunakan Sistem Antrean Digital." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
