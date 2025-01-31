// input: number of coin tosses (N) and number of times to run the experiment (M)
// output: number of times x heads are the result
//
// time complexity: M*N
// space complexity: N+1

#include <stdio.h>
#include <stdlib.h>

// orchestrates a flip. returns 0 or 1.
int heads() {
    return rand() < RAND_MAX/2;
}

int main(int argc, char *argv[]) {

    // usage checks
    if (argc != 3) {
        fprintf(stderr, "Usage %s <integer>\n", argv[0]);
        return 1;
    }

    // declaring variables
    int i, j, c;

    // converting commandline argument to integers
    int N = atoi(argv[1]), M = atoi(argv[2]);

    // creating frequency array and initialising it with an error check
    int *f = malloc((N+1) * sizeof(int));
    if (f == NULL) {fprintf(stderr, "Insufficient memory.\n"); return 1;}
    for (j = 0; j <= N; j++) f[j] = 0;

    // doing the experiment M times
    for (i = 0; i < M; i++, f[c]++)
        // flips the coin N times.
        // the value of c is used to increment the corresponding frequency histogram index on the next loop
        for (c = 0, j = 0; j <= N; j++)
            if (heads()) c++;

    // printing the histogram
    for (j = 0; j <= N; j++)
    {
        printf("%2d ", j);
        for (i = 0; i < f[j]; i += 10) printf("*");
        printf("\n");

    }

    return 0;

}
