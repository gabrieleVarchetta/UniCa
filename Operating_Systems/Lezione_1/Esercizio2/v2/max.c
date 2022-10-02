#include "max.h"

int max(int a, int b)
{
    int temp;

    temp = (a > b) ? a : b;

    return temp;
}

bool areEquals(int a, int b)
{
    if (a == b)
        return true;

    return false;
}