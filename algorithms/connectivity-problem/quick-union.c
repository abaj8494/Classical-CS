// input: a sequence of pairs < N
// output: pairs representing objects that are not yet connected
//
// time complexity: unknown
// space complexity: N

#include <stdio.h>
#define N 10000

int main() {
    // declare variables
    int i, j, p, q, id[N];
    // set values of id array to [0, 1, 2, ..., N]
    for (i = 0; i < N; i++) id[i] = i;

    // whilst input is 2 numbers...
    while ((scanf("%d %d\n", &p, &q) == 2)) {
        // changed the while body for _quick union_ implementation
        for (i = p; i != id[i]; i = id[i]) ;
        for (j = q; q != id[j]; j = id[j]) ;
        if (i == j) continue;
        id[i] = j;
        printf(" %d %d\n", p, q);
    }
}

