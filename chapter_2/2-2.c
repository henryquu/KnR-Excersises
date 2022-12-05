#include <stdio.h>

int main() {
    int lim = 50;
    int c, i;
    char s[50];

    for (i=0; i < lim - 1; ++i) {
        c = getchar();
        if (c == EOF) break;
        if (c == '\n') break;
        s[i] = c;
    }

    s[lim] = '\0';

    i = 0;
    while (s[i] != '\0')
        putchar(s[i++]);

    return 0;
}