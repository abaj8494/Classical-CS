#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

void print_bits_unsigned(uint8_t bytes, int integer)
{
    int bits = bytes * 8;
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (integer >> i) & 1);
    }
    printf("\n");
}

void print_bits_signed(uint8_t bytes, int integer)
{
    int bits = bytes * 8;
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (integer >> i) & 1);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    if (argc != 4) {
        fprintf(stderr, "Usage %s <u/s> <byte size> <int>\n", argv[0]);
        return 1;
    }

    char sign_type = argv[1][0];
    uint8_t bytes = atoi(argv[2]);
    int integer = atoi(argv[3]);

    if (sign_type == 'u') {
        print_bits_unsigned(bytes, integer);
    } else if (sign_type == 's') {
        print_bits_signed(bytes, integer);
    } else {
        fprintf(stderr, "Usage %s <u/s> <byte size> <int>\n", argv[0]);
        return 1;
    }

    return 0;
}
