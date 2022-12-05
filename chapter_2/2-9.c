/* removing 1 from x changes the rightmost 1bit to 0 and the following 0bits to 1,
   after using & operator, all these numbers are different therefore, switched to 0 */
#include <stdio.h>


int bitcount(unsigned);


int main() {
    printf("%i\n", bitcount(256));
    return 0;
}


int bitcount(unsigned x) {
    int b;
    for (b = 0; x != 0; x &= x - 1, printf("%i\n", x))
        b++;
    return b;
}