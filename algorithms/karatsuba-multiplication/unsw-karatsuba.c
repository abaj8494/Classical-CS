// implements karatsuba's integer multiplication algorithm
// input: integers to multiply - a, b
//        threshold integer d

#include <stdio.h>
#include <math.h>


int karatsuba(unsigned int a, unsigned int b, unsigned int s)
{
   if (a == b && a == 1) return a*b;
   else {
       int shift = (sizeof(int) * 8) / 2; 
       unsigned int a0, a1, b0, b1, u, v, x, w, y;

       a0 = (a << shift) >> shift;
       b0 = (b << shift) >> shift;
       a1 = (a >> shift) << shift;
       b1 = (b >> shift) << shift;

       
       u = a0 + a1;
       v = b0 + b1;

       printf("shift: %d\na0: %d\ta1: %d\ta: %d\nb0: %d\tb1: %d\tb: %d\n", shift, a0, a1, a, b0, b1, b);
       w = karatsuba(a0, b0);
       x = karatsuba(a1, b1);
       y = karatsuba(u, v);

       return w * pow(2, 2*shift) + (y - x - w) * pow(2, shift) + x;
   }

}
