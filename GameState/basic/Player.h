#include <string>

enum PlayerState{
    INVALID,
    STAND,
    MOVE,
    ATTACK,
    DIE
};

static const int kMaxHp = 100;
static const float kSpeed = 2.0f;

struct MonsterInfo{
    int count;
    int pos;
};

class Player{
    public:
        Player(){};
        Player(int id, std::string name);
        virtual ~Player(){}
        void SetState(PlayerState state);
        void Update(float ts);
        bool IsDie();
    private:
        void FindMonster();
        void Stand(float ts);
        void Move(float ts);
        void Attack(float ts);
        void Die();
    private:
        int hp_;
        int user_id_;
        int monster_count_;
        float move_speed_;
        float move_distance_;
        float play_time_;
        MonsterInfo monster_info_;
        std::string  user_name_;
        PlayerState user_state_;
};
