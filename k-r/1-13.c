// program that creates a histogram of words from stdin

#include <stdio.h>

int main()
{
    int c;
    int length = 0;
    int arr[20]; 

    for (int i = 0; i < 20; ++i) arr[i] = 0;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n') {
            arr[length]++;
            length=0;
        }
        else length++;
    }

    for (int i = 0; i < 20; i++) {
        printf("%d: ", i);
        for (int j = arr[i]; j > 0; j--) printf("-");
        printf("\n");
    }



}
