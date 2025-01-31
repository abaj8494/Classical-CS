#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_prime(int p) {
    int n = (int) sqrt(p);
    for (int i = 2; i < n; i++) {
        if (!(p % i)) return false;
    }
    return true;
}
