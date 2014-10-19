#include "PlayerAttackState.h"
#include <iostream>

void PlayerAttackState::Enter(Player* player){
    std::cout <<"PlayerAttackState::Enter\n";
}

void PlayerAttackState::Update(float ts, Player* player){

}

void PlayerAttackState::Exit(Player* player){
    std::cout <<"PlayerAttackState::Exit\n";
}
