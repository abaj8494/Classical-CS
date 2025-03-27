// solves the integer values which satisfy the equation ax equiv b (mod m)
// uses the euclidean algorithm

#include <stdio.h>
#include <stdlib.h>


int gcd_ext(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
 
    int x1, y1; // To store results of recursive call
    int gcd_ret = gcd_ext( b % a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd_ret;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s a b c\n", argv[0]);
        return  1;
    }
    int a = atoi(argv[1]), b = atoi(argv[2]), m = atoi(argv[3]), x, y; 
    int d = gcd_ext(a, m, &x, &y);
    x = (x * b / d) % m;
    if (x < 0) x += m;

    // ax equiv b (mod) c => ax + by = c
    if (b % d) printf("no solutions\n");
    else {
        printf("Solutions are: ");
        for (int i = 0; i < d; i++) {
            printf("%d ", (x + i * m/d) % m);
        }
        printf("\n");
    }
    return 0;
    
}
