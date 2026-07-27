#include <iostream>
using namespace std;

int storage[200];
int hdt_boundary;
int i;

void tambah_linear_probing(int n)
{
    bool inserted = false;
    int hash;
    i = 0;

    while (!(inserted) && (i < hdt_boundary))
    {
        hash = (n % hdt_boundary) + i;

        if (storage[hash] == 0)
        {
            storage[hash] = n;
            inserted = true;
        }
        else
        {
            ++i;
            cout << "Terjadi tabrak di " << hash << endl;
        }
    }
}

int main()
{
    int jumlah, data;

    cout << "Masukkan ukuran tabel: ";
    cin >> hdt_boundary;

    for (int j = 0; j < 200; j++)
        storage[j] = 0;

    cout << "Masukkan jumlah data: ";
    cin >> jumlah;

    for (int j = 0; j < jumlah; j++)
    {
        cout << "Masukkan data: ";
        cin >> data;
        tambah_linear_probing(data);
    }

    cout << "Isi tabel:" << endl;
    for (int j = 0; j < hdt_boundary; j++)
        cout << "[" << j << "]: " << storage[j] << endl;

    return 0;
}
