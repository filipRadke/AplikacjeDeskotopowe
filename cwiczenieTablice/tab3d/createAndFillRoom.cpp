#include "functions.h"
#include <stdlib.h>

int*** createAndFillRoom(int x, int y, int z)
{
    int ***arr = new int **[x];
    for (int i = 0; i < x; ++i)
    {
        arr[i] = new int *[y];
        for (int j = 0; j < y; ++j)
        {
            arr[i][j] = new int[z];
            for (int k = 0; k < z; ++k)
            {
                arr[i][j][k] = rand() % 8 + 18;
            }
        }
    }
    return arr;
}