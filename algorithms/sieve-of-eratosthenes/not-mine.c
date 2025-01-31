// outputs all of the prime numbers within a range
// input is a command line argument

// time complexity: N lg N
// space complexity: N

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <integer>\n", argv[0]);
        return 1;
    }

    // convert argument to integer
    int N = atoi(argv[1]);

    // declare and initialise array
    int *a = malloc(sizeof(int) * N);
    for (int i = 2; i < N; i++) a[i] = 1;

    // check if a[i] is a factor for the rest of the array
    for (int i = 2; i < N; i++) {
        if (a[i]) {
            for (int j = i; i*j < N; j++) {
                a[i*j] = 0;
            }
        }
    }

    // print out array
    for (int i = 2; i < N; i++) if (a[i]) printf("%4d ", i);

    return 0;
}
