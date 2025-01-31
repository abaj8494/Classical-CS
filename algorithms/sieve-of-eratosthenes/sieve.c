#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {fprintf(stderr, "Usage %s <integer>\n", argv[0]); return 1;}

    int p = atoi(argv[1]);
    char *a = malloc(sizeof(4*p));

    // initialise array
    for (int i = 1; i < p; i++) {
        a[i] = i;
    }
    // sieve the array
    for (int i = 2; i < p; i++) {
        for (int j = i + 1; j < p; j++) {
            if (!(a[j] % i)) a[j] = 0;
        }
    }

    // print array
    for (int i = 0; i < p; i++) if (a[i] != 0) printf("%d ", a[i]);
    printf("\n");

}
