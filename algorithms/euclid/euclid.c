// taken from the end of chapter 2 in sedgewick's algorithms book
// I like the do while loop and the funky variable declaration after the function declaration

#include <stdio.h>

int gcd(u, v)
    int u, v;
    {
        int t;
        do {
            if (u<v)
                { t = u; u = v; v = t;};
            u = u-v;
        } while (u != v);
        return (u);
    }

int main(void)
{
    int x, y;
    while (scanf("%d %d", &x, &y) != EOF)
        if ((x > 0) && (y > 0))
            printf("%d %d %d\n", x, y, gcd(x,y));
}

