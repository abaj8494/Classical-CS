#include <stdio.h>
#include "lg.h"

int main(void)
{
    int i, N;
    printf("%8s %11s %14s\n", "| O(n) |", " O(log(n)) ", "| O(nlog(n)) |");
    printf("-----------------------------------\n");
    for (i = 1, N = 10; i <= 6; i++, N*= 10)
        printf("%8d %11d %14d\n", N, lg(N), N*lg(N));
    printf("log 8: %d\n", lg(8));
    return 0;
}
