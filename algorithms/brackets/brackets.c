/*

Read stdin checking   { [ ( left brackets match ) ] } right brackets
Other characters ignored.

$ dcc brackets.c stack_list.c -o brackets   # or stack_array.c or stack_realloc.c
$ ./brackets
[ {{ ( ) } ]
Error: bracket mismatch '{' versus ']'
*/

// Modified 3/5/2019 by Andrew Taylor (andrewt@unsw.edu.au)
// COMP1511 Lecture example

#include <stdio.h>

#include "stack.h"


int main(void) {

    stack s = stack_create();

    int ch = getchar();
    while (ch != EOF) {

        if (ch == '{' || ch == '(' || ch == '[') {
            stack_push(s, ch);
        } else if (ch == '}' || ch == ')' || ch == ']') {
            if (stack_is_empty(s)) {
                printf("Error: unbalanced '%c'\n", ch);
                return 1;
            }

            int left_bracket = stack_pop(s);
            if (
                (ch == '}' && left_bracket != '{') ||
                (ch == ')' && left_bracket != '(') ||
                (ch == ']' && left_bracket != '[')
                ) {
                printf("Error: bracket mismatch '%c' versus '%c'\n", left_bracket, ch);
                return 1;
            }
        }

        ch = getchar();
    }

    if (!stack_is_empty(s)) {
        printf("Error: unbalanced '%c'\n", stack_pop(s));
        return 1;
    }

    return 0;
}
