#include "StateManager.h"
#include "PlayerState.h"
#include <iostream>

StateManager::StateManager(Player* player, PlayerState* state):
    player_(player),
    cur_state_(state)
{
    cur_state_->Enter(player);
}

void StateManager::Update(float ts){
    if(cur_state_ != nullptr){
        cur_state_->Update(ts, player_);
    }
}

PlayerState* StateManager::GetCurState(){
    return cur_state_;
}

void StateManager::ChangeState(PlayerState* state){
    if(cur_state_ != state){
        cur_state_->Exit(player_);
        pre_state_ = cur_state_;
        cur_state_ = state;
        cur_state_->Enter(player_);
    }
}
