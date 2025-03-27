// contains a recursive implementation of euclids algorithm which returns the gcd of 2 numbers

#include <stdio.h>
#include <stdlib.h>


int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}


int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s a b\n", argv[0]);
        return 1;
    }
    int a = atoi(argv[1]), b = atoi(argv[2]);
    printf("%d\n", gcd(a, b));
}
