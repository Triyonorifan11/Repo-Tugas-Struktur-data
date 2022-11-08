#include <iostream>

using namespace std;

struct Antrian
{
    string namaPemesan;
    int noMeja;
    Antrian *next;
    Antrian *prev;
};

Antrian *head, *tail, *current, *newNode, *del;

// create frst double linkedlist
void setFirstData(string namaPemesan, int noMeja)
{
    head = new Antrian();
    head->namaPemesan = namaPemesan;
    head->noMeja = noMeja;
    head->next = NULL;
    head->prev = NULL;
    tail = head;
}

void addFirstAntrian(string namaPemesan, int noMeja)
{
    if (head == NULL)
    {
        cout << "Buat Antrian Pertama Terlebih dahulu" << endl;
    }
    else
    {
        newNode = new Antrian();
        newNode->namaPemesan = namaPemesan;
        newNode->noMeja = noMeja;
        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
    }
}

void addLastData(string namaPemesan, int noMeja)
{
    if (head == NULL)
    {
        cout << "Buat Antrian Pertama Terlebih dahulu" << endl;
    }
    else
    {
        newNode = new Antrian();
        newNode->namaPemesan = namaPemesan;
        newNode->noMeja = noMeja;
        newNode->next = NULL;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void updateFirstAntrian(string namaPemesan, int noMeja)
{
    head->namaPemesan = namaPemesan;
    head->noMeja = noMeja;
}

void updateLastAntrian(string namaPemesan, int noMeja)
{
    tail->namaPemesan = namaPemesan;
    tail->noMeja = noMeja;
}

void removeFirstAntrian()
{
    if (head == NULL)
    {
        cout << "Buat Antrian Pertama Terlebih dahulu" << endl;
    }
    else
    {
        del = head;
        head = head->next;
        head->prev = NULL;
        delete del;
    }
}

void removeLastAntrian()
{
    if (head == NULL)
    {
        cout << "Buat Antrian Pertama Terlebih dahulu" << endl;
    }
    else
    {
        del = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete del;
    }
}

void printAllAntrian()
{
    if (head == NULL)
    {
        cout << "Buat Antrian Pertama Terlebih dahulu" << endl;
    }
    else
    {
        current = head;
        while (current != NULL)
        {
            cout << "Nama Pemesan : " << current->namaPemesan << endl;
            cout << "No Meja : " << current->noMeja << endl;
            current = current->next;
        }
    }
}

int main()
{

    cout << "===== set first data ======" << endl;
    setFirstData("Alfian", 4);
    printAllAntrian();
    cout << "\n"
         << endl;

    cout << "===== add first data ======" << endl;
    addFirstAntrian("Riyo", 2);
    addFirstAntrian("Riyana", 1);
    addFirstAntrian("Rina", 3);
    printAllAntrian();
    cout << "\n"
         << endl;

    cout << "===== add last data ======" << endl;
    addLastData("Calista", 5);
    addLastData("Rahayu", 9);
    printAllAntrian();
    cout << "\n"
         << endl;

    cout << "===== Delete First data ======" << endl;
    removeFirstAntrian();
    printAllAntrian();
    cout << "\n"
         << endl;

    cout << "===== Delete Last data ======" << endl;
    removeLastAntrian();
    printAllAntrian();
    cout << "\n"
         << endl;

    // cout << "===== Update First data ======" << endl;
    // updateFirstAntrian("Riyonali", 10);
    // printAllAntrian();
    // cout << "\n" << endl;

    // cout << "===== Update Last data ======" << endl;
    // updateLastAntrian("Alii", 15);
    // printAllAntrian();
    // cout << "\n" << endl;
}