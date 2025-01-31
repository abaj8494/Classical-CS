#include <stdio.h>

#define     IN      1
#define     OUT     0

int main()
{
    int c, state;
    state = OUT; // if you leave this variable uninitialised it could bug.

    while ((c = getchar()) != EOF) {
        if (state == OUT && c == ' ') {putchar(c); state = IN;}
        else if (state == IN && c == ' ') continue;
        else {putchar(c); state = OUT;}
    }
}
