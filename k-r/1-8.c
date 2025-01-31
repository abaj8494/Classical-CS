// counts all the newline, space, tab and character characters from stdin

#include <stdio.h>

int main()
{
    int c;
    int spaces, newlines, characters, tabs;
    spaces = newlines = characters = tabs = 0;

    // counting
    while ((c = getchar()) != EOF) {
        switch (c) {
            case '\n':
                newlines++;
            case '\t':
                tabs++;
            case ' ':
                spaces++;
            default:
                ;
        }
        characters++;
    }

    // printing
    static const char heading[] = "| Newlines | Spaces | Tabs | Characters |";
    for (int i = 0; i < sizeof(heading); i++) printf("-");
    printf("\n%s\n", heading);
    for (int i = 0; i < sizeof(heading); i++) printf("-");
    printf("\n| %8d | %6d | %4d | %10d |\n", newlines, spaces, tabs, characters);
    for (int i = 0; i < sizeof(heading); i++) printf("-");
    printf("\n");
}
