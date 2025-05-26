#include <stdio.h>

int main() {
    int height = 0, length = 0, row = 1, col = 1;
    printf("Please enter the height of the sawtooth: ");
    scanf("%d", &height);
    printf("Please enter the length of the sawtooth: ");
    scanf("%d", &length);
    while (!(row == height + 1)) {
        while (!(col == length + 1)) {
            if ((col - 1)%height == 0) printf("*"); 
            else if ((col - 1)%height == (row - 1)) printf("*");
            else printf(" ");
            col++;
        }
        printf("\n");
        col = 1;
        row++;
    }
}
