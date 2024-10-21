#include <console.h>
#include <iostream>

using namespace std;

void console::echo(const char* text)
{
    cout << text;
}

void console::Console::print(const char* text)
{
    cout << text << endl;
}
