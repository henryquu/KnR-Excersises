#include <stdio.h>
#include <string.h>

int itoa(int, char[]);

/* absolute value of the largest negative number is 1 higher than the largest positive number */

int main () {
    char s[30];

    itoa(-2147483648, s);
    printf("%s\n", s);
}


int itoa(int n, char s[]) {
    int i, sign;

    sign = 1;
    if (n < 0)
        sign = -1;

    i = 0;
    do { 
        s[i++] = sign*(n % 10) + '0';
    } while ((n /= 10) != 0);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    strrev(s);
}