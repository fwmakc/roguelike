#include <codecvt>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <interface.h>
#include <pdcurses.h>

void Interface::open()
{
    initscr();
    start_color();
}

void Interface::close()
{
    endwin();
}

void Interface::reset()
{
    clear();
}

void Interface::print(const char* format, ...)
{
    // Инициализация списка аргументов
    va_list args;
    va_start(args, format);

    // Используем vsprintf для получения форматированной строки
    char buffer[256]; // Буфер для строки (выделите нужный размер)
    vsnprintf(buffer, sizeof(buffer), format, args);

    // Выводим текст на экран с помощью printw
    printw("%s", buffer);

    // Завершаем работу с аргументами
    va_end(args);

    printw("\n");

    refresh();
}

const char* Interface::get()
{
    const char* result;
    int action;

    action = getch();

    switch (action)
    {
    case 48:
    case 41: result = "KEY_0"; break;
    case 49:
    case 33: result = "KEY_1"; break;
    case 50:
    case 64: result = "KEY_2"; break;
    case 51:
    case 35: result = "KEY_3"; break;
    case 52:
    case 36: result = "KEY_4"; break;
    case 53:
    case 37: result = "KEY_5"; break;
    case 54:
    case 94: result = "KEY_6"; break;
    case 55:
    case 38: result = "KEY_7"; break;
    case 56:
    case 42: result = "KEY_8"; break;
    case 57:
    case 40: result = "KEY_9"; break;

    case 65:
    case 97: result = "KEY_A"; break;
    case 66:
    case 98: result = "KEY_B"; break;
    case 67:
    case 99: result = "KEY_C"; break;
    case 68:
    case 100: result = "KEY_D"; break;
    case 69:
    case 101: result = "KEY_E"; break;
    case 70:
    case 102: result = "KEY_F"; break;
    case 71:
    case 103: result = "KEY_G"; break;
    case 72:
    case 104: result = "KEY_H"; break;
    case 73:
    case 105: result = "KEY_I"; break;
    case 74:
    case 106: result = "KEY_J"; break;
    case 75:
    case 107: result = "KEY_K"; break;
    case 76:
    case 108: result = "KEY_L"; break;
    case 77:
    case 109: result = "KEY_M"; break;
    case 78:
    case 110: result = "KEY_N"; break;
    case 79:
    case 111: result = "KEY_O"; break;
    case 80:
    case 112: result = "KEY_P"; break;
    case 81:
    case 113: result = "KEY_Q"; break;
    case 82:
    case 114: result = "KEY_R"; break;
    case 83:
    case 115: result = "KEY_S"; break;
    case 84:
    case 116: result = "KEY_T"; break;
    case 85:
    case 117: result = "KEY_U"; break;
    case 86:
    case 118: result = "KEY_V"; break;
    case 87:
    case 119: result = "KEY_W"; break;
    case 88:
    case 120: result = "KEY_X"; break;
    case 89:
    case 121: result = "KEY_Y"; break;
    case 90:
    case 122: result = "KEY_Z"; break;

    case 96:
    case 126: result = "KEY_TILDA"; break;
    case 45:
    case 95: result = "KEY_MINUS"; break;
    case 43:
    case 61: result = "KEY_PLUS"; break;
    case 92:
    case 124: result = "KEY_BACKSLASH"; break;
    case 46:
    case 62: result = "KEY_PERIOD"; break;
    case 44:
    case 60: result = "KEY_COMMA"; break;
    case 59:
    case 58: result = "KEY_COLON"; break;
    case 39:
    case 34: result = "KEY_QUOTE"; break;
    case 47:
    case 63: result = "KEY_SLASH"; break;
    case 91:
    case 123: result = "KEY_BRACKET_OPEN"; break;
    case 93:
    case 125: result = "KEY_BRACKET_CLOSE"; break;

    case 9: result = "KEY_TAB"; break;
    case 27: result = "KEY_ESC"; break;
    case 127: result = "KEY_DEL"; break;
    case 32: result = "KEY_SPACE"; break;
    case 13: result = "KEY_ENTER"; break;
    }

    clear();
    return result;
}

bool Interface::equal(const char* str1, const char* str2)
{
    return strcmp(str1, str2) == 0;
}

void Interface::wait()
{
    int action;
    action = getch();
}
