#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {
        char str[25];
        for (int i = 0; argv[1][i] != '\0'; i++) {
                if (argv[1][i] >= 65 && argv[1][i] <= 90) {
                        str[i] = argv[1][i];
                }
                else {
                        str[i] = argv[1][i] - 32;
                }
        }
        str[strlen(str)] += '\n';
        printf("%s\n", str);
        return 0;
}
