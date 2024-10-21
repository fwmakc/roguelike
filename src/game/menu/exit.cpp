#include <interface.h>

void exit()
{
    Interface::reset();
    Interface::print("Жаль, что Вы покидаете нас");
    Interface::print("Чтобы выйти, нажмите любую клавишу...");
    Interface::wait();
    Interface::close();
}
