#include <iostream>
#include <random>

// #include <stdlib.h>
// #include <time.h>

// int random(int min, int max)
// {
//     srand(time(NULL));
//     int result = rand() % (max - min);
//
//     return result + min;
// }

int random(int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distrib(min, max);

    int random_number = distrib(gen);
    return random_number;
}

bool chance(int percent)
{
    int num = random(1, 1000) % 100;
    return num <= percent;
}
