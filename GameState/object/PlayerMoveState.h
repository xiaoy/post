#ifndef __PLAYER_MOVE_STATE__
#define __PLAYER_MOVE_STATE__

#include "Singleton.h"
#include "PlayerState.h"

class Player;

class PlayerMoveState : public Singleton<PlayerMoveState>, public PlayerState{
public:
    virtual void Enter(Player* player);
    virtual void Update(float ts, Player* player);
    virtual void Exit(Player* player);
};
#endif
