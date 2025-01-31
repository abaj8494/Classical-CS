#include <stdio.h>
#include <math.h>

int karatsuba(unsigned int a, unsigned int b, unsigned int s) {
    if (a == b && a == 1) return a * b;
    else
    {
    unsigned int a0, a1, b0, b1, u, v, w, x, y;

    a1 = a >> 2;
    a0 = (a << s) >> s;
    b1 = b >> s;
    b0 = (b << s) >> s;

    u = a1 + a0;
    v = b1 + b0;
    printf("shift: %d\na0: %d\ta1: %d\ta: %d\nb0: %d\tb1: %d\tb: %d\n", s, a0, a1, a, b0, b1, b);
    return 1;

    w = karatsuba(a1, b1, s/2);
    x = karatsuba(u, v, s/2);
    y = karatsuba(a0, b0, s/2);

    return w * pow(2, s) + (x - w - y) * pow(2, s / 2) + x;

    }
    
}
