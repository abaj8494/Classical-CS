// program to print the bits of an integer
// arg 1 u for unsigned, s for signed
// arg 2 byte size
// arg 3 integer
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

void print_bits_unsigned(uint8_t b, int i)
{
    int count = b * sizeof(i);
    while (count > 0) {
        printf("%d", (i >> --count) & 1);
    }
}

void print_bits_signed(uint8_t b, int i)
{
    int count = b * sizeof(i);
    while (count > 0) {
        printf("%d", (i >> count--) & 1);
    }
    printf("signed");
}

int main(int argc, char *argv[])
{
    if (argc != 4) {fprintf(stderr, "Usage %s <u/s> <byte size> <int>\n",argv[0]); return 1;}

    uint8_t bytes = atoi(argv[1]);
    int integer = atoi(argv[2]); //may need to change this data type
    if (argv[1][0] == 'u') {
        print_bits_unsigned(bytes, integer);
    } else if (argv[1][0] == 's') {
        print_bits_signed(bytes, integer);
    } else {
        fprintf(stderr, "Usage %s <u/s> <byte size> <int>\n", argv[0]);
        return 1;
    }
}
