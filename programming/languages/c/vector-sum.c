#include <stdio.h>

int main() {
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0, z1 = 0, z2 = 0;
    printf("Please enter the values of the first vector (x, y, z): ");
    scanf("%d%d%d", &x1, &y1, &z1);
    printf("Please enter the values of the second vector (x, y, z): ");
    scanf("%d%d%d", &x2, &y2, &z2);
    printf("The resulting sum vector is:\n"
        "x: %d\ny: %d\nz: %d\n", x1 + x2, y1 + y2, z1 + z2);
}
