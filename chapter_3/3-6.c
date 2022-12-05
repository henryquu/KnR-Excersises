#include <stdio.h>
#include <string.h>

int itoa(int, char[], int);


int main () {
    char s[30];

    itoa(6448, s, 5);
    printf("%s\n", s);
}


int itoa(int n, char s[], int m) {
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

    while (i < m) {
        s[i++] = ' ';
    }

    s[i] = '\0';
    strrev(s);
}