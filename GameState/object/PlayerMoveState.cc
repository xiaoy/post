#include "PlayerMoveState.h"
#include <iostream>

void PlayerMoveState::Enter(Player* player){
    std::cout << "PlayerMoveState::Enter\n";
}

void PlayerMoveState::Update(float ts, Player* player){

}

void PlayerMoveState::Exit(Player* player){
    std::cout << "PlayerMoveState::Exit\n";
}
