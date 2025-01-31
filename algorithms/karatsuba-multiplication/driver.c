#include <stdio.h>
#include <stdlib.h>
#include "driver.h"

int main(int argc, char *argv[])
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    printf("result: %d\n", karatsuba(a, b, (sizeof(int) * 8) / 2 ));
}
