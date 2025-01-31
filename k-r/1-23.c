/* removes all comments from a C program */

#include <stdio.h>
#include <stdbool.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
    int len;
    int max;
    int skip;
    char line[MAXLINE];
    char out[MAXLINE];
    bool comment = false;

    max = 0;
    skip = 0;
    while ((len = my_getline(line, MAXLINE)) > 0) {
        copy(out, line);
        printf("%s", out);
    }
    return 0;
}

int my_getline(char s[], int lim)
{
    int c, i, skip = 0;
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        if (c == '/' && skip == 0) {
            skip++;
            s[i] = c;
        }
        else if (c == '/' && skip == 1) {
            s[i-1] = '\n';
            while ((c = getchar()) != '\n');
            skip = 0;
        }
        else if (c == '*' && skip == 1) {
            while ((c = getchar()) != '*' && (c = getchar()) != '/');
            skip = 0;
        }
        else {
            s[i] = c;
            skip = 0;
        }
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0') ++i;
}
