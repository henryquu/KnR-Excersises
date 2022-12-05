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


unsigned rightrot(unsigned, int);


int main() {
    int rotation;
    unsigned x = 8;
    int n = 1;

    printf("x   = "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(x));

    rotation = rightrot(x, n);
    printf("set = "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(rotation));
    printf("integer = %i", rotation);

    return 0;
} 

unsigned rightrot(unsigned x, int n) {
    return (x & ~(~0 << n)) << sizeof(x) | (x >> n);
}