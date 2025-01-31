/*
Reverse Polish notation calculator using stack ADT

https://en.wikipedia.org/wiki/Reverse_Polish_notation

$ dcc postfix.c stack_list.c -o postfix   # or stack_array.c or stack_realloc.c
$ ./postfix
15 7 1 1 + - / 3 * 2 1 1 + + -
Result: 5
*/

// Modified 3/5/2019 by Andrew Taylor (andrewt@unsw.edu.au) original example courtesy Alan Blair
// COMP1511 Lecture example

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "stack.h"

#define MAX_LINE 4096
int main(void) {

    char line[4096];
    while (fgets(line, sizeof line, stdin) != NULL) {
        stack s = stack_create();

        int i = 0;
        while (line[i] != '\0') {
            int ch = line[i];

            if (isdigit(ch)) {
                // convert chars to num push number onto stack
                // and skip over digits

                int num = atoi(&line[i]);

                stack_push(s, num);

                while (isdigit(line[i])) {
                    i = i + 1;
                }
            } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {

                // pop 2 values from stack
                // calculate result
                // push result onto stack

                int a = stack_pop(s);
                int b = stack_pop(s);

                int result;
                if (ch == '+') {
                    result = b + a;
                } else if (ch == '-') {
                    result = b - a;
                } else if (ch == '*') {
                    result = b * a;
                } else {
                    result = b / a;
                }

                stack_push(s, result);
            }
            i = i + 1;
        }

        printf("Result: %d\n", stack_pop(s));
    }

    return 0;
}
