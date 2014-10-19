#include "PlayerStandState.h"
#include <iostream>

void PlayerStandState::Enter(Player* player){
    std::cout <<"Enter PlayerStandState\n";
}

void PlayerStandState::Update(float ts, Player* player){

}

void PlayerStandState::Exit(Player* player){
    std::cout <<"Exit PlayerStandState\n";
}
