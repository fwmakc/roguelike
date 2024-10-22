#include <exit.h>
#include <interface.h>
#include <random.h>
#include <start.h>
#include <tavern.h>

int main(void)
{
    char nickname[8];
    // char hero = '@';
    int playerGold = 0;

    start(nickname);

    Interface::open();

    tavern(playerGold, nickname);

    exit();

    return 0;
}
