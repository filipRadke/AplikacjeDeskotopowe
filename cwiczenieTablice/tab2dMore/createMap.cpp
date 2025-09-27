#include <stdlib.h>
bool** createMap(int x, int y)
{
    bool** map = new bool* [x];
    for (int i = 0; i < x; i++)
    {
        map[i] = new bool[y];
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            map[i][j] = new bool;
        }
    }
    return map;
};
