#include <iostream>
#include <math.h>

using namespace std;

double rekursif(double x, float n)
{
    int hasil;
    if (n == 0)
    {
        return 1;
    }
    else if (n > 0)
    {
        return (x * rekursif(x, n - 1));
    }
    else
    {
        return (1 / rekursif(x, -(n)));
    }
}

double pangkatAkar(double nilaiX, double nilaiN)
{
    if (nilaiN == 0)
    {
        return 1;
    }
    else if (nilaiX == 0)
    {
        return 0;
    }
    else
    {
        return (nilaiX * (pangkatAkar(nilaiX, nilaiN - 1) / 2));
    }
}

int main(int argc, char const *argv[])
{
    int x = 4, n = -2;
    cout << "hasil dari x(x^n-1) dengan x=" << x << " dan n=" << n << " adalah ";
    cout << rekursif(x, n) << endl;

    int y = 4, nilaiN = 0;
    cout << "Hasil " << y << " pangkat " << nilaiN << " = " << pangkatAkar(y, nilaiN) << endl;

    return 0;
}
