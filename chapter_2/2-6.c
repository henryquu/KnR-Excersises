#include <stdio.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 


unsigned setbits(unsigned, int, int, unsigned);

int main() {
    unsigned x = 218;
    int p = 3;
    int n = 3;
    unsigned y = 170;

    printf("x   = "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(x));
    printf("y   = "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(y));
    printf("set = "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(setbits(x, p, n, y)));
    printf("integer = %i", setbits(x, p, n, y));

    return 0;
}


unsigned setbits(unsigned x, int p, int n, unsigned y) {
    x = x & ~((x >> (p+1-n)) & ~(~0 << n) << p);
    y = (y & ~(~0 << n)) << p;

    return x | y;
}
