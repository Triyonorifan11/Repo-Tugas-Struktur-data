#include <iostream>

using namespace std;

int maks = 5;
string menuMakanan[5];
int top = 0;

bool isFull()
{
    return (top == maks) ? true : false;
}

bool isEmpty()
{
    return (top == 0) ? true : false;
}

void pushData(string dataMenu)
{
    if (isFull())
    {
        cout << "Menu sudah penuh" << endl;
    }
    else
    {
        menuMakanan[top] = dataMenu;
        top++;
    }
}

void popData()
{
    if (isEmpty())
    {
        cout << "Data Kosong" << endl;
    }
    else
    {
        menuMakanan[top - 1] = "";
        top--;
    }
}

void peekData(int position)
{
    if (isEmpty())
    {
        cout << "Data Kosong" << endl;
    }
    else
    {
        int index = top;
        for (int i = 0; i < position; i++)
        {
            index--;
        }
        cout << "Data posisi ke-" << position << " = " << menuMakanan[index] << endl;
    }
}

void changeData(string data, int position)
{
    if (isEmpty())
    {
        cout << "Data Kosong" << endl;
    }
    else
    {
        int index = top;
        for (int i = 0; i < position; i++)
        {
            index--;
        }
        menuMakanan[index] = data;
    }
}

int countData()
{
    return (isEmpty()) ? 0 : top;
}

void destroyData()
{
    for (int i = 0; i < top; i++)
    {
        menuMakanan[i] = "";
    }
    top = 0;
}

void showAllMenu()
{
    if (isEmpty())
    {
        cout << "Menu Kosong" << endl;
    }
    else
    {
        cout << "Daftar Menu : " << endl;
        for (int i = maks - 1; i >= 0; i--)
        {
            if (menuMakanan[i] != "")
            {
                cout << menuMakanan[i] << endl;
            }
        }
    }
}

int main(int argc, char const *argv[])
{

    cout << "======= Push 1 data =======" << endl;
    pushData("Es teh indo");
    showAllMenu();
    cout << "Menu sudah penuh ? " << isFull() << endl;
    cout << "Menu Kosong ? " << isEmpty() << endl;
    cout << "\n"
         << endl;

    cout << "======= Push data penuh =======" << endl;
    pushData("Teh Anget indo");
    pushData("Es apel indo");
    pushData("Es Mangga indo");
    pushData("Es Pepaya indo");
    pushData("Es Manggis indo");
    showAllMenu();
    cout << "Menu sudah penuh ? " << isFull() << endl;
    cout << "Menu Kosong ? " << isEmpty() << endl;
    cout << "\n"
         << endl;

    cout << "======= Hapus 1 data teratas =======" << endl;
    popData();
    showAllMenu();
    cout << "Menu sudah penuh ? " << isFull() << endl;
    cout << "Menu Kosong ? " << isEmpty() << endl;
    cout << "\n"
         << endl;

    cout << "======= Ubah 1 data ke 4 =======" << endl;
    changeData("Es Cocacola", 4);
    showAllMenu();
    cout << "Menu sudah penuh ? " << isFull() << endl;
    cout << "Menu Kosong ? " << isEmpty() << endl;
    cout << "\n"
         << endl;

    cout << "======= Peek Data 4 =======" << endl;
    peekData(4);
    cout << "Banyak data = " << countData() << endl;
    cout << "\n"
         << endl;

    cout << "======= Hapus Semua Data =======" << endl;
    destroyData();
    showAllMenu();
    cout << "Menu sudah penuh ? " << isFull() << endl;
    cout << "Menu Kosong ? " << isEmpty() << endl;
    cout << "Banyak data = " << countData() << endl;
    cout << "\n"
         << endl;

    return 0;
}
