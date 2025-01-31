#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 21000

void print_canvas(int *canvas)
{
	for (int i = 0; canvas[i] != '\0'; i++) {
		printf("%d ", i);
		int j = canvas[i];
		int count = 0;
		for (; j == canvas[i]; i++, count++) {
			;
		}
		printf("%d %d \n", count, j);
	}
	return;
}	

int main(void) {
	int canvas[MAX_SIZE] = {0};
	int pos, paint, colour; 
	while (scanf("%d %d %d", &pos, &paint, &colour) != EOF) {
		pos--;
		for (int i = pos; paint > 0; paint--) {
			canvas[i++] = colour;
		}
		//for (int i = 0; canvas[i] != '\0'; i++) {
		//	printf("%d", canvas[i]);
		//}
		//printf("\n");
	}
	print_canvas(canvas);
	return 0;
}
