#include "functions.h"
#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

int main()
{
  srand(time(NULL));

  int steps = 0;
  float angle = 0;
  bool stuck = false;

  int x = 5000, y = 4000;
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
      cout << "Steps: " << steps << endl;
      cout << "Avg angle: " << (angle * (180.0 / M_PI))/steps << endl;

      delete[] field, map;
      delete start, end, next;
  
      return 0;
    }

    else
    {
      double newAngle;
      double height = field[start->x][start->y] - field[next->x][next->y];
      if(next->x != 0 && next->y != 0)
      {
        newAngle = calculateAngle(abs(height),sqrt(2));
      }
      else
      {
        newAngle = calculateAngle(abs(height),1);
      }

      if(height > 0)
      {
        angle -= newAngle;
      }
      else
      {
        angle += newAngle;
      }
      start = next;
      steps++;
    }

    map[start->x][start->y] = true;
  }
  cout << "Success, steps: " << steps << endl;
  cout << "Avg angle: " << angle/steps << endl;

  delete[] field, map;
  delete start, end, next;

  return 0;
}
