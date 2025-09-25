#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
    srand(time(NULL));

    int x = 50, y = 40, z = 27;

    int ***room = createAndFillRoom(x, y, z);

    sliceInfo *currentSlice = new sliceInfo;
    sliceInfo *maxTempSlice = new sliceInfo;

    for (int i = 0; i < x; i++)
    {
        currentSlice = getSliceInfo(room, 'x', i, x, y, z);
        if (i == 0 || currentSlice->avgTemp > maxTempSlice->avgTemp)
        {
            maxTempSlice = currentSlice;
        }
    }
    for (int i = 0; i < y; i++)
    {
        sliceInfo *currentSlice = getSliceInfo(room, 'y', i, x, y, z);
        if (currentSlice->avgTemp > maxTempSlice->avgTemp)
        {
            maxTempSlice = currentSlice;
        }
    }

    cout << "Max avg temp slice is from side " << maxTempSlice->sliceSide << " with index " << maxTempSlice->index << " and avg temp " << maxTempSlice->avgTemp << endl;

    delete currentSlice, maxTempSlice;
    delete[] room;
    return 0;
}