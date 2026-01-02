#include <stdio.h>
#include <string.h>

int main() {
	char str[1024];
	int i = 0, ch;
	printf("Input word: ");
	while ((ch = getchar())) {
		if (ch == '\n' || ch == '\0') {
			break;
		}
		str[i++] = ch;
	}
	printf("\nWord square is:\n");
	for (int j = i; j > 0; j--) {
		for (int k = 0; k < i; k++) {
			putchar(str[k]);
		}
		putchar('\n');
	}
}
