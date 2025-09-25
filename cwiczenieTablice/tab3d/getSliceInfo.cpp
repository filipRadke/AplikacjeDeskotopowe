#include "functions.h"

sliceInfo* getSliceInfo(int*** room, char side, int index, int x, int y, int z)
{
    sliceInfo* currentSlice = new sliceInfo;
    currentSlice->sliceSide = side;
    currentSlice->index = index;
    
    int sumTemp = 0;
    int count = 0;

    if(side == 'x')
    {
        for(int i = 0; i < y; i++)
        {
            for(int k = 0; k < z; k++)
            {
                sumTemp += room[index][i][k];
                count++;
            }
        }
    }
    else if(side == 'y')
    {
        for(int i = 0; i < x; i++)
        {
            for(int k = 0; k < z; k++)
            {
                sumTemp += room[i][index][k];
                count++;
            }
        }
    }
    currentSlice->avgTemp = (float)sumTemp / count;
    return currentSlice;
}