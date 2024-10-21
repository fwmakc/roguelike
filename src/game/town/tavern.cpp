#include <ale.h>
#include <declension.h>
#include <goblin.h>
#include <interface.h>


int tavern(int playerGold, char* nickname)
{
    const char* action;
    int loop = 1;

    while (loop == 1)
    {
        Interface::reset();

        Interface::print("Привет, %s! Чем хочешь заняться сегодня?", nickname);
        Interface::print("1. Выпить в таверне");
        Interface::print("2. Узнать, сколько у тебя монет");
        Interface::print("3. Пойти в лес поохотиться на гоблинов");
        Interface::print("0. Выйти из игры");

        action = Interface::get();

        if (Interface::equal(action, "KEY_1"))
        {
            playerGold = ale(playerGold);
        }

        if (Interface::equal(action, "KEY_2"))
        {
            const char* playerGoldString =
                declension(playerGold, "золотая монета", "золотые монеты",
                           "золотых монет");

            Interface::print("У вас %d %s", playerGold, playerGoldString);
        }

        if (Interface::equal(action, "KEY_3"))
        {
            playerGold = goblin(playerGold);
        }

        if (Interface::equal(action, "KEY_0"))
        {
            break;
        }

        Interface::print("Нажмите любую клавишу...");
        Interface::wait();
    }

    return playerGold;
}
