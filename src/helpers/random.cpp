#include <stdlib.h>
#include <time.h>

int random(int min, int max)
{
    srand(time(NULL));
    int result = rand() % (max - min);

    return result + min;
}
