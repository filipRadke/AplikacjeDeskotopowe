#include <stdlib.h>
int** createAndFillField(int x, int y)
{
    int** field = new int* [x];
    for (int i = 0; i < x; i++)
    {
        field[i] = new int[y];
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            field[i][j] = rand() % 2299 + 1200;
        }
    }
    return field;
};
