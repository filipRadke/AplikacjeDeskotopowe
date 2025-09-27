int** createAndFillField(int x, int y);
bool** createMap(int x, int y);
using point = struct point { int x; int y; };
void move(int** field, point* curr,int x, int y);