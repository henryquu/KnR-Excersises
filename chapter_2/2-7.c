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


unsigned invert(unsigned, int, int);


int main() {
    int inversion;
    unsigned x = 16;
    int p = 2;
    int n = 3;

    printf("x   = "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(x));

    inversion = invert(x, p, n);
    printf("set = "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(inversion));
    printf("integer = %i", inversion);

    return 0;
} 

unsigned invert(unsigned x, int p, int n) {
    return x ^ (~(~0 << n) << p);
}