#ifndef __PLAYER_DIE_STATE__
#define __PLAYER_DIE_STATE__

#include "Singleton.h"
#include "PlayerState.h"

class Player;

class PlayerDieState : public Singleton<PlayerDieState>, public PlayerState{
public:
    virtual void Enter(Player* player);
    virtual void Update(float ts, Player* player);
    virtual void Exit(Player* player);
};

#endif


