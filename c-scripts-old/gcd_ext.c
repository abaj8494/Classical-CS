// program which prints out the extended euclid algorithm for 2 integers.

#include <stdio.h>
#include <stdlib.h>

int q_func(int a, int b) {
    return a / b;
}

int r_func(int a, int b, int q) {
    return a - (q * b);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <integer 1> <integer 2>\n", argv[0]);
        return 1;
    }

    int a = atoi(argv[1]), b = atoi(argv[2]), 
        q = q_func(a, b), r = r_func(a, b, q);

    do {
        printf("%d = %d * %d + %d\n", a, q, b, r);
        a = b;
        b = r;
        q = q_func(a, b);
    }
    while ((r = r_func(a, b, q)));

    printf("%d = %d * %d + %d\n", a, q, b, r);
    printf("Hence the GCD is %d\n", b);
    return 0;
}
