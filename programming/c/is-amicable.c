#include <unistd.h>
#include <stdio.h>

int len(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}

int atoi(char *str)
{
    int res = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i]> '9' || str[i]<'0')
            return -1;
        res = res*10 + str[i] - '0';
    }
    return res;
}

int amicable(int a, int b)
{
    int sum = 0;
    for (int fac = 1; fac < b; fac++) { // note: you cannot modulo by 0
        if (!(b % fac)) sum += fac;     // -> floating point exception
    }
    return (a == sum) ? 1 : 0;
}

int main(int argc, char *argv[])
{
    char usage[50];
    sprintf(usage,"Usage: %s <int> <int>\n", argv[0]);
    if (argc != 3) {write(2, usage, len(usage)); return 1;}

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    write(1, amicable(a, b) ? "true\n" : "false\n", 6);
}
