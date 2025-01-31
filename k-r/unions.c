// unions are like structs
// but instead of reserving all the memory for every field of the struct
// a union only reserves the max memory of ONE of the field items
// see example:
#include <stdio.h>

typedef struct {
    int a;
    char b;
    float c;
} mystruct;

typedef union {
    int a;
    char b;
    float c;
} myunion;

int main(void)
{
    mystruct s;
    myunion u;
    printf("sizeof struct: %lu\n", sizeof(s));
    printf("sizeof union: %lu\n", sizeof(u));
}

// the purpose of this is to save space.
// conceptually can think of this as set theory notation ~= OR
