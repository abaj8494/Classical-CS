#include <stdio.h>
#include <stdlib.h>

char *int_to_bits(int i)
{
    char *bit_string = malloc(sizeof(int) * 8);

    for (int n = sizeof(i) * 8, j = 0; j < 32; n--, j++) {
        bit_string[j] = '0' + ((i >> n) & 1);
    }
    return bit_string;
}

char *uint_to_bits(unsigned int i)
{
    char *bit_string = malloc(sizeof(unsigned int) * 8);

    for (int n = sizeof(i) * 8, j = 0; j < 32; n--, j++) {
        bit_string[j] = '0' + ((i >> n) & 1);
    }

    return bit_string;
    
}

int main(int argc, char *argv[])
{
    if (argc > 1 && argc != 2) {
        fprintf(stderr, "Usage: %s [-v]\n", argv[0]);
        return 1;
    }

    printf("Signed Representations\n"
            " 1: %s\n"
            " 2: %s\n"
            " 3: %s\n"
            " 4: %s\n"
            "16: %s\n"
            "32: %s\n", 
            int_to_bits(1), int_to_bits(2), int_to_bits(3), int_to_bits(4),
            int_to_bits(16), int_to_bits(32));
    printf("Unsigned Representations\n"
            " 1: %s\n"
            " 2: %s\n"
            " 3: %s\n"
            " 4: %s\n"
            "16: %s\n"
            "32: %s\n", 
            uint_to_bits(1), uint_to_bits(2), uint_to_bits(3), uint_to_bits(4),
            uint_to_bits(16), uint_to_bits(32));

    return 0;

}
