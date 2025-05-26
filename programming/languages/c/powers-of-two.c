#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

int main(int argc, char **argv)
{
    if (argc != 2) {fprintf(stderr, "Usage %s <power>\n", argv[0]); return 1;}
    uint8_t loop = atoi(argv[1]);
    
    for (int i = 0; i < loop; i++) {
        printf("%20.0f\n", pow(2, i));
    }
    
}
