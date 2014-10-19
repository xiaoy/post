#ifndef __PLAYER_STATE__
#define __PLAYER_STATE__
class Player;
class PlayerState{
public:
    PlayerState(){}
    virtual ~PlayerState(){};
    virtual void Enter(Player* player) = 0;
    virtual void Update(float ts, Player* player) = 0;
    virtual void Exit(Player* player) = 0;
};

#endif
