#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int j = 0;

struct DataMhs
{
    string nama;
    long long int npm;
} DataMahasiswa[100];

void createdData(string nama, long long int npm)
{
    DataMahasiswa[j].nama = nama;
    DataMahasiswa[j].npm = npm;
    j++;
}

void tampilData()
{
    int i = 0;
    while (i < j)
    {
        cout << i + 1 << ". "
             << "Nama: " << DataMahasiswa[i].nama << endl;
        cout << "NPM: " << DataMahasiswa[i].npm << endl;
        cout << endl;
        i++;
    }
}

void tukarData(struct DataMhs *a, struct DataMhs *b)
{
    struct DataMhs temp = *a;
    *a = *b;
    *b = temp;
}

// ascending NPM
void InsertionSort()
{
    for (int i = 0; i < j; i++)
    {
        for (int k = i; k > 0 && DataMahasiswa[k].npm < DataMahasiswa[k - 1].npm; k--)
        {
            tukarData(&DataMahasiswa[k], &DataMahasiswa[k - 1]);
        }
    }
}

void binarySearch()
{
    long long int npmDicari;
    int awal = 0, akhir = j - 1, ketemu = 0, tengah;
    cout << "Masukkan NPM yang akan dicari: ";
    cin >> npmDicari;

    InsertionSort();
    while (awal <= akhir && ketemu == 0)
    {
        tengah = (awal + akhir) / 2;

        if (DataMahasiswa[tengah].npm == npmDicari)
        {
            ketemu = 1;
            break;
        }
        else if (DataMahasiswa[tengah].npm < npmDicari)
        {
            awal = tengah + 1;
        }
        else
        {
            akhir = tengah - 1;
        }
    }

    if (ketemu == 1)
    {
        cout << "Data Ditemukan" << endl;
        cout << tengah + 1 << ". Nama: " << DataMahasiswa[tengah].nama << endl;
        cout << "Npm: " << DataMahasiswa[tengah].npm << endl;
    }else{
        cout << "Maaf data tidak ada" << endl;
    }
}

int main(int argc, char const *argv[])
{
    cout << "Create data:" << endl;
    createdData("Triyono rifan", 20081010003);
    createdData("Riyo", 20081010012);
    createdData("Alfian", 20081010001);
    createdData("Ali", 20081010031);
    createdData("Fani", 20081010011);
    createdData("Calista", 20081010051);
    createdData("Rahayu", 20081010061);
    createdData("Madya", 20081010069);
    createdData("Fian", 20081010090);
    createdData("Hamdan", 20081010038);
    createdData("Mifta", 20081010029);
    createdData("Ani", 20081010045);
    tampilData();
    cout << endl
         << endl;
    cout << "Sort By Npm" << endl;
    InsertionSort();
    tampilData();
    cout << endl
         << endl;
    binarySearch();
    return 0;
}
