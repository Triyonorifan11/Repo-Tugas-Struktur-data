#include <iostream>

using namespace std;

// arrau antrian resto
int datamaks = 5, front = 0, back = 0;
string antrianResto[5];

// check is full
bool isFullAntrian()
{
    return (back == datamaks) ? true : false;
}

bool isEmptyAntrian()
{
    return (back == 0) ? true : false;
}

// enqueue
void enqueueAntrian(string data)
{
    if (isFullAntrian())
    {
        cout << "Antrian sedang penuh, Mohon menunggu" << endl;
    }
    else if (isEmptyAntrian())
    {
        antrianResto[0] = data;
        front++;
        back++;
    }
    else
    {
        antrianResto[back] = data;
        back++;
    }
}

// dequeue
void dequeueAntrian()
{
    if (isEmptyAntrian())
    {
        cout << "Antrian belum ada" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            antrianResto[i] = antrianResto[i + 1];
        }
        back--;
    }
}

// jumlah antrian
int countData()
{
    if (isEmptyAntrian()) { return 0; }
    else if (isFullAntrian()){ return datamaks; }
    else{ return back; }
}

// delete all
void deleteDataAntrian()
{
    if (isEmptyAntrian()){
        cout << "Antrian belum ada" << endl;
    }else{
        for (int i = 0; i <= datamaks; i++){
            if( back > 1 ){
                antrianResto[back - 1] = "";
                back--;
            }else if(back == 1 ){
                antrianResto[back-1] = "";
                back = 0;
                front = 0;
            }
        }
    }
}

// show data
void echodata()
{
    cout << "Jumlah data: " << countData() << endl;
    cout << "Data antrian resto" << endl;
    if (isEmptyAntrian())
    {
        cout << "Antrian belum ada" << endl;
    }
    else
    {
        for (int i = 0; i < datamaks; i++)
        {
            if (antrianResto[i] != "")
            {
                cout << i + 1 << ". " << antrianResto[i] << endl;
            }
            else
            {
                cout << i + 1 << ". (belum ada)" << endl;
            }
        }
    }
    cout << endl
         << endl;
}

int main(int argc, char const *argv[])
{
    /* code */
    cout << "is full? " << isFullAntrian() << endl;
    cout << "is emtpy? " << isEmptyAntrian() << endl;
    enqueueAntrian("Riyo");
    enqueueAntrian("Calista");
    echodata();

    enqueueAntrian("Rahayu");
    enqueueAntrian("Niken");
    enqueueAntrian("Shifa");
    echodata();
    enqueueAntrian("Shifani");
    echodata();

    dequeueAntrian();
    echodata();

    dequeueAntrian();
    echodata();


    deleteDataAntrian();
    echodata();

    return 0;
}
