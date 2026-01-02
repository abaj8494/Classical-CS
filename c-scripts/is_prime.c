// checks if an integer is prime

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(int p) {
    int n = (int) sqrt(p);
    for (int i = 2; i < n; i++) {
        if (!(p % i)) return false;
    }
    return true;
}

int main (int argc, char **argv) {
    int p = atoi(argv[1]);
    printf(is_prime(p) ? "true\n" : "false\n");
    return 0;
}
