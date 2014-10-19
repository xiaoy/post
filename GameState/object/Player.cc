#include "Player.h"
#include "utility.h"
#include "PlayerStandState.h"
#include "PlayerAttackState.h"
#include "PlayerMoveState.h"
#include "PlayerDieState.h"
#include "StateManager.h"
#include <iostream>

Player::Player(int id, std::string name):
    user_id_(id),
    user_name_(name)
{
    play_time_ = 0;
    state_manager_ = new StateManager(this, PlayerStandState::Instance());
    state_vec_.push_back(PlayerStandState::Instance());
    state_vec_.push_back(PlayerAttackState::Instance());
    state_vec_.push_back(PlayerMoveState::Instance());
    state_vec_.push_back(PlayerDieState::Instance());
}

Player::~Player(){
    delete state_manager_;
    state_vec_.clear();
}

StateManager* Player::GetFsm(){
    return state_manager_;
}

void Player::Update(float ts){
    state_manager_->Update(ts);
    play_time_ += ts;
    if(play_time_ > kUpdateTime){
        int index = GetRand(0, state_vec_.size());
        state_manager_->ChangeState(state_vec_[index]);
        play_time_ = 0;
    }
}

bool Player::IsDie(){
    return state_manager_->GetCurState() == PlayerDieState::Instance();
}
