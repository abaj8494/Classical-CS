#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char change(base, user_num)
{
    int i = 0;
    int j = 0;
    int raised, ceiling, floored;
    int length = snprintf( NULL, 0, "%d", base );
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
    else snprintf(base_name, length + 1, "%d", base );
    printf("<items><item uid=\"%s\" arg=\"%s\"><title>%s</title><subtitle></subtitle><icon>icon.png</icon></item></items>", base_name, output, output);
    return 0;
}


int main(int argc, char *argv[])
{
    if (!(atoi(argv[1]) >= 2 && atoi(argv[1]) <= 36))
        return 2;
    if (atoi(argv[2]) > 2147483647)
        return 2;
    int base = atoi(argv[1]);
    int user_num = atoi(argv[2]);
    change(base, user_num);
    return 0;

} 

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#define N_BITS 16

char *sixteen_out(int16_t value);

int main(int argc, char *argv[]) {
    for (int arg = 1; arg < argc; arg++) {
        long l = strtol(argv[arg], NULL, 0);
        assert(l >= INT16_MIN && l <= INT16_MAX);
        int16_t value = l;

        char *bits = sixteen_out(value);
		printf("<items><item uid=\"%s\" arg=\"%s\"><title>%s</title><subtitle></subtitle><icon>icon.png</icon></item></items>", bits, bits, bits);

        free(bits);
    }

    return 0;
}

// given a signed 16 bit integer
// return a null-terminated string of 16 binary digits ('1' and '0')
// storage for string is allocated using malloc
char *sixteen_out(int16_t value) {
    char *buffer = malloc((N_BITS + 1) * sizeof(char));
    assert(buffer);

    for (int i = 0; i < N_BITS; i++) {
        int16_t bit_mask = 1 << (N_BITS - i - 1);
        if (value & bit_mask) {
            buffer[i] = '1';
        } else {
            buffer[i] = '0';
        }
    }

    buffer[N_BITS] = '\0';

    return buffer;
}
