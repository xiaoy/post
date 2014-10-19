#ifndef __STATE_MANAGER__
#define __STATE_MANAGER__
class PlayerState;
class Player;

class StateManager{
public:
    StateManager(Player* player, PlayerState* state);
    virtual ~StateManager(){}
    void Update(float ts);
    void ChangeState(PlayerState* state);
    PlayerState* GetCurState();
private:
    PlayerState* pre_state_;
    PlayerState* cur_state_;
    Player* player_;
};
#endif
