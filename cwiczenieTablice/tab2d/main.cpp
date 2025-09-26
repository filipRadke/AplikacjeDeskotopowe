#include "functions.h"
#include <iostream>

using namespace std;

int main()
{
    srand(time(NULL));

    int x = 5000, y = 4000;
    ++x, ++y;
    float fieldArea = 0;

    int** filed = createAndFillField(x, y);
    for(int i = 0; i < x - 1; i++)
    {
        for(int j = 0; j < y - 1; j++)
        {
            fieldArea += calculateSquare(filed[i][j], filed[i][j + 1], filed[i + 1][j], filed[i + 1][j + 1]);
        }
    }

    cout << "Field area: " << fieldArea << endl;

    delete[] filed;
    return 0;
}