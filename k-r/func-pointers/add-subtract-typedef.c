#include <stdio.h>

typedef int (*op_ptr)(int, int);

int add(int a, int b) {return a + b;}
int subt(int a, int b) {return a - b;}

int run(op_ptr op, int a, int b) {
    return op(a, b);
}

int main(void) {
    int r, s;
    r = run(add, 5, 7);
    s = run(subt, 5, 7);

    printf("r: %d\ns: %d\n", r, s);

    return 0;

}
