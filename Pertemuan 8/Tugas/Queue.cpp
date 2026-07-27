#include <iostream>
using namespace std;

const int MAX = 100;
string queue[MAX];
int front = -1, rear = -1;

bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return rear == MAX - 1;
}

int Size() {
    if (isEmpty()) return 0;
    return rear - front + 1;
}

void Enqueue(string nama) {
    if (isFull()) {
        cout << "Antrean penuh!" << endl;
        return;
    }
    if (isEmpty()) front = 0;
    rear++;
    queue[rear] = nama;
    cout << nama << " masuk ke antrean." << endl;
}

void Dequeue() {
    if (isEmpty()) {
        cout << "Antrean kosong!" << endl;
        return;
    }
    cout << queue[front] << " dilayani." << endl;
    front++;
    if (front > rear) front = rear = -1;
}

void Peek() {
    if (isEmpty()) {
        cout << "Antrean kosong!" << endl;
        return;
    }
    cout << "Pengunjung pertama: " << queue[front] << endl;
}

void Display() {
    if (isEmpty()) {
        cout << "Antrean kosong!" << endl;
        return;
    }
    cout << "Daftar Antrean:" << endl;
    for (int i = front; i <= rear; i++) {
        cout << i - front + 1 << ". " << queue[i] << endl;
    }
}

int main() {
    int pilihan;
    string nama;
    
    do {
        cout << "\n=== Sistem Antrean Digital ===" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. isFull" << endl;
        cout << "5. isEmpty" << endl;
        cout << "6. Size" << endl;
        cout << "7. Display" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore();
        
        if (pilihan == 1) {
            cout << "Masukkan nama: ";
            getline(cin, nama);
            Enqueue(nama);
        } else if (pilihan == 2) {
            Dequeue();
        } else if (pilihan == 3) {
            Peek();
        } else if (pilihan == 4) {
            cout << (isFull() ? "Penuh" : "Tidak penuh") << endl;
        } else if (pilihan == 5) {
            cout << (isEmpty() ? "Kosong" : "Tidak kosong") << endl;
        } else if (pilihan == 6) {
            cout << "Jumlah antrean: " << Size() << endl;
        } else if (pilihan == 7) {
            Display();
        }
    } while (pilihan != 0);
    
    return 0;
}
