#include "PlayerDieState.h"
#include <iostream>

void PlayerDieState::Enter(Player* player){
    std::cout << "PlayerDieState::Enter\n";
}

void PlayerDieState::Update(float ts, Player* player){

}

void PlayerDieState::Exit(Player* player){
    std::cout << "PlayerDieState::Exit\n";
}
