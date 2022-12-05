#include <stdio.h>
#include <string.h>

int itob(int, char[], int);


int main() {
    char s[100];

    itob(145, s, 2);
    printf("%s\n", s);
}


int itob(int n, char s[], int b) {
    switch (b) {
        case 16:
            sprintf(s, "0x%x", n);
            break;
        case 8:
            sprintf(s, "0%o", n);
            break;
        case 2: {
            int i = 0;
            while (n > 0) {
                s[i++] = (n & 1) + '0';
                n >>= 1;
            }
            s[i] = '\0';

            strrev(s);
            break;
        }
        default:
            sprintf(s, "%i", n);
            break;
    }
}