#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;
int j = 0;
struct RandomData
{
    int randDom;
} randData[10000];

void createdRandNumber(int banyak)
{
    for (int k = 0; k < banyak; k++)
    {
        randData[j].randDom = rand();
        j++;
    }
}

void tukarData(struct RandomData *a, struct RandomData *b)
{
    struct RandomData temp = *a;
    *a = *b;
    *b = temp;
}

// ascending NPM
void InsertionSort()
{
    for (int i = 0; i < j; i++)
    {
        for (int k = i; k > 0 && randData[k].randDom < randData[k - 1].randDom; k--)
        {
            tukarData(&randData[k], &randData[k - 1]);
        }
    }
}

void showAllData()
{
    int i = 0;
    while (i < j)
    {
        cout << i + 1 << ". " << randData[i].randDom << endl;
        i++;
    }
}

int main()
{
    createdRandNumber(100);
    showAllData();

    cout << "Sorting dengan Insertion Sort" << endl;
    InsertionSort();
    showAllData();
    return 0;
}