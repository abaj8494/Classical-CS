/* removes trailing blanks and tabs from each line of input */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXLINE 1000

int my_getline(char line[]);
void trim(char line[]);
void copy(char out[], char line[]);

int main(void)
{
    char line[MAXLINE];
    char out[MAXLINE];
    int len;

    while ((len = my_getline(line)) > 0) {
        trim(line);
        copy(out, line);
        printf("%s", out);
    } 
}

int my_getline(char s[]) 
{
    int c, i;
    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) 
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void trim(char line[])
{
    int start = 0;
    int end = strlen(line) - 1;
    while ((end >= start) && isspace((unsigned char) line[end])) end--;
    line[end+1] = '\n';
    line[end+2] = '\0';
}

void copy(char to[], char from[]) 
{
    int i = 0;
    while ((to[i] = from[i]) != '\0') ++i;
}
