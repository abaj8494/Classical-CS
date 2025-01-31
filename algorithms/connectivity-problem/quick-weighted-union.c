// input: a sequence of pairs < N
// output: pairs representing objects that are not yet connected
//
// time complexity: M lg N
//      - I don't not even remotely understand this time complexity
// space complexity: N

#include <stdio.h>
#define N 10000

int main()
{
    int i, j, p, q, id[N], sz[N];
    for (i = 0; i < N; i++) 
        { id[i] = i; sz[i] = 1; }
    while (scanf("%d %d\n", &p, &q) == 2)
    {
        for (i = p; i != id[i]; i = id[i]) ;
        for (j = q; j != id[j]; j = id[j]) ;
        if (i == j) continue;
        if (sz[i] < sz[j])
             { id[i] = j; sz[j] += sz[i]; }
        else { id[j] = i; sz[i] += sz[j]; }
        printf(" %d %d\n", p, q);
    }

}

// I have no idea what this program does.
// Hoping it clicks a little later...
