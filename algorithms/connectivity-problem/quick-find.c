// input: a sequence of pairs < N
// output: pairs representing objects that are not yet connected
//
// time complexity: M*N
//      - I don't fully understand this time complexity either
// space complexity: N

#include <stdio.h>
#define N 10000

// you do not need to define the return type for main!
//      - jokes it seems like you do. gcc complains
int main() {
    // declare variables
    int i, t, p, q, id[N];
    // set values of id array to [0, 1, 2, ..., N]
    for (i = 0; i < N; i++) id[i] = i;

    // whilst input is 2 numbers...
    while ((scanf("%d %d\n", &p, &q) == 2)) {
        if (id[p] == id[q]) continue;
        for (t = id[p], i = 0; i < N; i++) {
            if (id[i] == t) id[i] = id[q];
        }
        printf(" %d %d\n", p, q);
    }
    // no return value and gcc compiles without warning...
}

// i'm still not entirely sure what this program does with respect
// to the connectivity problem but I thought typing out the code would help...

