#include <stdio.h>
#include <stdlib.h>
#include "fac.h"

int main(int argc, char *argv[])
{
    int i, r;
    int f = atoi(argv[1]);
    i = it(f);
    r = rec(f);
    printf("Iterative factorial of %d is %d\n"
            "Recursive factorial of %d is %d\n", f, i, f, r);
    return 0;
}
