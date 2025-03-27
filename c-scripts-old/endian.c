#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint8_t b;
    uint32_t u;
    u = 0x03040506;
    b = *(uint8_t *)&u; // load first byte of u
    if (b == 3) printf("Big-Endian\n");
    else if (b == 6) printf("Little-Endian\n");
}
