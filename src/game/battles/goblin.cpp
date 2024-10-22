#include <declension.h>
#include <goblin.h>
#include <interface.h>
#include <random.h>

Goblin::Goblin()
{
    hitpoints = random(2, 4);
    gold = random(3, 10);
    level = 5;
}

void Goblin::message(const char* state)
{
    const char* goblinString =
        declension(hitpoints, "жизнь", "жизни", "жизней");

    if (Interface::equal(state, "start"))
    {
        Interface::print("Тебя атаковал гоблин! У него %d %s", hitpoints,
                         goblinString);
    }

    if (Interface::equal(state, "escape"))
    {
        Interface::print("Ты решил сбежать с поля боя. Ну что ж, пока!");
    }

    if (Interface::equal(state, "attack"))
    {
        Interface::print("Ты ударил гоблина. У него осталось %d %s", hitpoints,
                         goblinString);
    }

    if (Interface::equal(state, "miss"))
    {
        Interface::print("Ты промахнулся!");
    }

    if (Interface::equal(state, "win"))
    {
        Interface::print("Ура! Ты победил гоблина!");
    }

    if (Interface::equal(state, "fail"))
    {
        Interface::print("Тебе не повезло, гоблин победил тебя!");
    }

    if (Interface::equal(state, "lose"))
    {
        Interface::print("Ух-ты, гоблин убежал. Ты не получаешь монет");
    }
}
