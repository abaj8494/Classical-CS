#include <stdio.h>

int square(int i)
{
    return i*i;
}

int main(void) {
    int a[] = {1,2,3,4,5,6,7};
    int (*fp)(int);
    fp = &square;
    for (int i = 0; i < 7; i++) {
        a[i] = (*fp)(a[i]);
    }
    for (int i = 0; i< 7; i++) {printf("%d\n",a[i]);}
    return 0;
}
