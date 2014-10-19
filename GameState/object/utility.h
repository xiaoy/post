#include <ctime>
#include <stdlib.h>
#include <iostream>

static int seed = 0;
static int GetRand(int min, int max){
    srand(time(nullptr) + seed);
    seed = rand();
    int dis = seed % (max - min);
    return dis + min;
}
