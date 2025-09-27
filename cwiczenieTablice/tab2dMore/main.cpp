#include "functions.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    srand(time(NULL));

    string n;

    int x = 10, y = 10;
    ++x, ++y;

    int **field = createAndFillField(x, y);
    bool **map = createMap(x, y);

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            map[i][j] = false;
        }
        cout << endl;
    }
    cout << endl;

    point *start = new point{rand() % x, rand() % y};
    point *end = new point{rand() % x, rand() % y};
    point *next = new point();

    map[start->x][start->y] = true;

    cout << "Start: " << start->x << " " << start->y << endl;
    cout << "End: " << end->x << " " << end->y << endl;

    while (map[end->x][end->y] == false)
    {
        do
        {
            next = new point{start->x + rand() % 3 - 1, start->y + rand() % 3 - 1};
            if (next->x < 0)
                next->x = 0;
            if (next->y < 0)
                next->y = 0;
            if (next->x >= x)
                next->x = x - 1;
            if (next->y >= y)
                next->y = y - 1;
            //!map[next->x][next->y] ? cout << "Free" << endl : cout << "";
        } while (map[next->x][next->y]);

        start = next;

        map[start->x][start->y] = true;
    }

    delete[] field, map;
    delete start, end, next;
    return 0;
}