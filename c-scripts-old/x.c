#include <stdio.h>

int main() {
    int size = 0, row = 1, col = 1;
    printf("Enter size: ");
    scanf("%d", &size);
    while (!(row > size)) {
        while (!(col > size)) {
            if (col == row ) printf("*");
            else if (col == size + 1 - row) printf("*");
            else printf("-");
            col++;
        }
        printf("\n");
        col = 1;
        row++; 
    }

}