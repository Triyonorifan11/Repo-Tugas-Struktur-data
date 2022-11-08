#include <iostream>

using namespace std;

struct Antrian{
    string namaPemesan;
    int noMeja;
    Antrian *next;
};

Antrian *head, *tail, *current, *newNode, *del;

void setFirstData(string namaPemesan, int noMeja){
    head = new Antrian();
    head->namaPemesan = namaPemesan;
    head->noMeja = noMeja;
    head->next = NULL;
    tail = head;
}

void addFirstAntrian(string namaPemesan, int noMeja){
    newNode = new Antrian();
    newNode->namaPemesan = namaPemesan;
    newNode->noMeja = noMeja;
    newNode->next = head;
    head = newNode;
}

void addLastAntrian(string namaPemesan, int noMeja){
    newNode = new Antrian();
    newNode->namaPemesan = namaPemesan;
    newNode->noMeja = noMeja;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

void updateFirstAntrian(string namaPemesan, int noMeja){
    head->namaPemesan = namaPemesan;
    head->noMeja = noMeja;
}

void updateLastAntrian(string namaPemesan, int noMeja){
    tail->namaPemesan = namaPemesan;
    tail->noMeja = noMeja;
}

void removeFirstAntrian(){
    del = head;
    head = head->next;
    delete del;
}

void removeLastAntrian(){
    del = tail;
    current = head;
    while(current->next != tail){
        current = current->next;
    }
    tail = current;
    current->next = NULL;
    delete del;
}

void printAllAntrian(){
    current = head;
    while(current != NULL){
        cout << "Nama Pemesan : " << current->namaPemesan << endl;
        cout << "No Meja : " << current->noMeja << endl;
        current = current->next;
    }
}

int main(){

    cout << "===== set first data ======" << endl;
    setFirstData("Alfian", 4);
    printAllAntrian();
    cout << "\n" << endl;

    cout << "===== add first data ======" << endl;
    addFirstAntrian("Riyo", 2);
    addFirstAntrian("Riyana", 1);
    addFirstAntrian("Rina", 3);
    printAllAntrian();
    cout << "\n" << endl;

    cout << "===== add last data ======" << endl;
    addLastAntrian("Calista", 5);
    addLastAntrian("Rahayu", 9);
    printAllAntrian();
    cout << "\n" << endl;

    cout << "===== Delete First data ======" << endl;
    removeFirstAntrian();
    printAllAntrian();
    cout << "\n" << endl;

    cout << "===== Delete Last data ======" << endl;
    removeLastAntrian();
    printAllAntrian();
    cout << "\n" << endl;

    cout << "===== Update First data ======" << endl;
    updateFirstAntrian("Riyonali", 10);
    printAllAntrian();
    cout << "\n" << endl;

    cout << "===== Update Last data ======" << endl;
    updateLastAntrian("Alii", 15);
    printAllAntrian();
    cout << "\n" << endl;

}