#include <stdio.h>
#include <limits.h>
#include <float.h>


int main() {
    printf("Singed:\n");
    printf("char: %d - %d\n", -((unsigned char) ~0 >> 1) - 1, (unsigned char) ~0 >> 1);
    printf("short: %d - %d\n", -((unsigned short) ~0 >> 1) - 1, (unsigned short) ~0 >> 1);
    printf("int: %d - %d\n", INT_MIN, INT_MAX);
    printf("long: %ld - %ld\n", LONG_MIN, LONG_MAX);

    printf("\nUnsinged:\n");
    printf("char: 0 - %d\n", (unsigned char) ~0);
    printf("short: 0 - %d\n", (unsigned short) ~0);
    printf("int: 0 - %lu\n", UINT_MAX);
    printf("long: 0 - %lu\n", ULONG_MAX);

    printf("\nFloating point types:\n");
    printf("float: %g - %g\n", FLT_MIN, FLT_MAX);
    printf("float: %g - %g\n", DBL_MIN, DBL_MAX);
    printf("long double: %g - %g\n", LDBL_MIN, LDBL_MAX);
    return 0;
}
