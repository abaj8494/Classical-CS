#include <stdio.h>

int main(void) {
    int boxes_num = 0, sides, row = 0, col = 0, i, j;
    printf("How many boxes: ");
    scanf("%d", &boxes_num);
    sides = 3+4*(boxes_num - 1);
    boxes_num = (sides + 1) / 2;
    while (row < sides) {
        while (col < sides) { 
            //do not fully understand the following 2 lines of logic.
            i = (row >= boxes_num) ? sides - row - 1: row;
            j = (col >= boxes_num) ? sides - col - 1 : col;
            if ((boxes_num - ((i < j) ? i : j))%2 == 0) printf("*");
            else printf("-");
            col++;
        }
        col = 0;
        row++;
        putchar ('\n');
    }
    return 0;
}

// this one was difficult. had to appropriate a few lines from stack
