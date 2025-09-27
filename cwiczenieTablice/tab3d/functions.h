#pragma once

using sliceInfo = struct sliceInfo {
    char sliceSide;
    int index;
    double avgTemp;
};

int*** createAndFillRoom(int x, int y, int z);
sliceInfo* getSliceInfo(int*** room, char sliceSide, int index, int x, int y, int z);