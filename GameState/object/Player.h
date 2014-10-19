#ifndef __PLAYER__
#define __PLAYER__
#include <string>
#include <vector>

class StateManager;
class PlayerState;
static const float kUpdateTime = 2.0f;

class Player{
public:
    Player(int id, std::string name);
    virtual ~Player();
    void Update(float ts);
    bool IsDie();
    StateManager* GetFsm();
private:
    int user_id_;
    float play_time_;
    std::string user_name_;
    StateManager* state_manager_;
    std::vector<PlayerState*> state_vec_;
};

#endif

