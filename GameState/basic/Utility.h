#include <ctime>
#include <stdlib.h>

static int GetRand(int min, int max){
    int ret = rand();
    srand(ret + time(nullptr));
    return ret % (max - min) + min;
}
