#include <stdio.h>
#include <string.h>

void itoa(int, char[]);


int main() {
    char s[30];
    itoa(-2147483648, s);
    printf("%s\n", s);

    itoa(2147483647, s);
    printf("%s\n", s);

    itoa(-1, s);
    printf("%s\n", s);

    itoa(0, s);
    printf("%s\n", s);

    itoa(1, s);
    printf("%s\n", s);
}


void itoa(int n, char s[]) {
    static int i = 0;
    int sign = (n < 0)? -1: 1;
    
    s[i++] = sign * (n % 10) + '0';
    

    if (n / 10)
        itoa(n / 10, s);
    else {
        if (n < 0) {
            s[i] = '-';
            s[i + 1] = '\0';
        }
        else
            s[i] = '\0';
    }

    i--;
    if (i == 0)
        strrev(s);
}