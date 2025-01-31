#include "rev.h"

void rev(char *s)
{
    if (*s != '\0') {
        rev(s + 1);
        write(STDOUT_FILENO, s, 1);
    }
}
