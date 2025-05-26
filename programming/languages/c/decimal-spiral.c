#include <stdio.h>

int value(int size, int row, int col) {
    // this is the quadratic equation which 
    // we will leverage to determine the digit values
    int quad = (size*size + 2* size - 3) / 2;
    // checking the first row
    if (row == 0) return quad - col;
    // checking second row
    else if (row == 1) {
        if (col == size - 1) return quad - col - 1;
    // this is the second-last row
    } else if (row == size - 2) {
        if (col == 0) return quad - 3*size + 2;
        else if (col == size - 1) return quad - 2*size + 3;
    // last row
    } else if (row == size - 1) return quad - 3*size + col + 3;
    // the rest
    else {
        if (col == 0) return quad - 4*size + row + 4;
        else if (col == 1) {
            if (row == 2) return quad - 4*size  + row + 3;
            else return -1;
        } else if (col == size - 1) return quad - size + 1 - row;
        else if (col == size - 2) return -1;
        else return value(size - 4, row - 2, col - 2);
    }
    return 0;
}

int draw(int size, int half) {
    // top half spiral. iterating through rows
    int row, col;
    for (row = 0; row < half; row++) {
        // deals with even rows in the top half
        if (row % 2) {
            // iterating through columns for each row
            for (col = 0; col < size; col++) {
                // logic. even columns are true. checks left / right side. 
                if (!(col % 2) && (col < row - 1 || col >= size - row)) {
                    printf("%d", value(size, row, col) % 10);
                }
                else {
                    putchar('-');
                }
            }
        }
        // deals with the odd rows in the top half
        else {
            // iterating through columns for each row 
            for (col = 0; col < size; col++) {
                // logic.
                if ((col % 2) && (col < row - 1 || col >= size - row)) {
                    putchar('-');
                }
                else {
                    printf("%d", value(size, row, col) % 10);
                }
            }
        }
        printf("\n");
    }
    // bottom half spiral
    for (; row < size; row++) {
        // deals with even rows
        if (row % 2) {
            // check cols. again these are the evens, but for the lower half.
            for (col = 0; col < size; col++) {
                // logic.
                if (!(col % 2) && (col < size - row || col > row)) {
                    printf("%d", value(size, row, col) % 10);
                }
                else {
                    putchar('-');
                }
            }
        }
        // deals with odd rows
        else {
            // check cols. again these are the odds, but for the lower half
            for (col = 0; col < size; col++) {
                // logic.
                if ((col % 2) && (col < size - row || col > row)) {
                    putchar('-');
                }
                else {
                    printf("%d", value(size, row, col) % 10);
                }
            }
        }
        printf("\n");
    } 
    return 0;
}

int main() {
    int spiral_size = 0;
    printf("Enter size: ");
    scanf("%d", &spiral_size);
    int half = (spiral_size / 2) + 1;
    draw(spiral_size, half);
}

// credits: i did use sabine's code to derive the quadratic
// I then used alex's code to understand how to peel back layers
// and then finally used some code from github to structure my layer logic
