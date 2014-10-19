#ifndef __PLAYER_ATTACK_STATE__
#define __PLAYER_ATTACK_STATE__

#include "Singleton.h"
#include "PlayerState.h"

class Player;

class PlayerAttackState : public Singleton<PlayerAttackState>, public PlayerState{
public:
    virtual void Enter(Player* player);
    virtual void Update(float ts, Player* player);
    virtual void Exit(Player* player);
};

#endif
