#include <declension.h>
#include <interface.h>
#include <random.h>

const char* goblinDeclension(int goblinHp)
{
    return declension(goblinHp, "жизнь", "жизни", "жизней");
}

int goblin(int playerGold)
{
    int goblinHp = random(2, 4);
    int goblinGold = random(5, 15);
    const char* goblinString;

    goblinString = goblinDeclension(goblinHp);

    const char* action;
    int loop = 1;

    Interface::reset();

    Interface::print("Тебя атаковал гоблин! У него %d %s", goblinHp,
                     goblinString);

    while (loop == 1)
    {
        Interface::print("1. Автобой");
        Interface::print("2. Атаковать");
        Interface::print("0. Убежать");

        action = Interface::get();

        if (Interface::equal(action, "KEY_0"))
        {
            Interface::print("Ты решил сбежать с поля боя. Ну что ж, пока!");
            break;
        }

        if (Interface::equal(action, "KEY_1"))
        {
            while (goblinHp > 0)
            {
                goblinHp--;
                goblinString = goblinDeclension(goblinHp);
                Interface::print("Ты ударил гоблина. У него осталось %d %s",
                                 goblinHp, goblinString);
            }
        }

        if (Interface::equal(action, "KEY_2"))
        {
            goblinHp--;
            goblinString = goblinDeclension(goblinHp);
            Interface::print("Ты ударил гоблина. У него осталось %d %s",
                             goblinHp, goblinString);
        }

        if (goblinHp < 1)
        {
            playerGold += goblinGold;
            Interface::print("Ура! Ты победил гоблина!");

            const char* goblinGoldString =
                declension(goblinGold, "золотую монету", "золотые монеты",
                           "золотых монет");
            const char* playerGoldString =
                declension(playerGold, "золотой", "золотых", "золота");

            Interface::print("За победу ты получаешь %d %s", goblinGold,
                             goblinGoldString);
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
