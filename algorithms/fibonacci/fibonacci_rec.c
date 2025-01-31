#include <stdio.h>
#include <stdlib.h>

int fib(int f) {
    if (f == 1 || f == 0) return 1;
    else return (fib(f - 1) + fib(f - 2));
}


int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <int>\n", argv[0]);
        return 1;
    }

    printf("%d\n", fib(atoi(argv[1])));
    return 0;
}
