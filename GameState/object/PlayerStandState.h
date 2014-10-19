#ifndef __PLAYER_STAND_STATE__
#define __PLAYER_STAND_STATE__

#include "Singleton.h"
#include "PlayerState.h"
class Player;

class PlayerStandState : public Singleton<PlayerStandState>, public PlayerState{
public:
    virtual void Enter(Player* player);
    virtual void Update(float ts, Player* player);
    virtual void Exit(Player* player);
};

#endif
