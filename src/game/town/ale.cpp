#include <ale.h>
#include <declension.h>
#include <interface.h>
#include <random.h>

int ale(int playerGold)
{
    int alePrice = random(1, 3);
    const char* alePriceString =
        declension(alePrice, "золотой", "золота", "золотых");

    Interface::print("Сегодня эль стоит %d %s", alePrice, alePriceString);
    if (playerGold >= alePrice)
    {
        playerGold -= alePrice;
        const char* playerGoldString =
            declension(playerGold, "монета", "монеты", "монет");

        Interface::print("Вы насладились чудесным элем!");
        Interface::print("Теперь у тебя в кошельке осталось %d %s", playerGold,
                         playerGoldString);
    }
    else
    {
        Interface::print("У тебя не хватает монет, чтобы "
                         "расплатиться за выпивку!");
    }

    return playerGold;
}
