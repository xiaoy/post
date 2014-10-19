#include "Player.h"
#include "Utility.h"
#include <iostream>

Player::Player(int id, std::string name):
    user_id_(id),
    user_name_(name)
{
    move_distance_ = 0;
    move_speed_ = kSpeed;
    play_time_ = 0;
    user_state_ = STAND;
    hp_ = kMaxHp;
}

void Player::Update(float ts){
    switch(user_state_){
        case STAND:
            Stand(ts);
            break;
        case MOVE:
            Move(ts);
            break;
        case ATTACK:
            Attack(ts);
            break;
        case DIE:
            Die();
            return;
        default:
            std::cout<<"error\n";

    }

    if(hp_ <= 0){
        SetState(DIE);
    }
}
void Player::FindMonster(){
    monster_info_.count = GetRand(1, 10);
    monster_info_.pos = GetRand(10, 50);
}

void Player::Stand(float ts){
    int ret = GetRand(0, 100);
    int guess = 0;
    while(true){
        std::cout << "guess the number in(0, 100):";
        std::cin >> guess;
        if(guess == ret){
            FindMonster();
            std::cout << "you have find "<< monster_info_.count << " monster\n";
            std::cout << "the pos is:" << monster_info_.pos << std::endl;
            SetState(MOVE);
            break;
        }

        int lossHp = GetRand(1, 10);
        hp_ = hp_ - lossHp;
        if(guess < ret){
            std::cout << "you are too small, loss hp:" << lossHp << "\n";
        }
        else{
            std::cout << "you are too big, loss hp:" << lossHp << "\n";
        }
        std::cout << "your current hp is:" << hp_ << std::endl;
    }
}

void Player::Move(float ts){
    move_distance_ += move_speed_ * ts;
    play_time_ += ts;
    if(play_time_ >= 1){
        std::cout << "the position is:" << move_distance_ << std::endl;
        play_time_ = 0;
    }

    if(move_distance_ >= monster_info_.pos){
        std::cout << "have reached the target:" << move_distance_ << std::endl;
        move_distance_ = 0;
        SetState(ATTACK);
    }
}

void Player::Attack(float ts){
    if(monster_info_.count == 0){
        SetState(STAND);
        return;
    }

    int monsterAttack = GetRand(1, 100);
    while(true){
        if(hp_ <= 0){
            break;
        }

        int attack = 0;
        std::cout << "play your attack at "<< monster_info_.count <<" in(1, 100):";
        std::cin >> attack;

        if(attack == monsterAttack){
            monster_info_.count -= 1;
            std::cout << "you killed the monster\n";
            break;
        }

        int lossHp = GetRand(1, 5);
        hp_ -= lossHp;
        if(attack > monsterAttack){
            std::cout << "your attack is too big, loss hp:" << lossHp << std::endl;
        }
        else{
            std::cout << "your attack is too small, loss hp:" << lossHp << std::endl;
        }
        std::cout << "your current hp is:" << hp_ << std::endl;
    }
}

void Player::Die(){

}

bool Player::IsDie(){
    return user_state_ == DIE;
}

void Player::SetState(PlayerState state){
    if(state == user_state_){
        return;
    }
    switch(state){
        case STAND:
            std::cout << "----begin stand--------\n";
            break;
        case MOVE:
            std::cout << "----begin move--------\n";
            break;
        case ATTACK:
            std::cout << "----begin attack--------\n";
            break;
        case DIE:
            std::cout << "----begin die--------\n";
            break;
        default:
            std::cout <<"the state is error";
            break;
    }
    user_state_ = state;
}
