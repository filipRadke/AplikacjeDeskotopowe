#include "functions.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
  srand(time(NULL));

  int steps = 0;
  bool stuck = false;

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
      !map[next->x][next->y] ? cout << "Free" << endl : cout << "";

      auto safe = [&](int i, int j)
      {
        if (i >= 0 && i < x && j >= 0 && j < y)
        {
          return map[i][j];
        }
        return true;
      };

      if (safe(start->x-1,start->y-1) && safe(start->x-1,start->y) && safe(start->x-1,start->y+1) &&
        safe(start->x,  start->y-1) && safe(start->x,  start->y+1) &&
        safe(start->x+1,start->y-1) && safe(start->x+1,start->y) && safe(start->x+1,start->y+1))
        stuck = true;
    } while (map[next->x][next->y] && stuck == false);
 
    if(stuck)
    {
      cout << "Stuck!!!" << endl;
      cout << "Steps: " << steps;

      delete[] field, map;
      delete start, end, next;
  
      return 0;
    }

    else
    {
      start = next;
      steps++;
      cout << "Start x: " << start->x << " y: " << start->y << endl;
      for(int i = 0; i<11; i++)
      {
       for(int j = 0; j<11; j++)
        {
           cout << map[i][j];
        }
        cout << endl;
      }
    }

    map[start->x][start->y] = true;
  }
  cout << "Success, steps: " << steps;

  delete[] field, map;
  delete start, end, next;

  return 0;
}
