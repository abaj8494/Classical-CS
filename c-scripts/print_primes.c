#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int factors = 0, total_primes = 0;
	for (int i = 1; i <= atoi(argv[1]); i++) {
		factors = 0;
		for (int j = 1; j <= i; j++) {
			if (i % j == 0) factors++;
		}
		if (factors == 2) {
			total_primes++;
			printf("%d\n", i);
		}
	}
	printf("Total Primes: %d\n", total_primes);
	return 0;
}
