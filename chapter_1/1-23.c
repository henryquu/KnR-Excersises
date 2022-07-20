#include <stdio.h>

#define N 10000

int main() {
    int c, j;
    char code[N];

    int i = 0;
    while ((c = getchar()) != EOF)
        code[i++] = c;
    code[i] = '\0';

    for (j = 0; j < i; j++) {
        c = code[j];
        if (c == '/' && code[j + 1] == '*') {
            j++;
            while (j < i) {
                c = code[++j];
                if (c == '*' && code[j + 1] == '/') {
                    j += 2;
                    break;
                }
            }
            c = code[j];
        }

        putchar(c);
    }
    return 0;
}
