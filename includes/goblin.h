#ifndef _GOBLIN_H_
#define _GOBLIN_H_

#include <enemy.h>

class Goblin : public Enemy
{
  public:
    Goblin();
    void message(const char* state) override;
}

#endif
;
