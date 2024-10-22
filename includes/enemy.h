#ifndef _ENEMY_H_
#define _ENEMY_H_

class Enemy
{
  public:
    int hitpoints;
    int gold;
    int level;
    Enemy();
    int start(int playerGold);
    void attack();
    virtual void message(const char* state);
}

#endif
;
