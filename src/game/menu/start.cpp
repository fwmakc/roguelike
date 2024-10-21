#include <stdio.h>
#include <string.h>

int start(char* nickname)
{
    char c;
    printf("Как тебя зовут, путник?\n");
    fgets(nickname, sizeof(nickname), stdin);

    int len;

    len = strlen(nickname);
    if (nickname[len - 1] == '\n')
    {
        nickname[len - 1] = '\0';
    }
    else
    {
        while ((c = getchar()) != '\n' && c != EOF)
            ; // clear buffer
    }

    printf("Приветствую тебя, %s, и приглашаю в нашу игру!\n", nickname);

    return 0;
}
