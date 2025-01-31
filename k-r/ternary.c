\\ this is an example of a ternary conditional statement
\\ prints n items of an array


#include <stdio.h>

int main(void)
{
    int i, n = 10, a[] = {9, 5, 4, 3, 2, 1, 6, 1, 2, 3};

    for (i = 0; i < n; i++)
        printf("%6d%c", a[i], (i%10==9 || i==n-1) ? '\n' : ' ');
}
