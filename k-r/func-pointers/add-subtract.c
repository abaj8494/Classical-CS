#include <stdio.h>

int add(int a, int b) {return a + b;}
int subt(int a, int b) {return a - b;}

int operation(int (*func)(int, int), int a, int b) {
    return func(a, b);
}

int main(void) {
    int r, s;
    r = operation(add, 5, 7);
    s = operation(subt, 5, 7);

    printf("r: %d\ns: %d\n", r, s);

    return 0;

}
