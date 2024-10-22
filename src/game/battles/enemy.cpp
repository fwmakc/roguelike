#include <declension.h>
#include <enemy.h>
#include <interface.h>
#include <random.h>

Enemy::Enemy()
{
    hitpoints = random(5, 10);
    gold = random(1, 3);
    level = 1;
}

void Enemy::message(const char* state)
{
    const char* lifeString = declension(hitpoints, "жизнь", "жизни", "жизней");

    if (Interface::equal(state, "start"))
    {
        Interface::print("На тебя напал враг! У него %d %s", hitpoints,
                         lifeString);
    }

    if (Interface::equal(state, "escape"))
    {
        Interface::print("Ты решил сбежать с поля боя. Ну что ж, пока!");
    }

    if (Interface::equal(state, "attack"))
    {
        Interface::print("Ты ударил. У врага осталось %d %s", hitpoints,
                         lifeString);
    }

    if (Interface::equal(state, "miss"))
    {
        Interface::print("Ты промахнулся!");
    }

    if (Interface::equal(state, "win"))
    {
        Interface::print("Ура! Ты победил!");
    }

    if (Interface::equal(state, "fail"))
    {
        Interface::print("Тебе не повезло, ты проиграл!");
    }

    if (Interface::equal(state, "lose"))
    {
        Interface::print(
            "Ух-ты, враг убежал с поля боя. Ты не получаешь монет");
    }
}

int Enemy::start(int playerGold)
{
    const char* action;
    int loop = 1;

    Interface::reset();

    message("start");

    while (loop == 1)
    {
        Interface::print("1. Автобой");
        Interface::print("2. Атаковать");
        Interface::print("0. Убежать");

        action = Interface::get();

        if (Interface::equal(action, "KEY_0"))
        {
            message("escape");
            break;
        }

        if (Interface::equal(action, "KEY_1"))
        {
            while (hitpoints > 0)
            {
                attack();
            }
        }

        if (Interface::equal(action, "KEY_2"))
        {
            attack();
        }

        if (hitpoints < 1)
        {
            playerGold += gold;
            message("win");

            const char* goldString = declension(
                gold, "золотую монету", "золотые монеты", "золотых монет");
            const char* playerGoldString =
                declension(playerGold, "золотой", "золотых", "золота");

            Interface::print("За победу ты получаешь %d %s", gold, goldString);
            Interface::print("Теперь у тебя %d %s", playerGold,
                             playerGoldString);

            break;
        }
        // else
        // {
        //     printw("Goblin run away.");
        //     break;
        // }
    }

    return playerGold;
}

void Enemy::attack()
{
    int value = 100 - (level * 10);
    int success = chance(value);
    if (success)
    {
        hitpoints--;
        message("attack");
    }
    else
    {
        message("miss");
    }
}
