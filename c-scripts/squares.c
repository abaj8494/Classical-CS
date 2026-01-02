#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int total_squares = 0;
	for (int i = 1; i < atoi(argv[1]); i++) {
		if (i*i > atoi(argv[1])) break;
		printf("%d\n", i*i);
		total_squares++;
	}
	printf("Total Squares: %d\n", total_squares);
	return 0;
}
