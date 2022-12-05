#include <stdio.h>

#define swap(t, x, y) \
    t = x; \
    x = y; \
    y = t; \


int main() {
    char i = 'a';
    char c = 'b';
    char k;

    printf("i=%c  c=%c\n", i, c);
    swap(k, i, c);
    printf("i=%c  c=%c\n", i, c);
}