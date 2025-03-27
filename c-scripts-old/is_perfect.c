#include <stdio.h>

int main() {
    int user_num = 0, i = 0, sum = 0;
    printf("Enter number: ");
    scanf("%d", &user_num);
    printf("The factors of %d are:\n", user_num);
    while (1) {
        i++;
        if (user_num%i == 0) {
            printf("%d\n", i);
            sum += i;
        }
        if (i == user_num + 1) break;
    }
    printf("Sum of factors = %d\n", sum);
    if (sum - user_num == user_num) {
        printf("%d is a perfect number\n", user_num);
    }
    else printf("%d is not a perfect number\n", user_num);
}