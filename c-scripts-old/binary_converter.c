#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define N_BITS 16

// Convert number to 16-bit binary
char *convert_to_binary(int16_t value) {
    char *buffer = malloc((N_BITS + 1) * sizeof(char));
    if (!buffer) {
        return NULL;
    }

    for (int i = 0; i < N_BITS; i++) {
        int16_t bit_mask = 1 << (N_BITS - i - 1);
        buffer[i] = (value & bit_mask) ? '1' : '0';
    }

    buffer[N_BITS] = '\0';
    return buffer;
}

void print_usage() {
    printf("Usage: %s <number> [number2 ...]\n", "binary_converter");
    printf("\nConvert numbers to 16-bit binary representation\n");
    printf("Each number must be between -32768 and 32767\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage();
        return 1;
    }

    for (int arg = 1; arg < argc; arg++) {
        long l = strtol(argv[arg], NULL, 0);
        if (l < INT16_MIN || l > INT16_MAX) {
            print_usage();
            return 2;
        }
        int16_t value = l;

        char *bits = convert_to_binary(value);
        if (!bits) {
            return 3;
        }
        
        printf("<items><item uid=\"%s\" arg=\"%s\"><title>%s</title><subtitle></subtitle><icon>icon.png</icon></item></items>", bits, bits, bits);
        free(bits);
    }

    return 0;
} 