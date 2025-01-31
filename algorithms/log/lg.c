#include "lg.h"

int lg(int n)
{
    int i = 0;
    for (; n > 1; i++, n /= 2);
    return i;
}
