#include <stdio.h>

int main() {
    int spiral_size = 0, row, col;
    printf("Enter size: ");
    scanf("%d", &spiral_size);
    int half = (spiral_size / 2) + 1;
    // top of spiral 
    // iterating through rows
    for (row = 0; row < half; row++) {
        // deals with even rows
        if (row % 2) {
            // iterating through columns for each row
            for (col = 0; col < spiral_size; col++) {
                // logic. even columns are true. checks left / right side. 
                if (!(col % 2) && (col < row - 1 || col >= spiral_size - row)) {
                    putchar('*');
                }
                else {
                    putchar('-');
                }
            }
        }
        // deals with odd rows
        else {
            // iterating through columns for each row 
            for (col = 0; col < spiral_size; col++) {
                // logic.
                if ((col % 2) && (col < row - 1 || col >= spiral_size - row)) {
                    putchar('-');
                }
                else {
                    putchar('*');
                }
            }
        }
        printf("\n");
    }
    // bottom of spiral
    for (; row < spiral_size; row++) {
        // deals with even rows
        if (row % 2) {
            // check cols
            for (col = 0; col < spiral_size; col++) {
                // logic.
                if (!(col % 2) && (col < spiral_size - row || col > row)) {
                    putchar('*');
                }
                else {
                    putchar('-');
                }
            }
        }
        // deals with odd rows
        else {
            // check cols
            for (col = 0; col < spiral_size; col++) {
                // logic.
                if ((col % 2) && (col < spiral_size - row || col > row)) {
                    putchar('-');
                }
                else {
                    putchar('*');
                }
            }
        }
        printf("\n");
    } 
    return 0;
}

// did appropriate second operand within the if conditional
// on line 16 from stack