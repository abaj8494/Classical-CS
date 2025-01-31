// a sample program provided by K&R to copy input to output
// page 17

#include <stdio.h>

int main()
{
    int c;
    while ((c = getchar()) != EOF)
        putchar(c);
}

/*
 * this is also equivalent to the longer and less suave version:
 * main()
 * {
 *      int c;
 *      c = getchar();
 *      while (c != EOF) {
 *          putchar(c);
 *          c = getchar();
 *      }
 * }
