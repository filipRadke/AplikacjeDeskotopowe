#include<iostream>

using namespace std;

int main()
{
    int tab[10];

    for(int i=0; i<10; i++)
    {
        tab[i] = i;
    }

    cout << *tab << endl;
    cout << *(tab + 1) << endl;


    int tabSquare[2][3] = { {1,2,3}, {4,5,6} };

    cout << *tabSquare+2 << endl;
    cout << *(tabSquare+1) [0] << endl;
}