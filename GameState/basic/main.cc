#include <iostream>
#include <stdio.h>
#include <ctime>
#include "Player.h"

static const int kFrameCount = 60;
static const float kSecondsPerFrame = 1.0f/kFrameCount;

int main(){
    Player* player = new Player(1001, "pis");
    clock_t startTickCount = clock();
    while(true){
        clock_t t = clock() - startTickCount;
        float detTime = (float)t/CLOCKS_PER_SEC;
        if(detTime >= kSecondsPerFrame){
            startTickCount = clock();
            player->Update(detTime);
            if(player->IsDie()){
                std::cout<< "Game Over\n";
                break;
            }
        }
    }
}
