// a program to display a histogram for the number of characters

#include <stdio.h>

int main()
{
    int arr[26] = {0};
    char alph[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    int c;

    while ((c = getchar()) != EOF) {
        if (c >= 'a' || c <= 'z') arr[c - 97]++;
        else if (c >= 'A' || c <= 'Z') arr[c - 65]++;
    }

    for (int i = 0; i < 26; i++) {
        printf("%c: ", alph[i]);
        for (int j = arr[i]; j > 0; j--) printf("-");
        printf("\n");
    }

}
