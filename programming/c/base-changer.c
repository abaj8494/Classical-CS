#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define N_BITS 16

// Function declarations
void change_base(int base, int user_num);
char *convert_to_binary(int16_t value);

// Convert number to any base (2-36)
void change_base(int base, int user_num)
{
    int i = 0;
    int j = 0;
    int raised, ceiling, floored;
    int length = snprintf(NULL, 0, "%d", base);
    char base_name[20] = "";
    char output[55] = "";
    char floored_str[32] = "";
    char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    for (raised = pow(base,i); user_num % raised < user_num; i++) {
        raised = pow(base, i);
        ceiling = i - 1;
    }
    
    for (j = ceiling; j > -1; j--) {
        floored = floor(user_num / pow(base, j));
        user_num -= floored*pow(base, j); 
        sprintf(floored_str, "%d", floored);
        if (floored > 9) {
            sprintf(floored_str, "%c", alphabet[floored - 10]);
        }    
        strcat(output, floored_str);
    }
    
    if (base == 2) strcpy(base_name, "Binary");
    else if (base == 16) strcpy(base_name, "Hexadecimal");
    else snprintf(base_name, length + 1, "%d", base);
    
    printf("<items><item uid=\"%s\" arg=\"%s\"><title>%s</title><subtitle></subtitle><icon>icon.png</icon></item></items>", base_name, output, output);
}

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
    printf("Usage: %s <base> <number>\n", "base_changer");
    printf("\nBase must be between 2 and 36\n");
    printf("Number must be between 0 and 2147483647\n");
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        print_usage();
        return 1;
    }
    
    int base = atoi(argv[1]);
    int user_num = atoi(argv[2]);
    
    if (!(base >= 2 && base <= 36)) {
        print_usage();
        return 2;
    }
    if (user_num > 2147483647) {
        print_usage();
        return 2;
    }
    
    change_base(base, user_num);
    return 0;
}
