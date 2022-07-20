#include <stdio.h>

#define WORD 'w'
#define NONWORD 'n'

int main()
{
    int c;
    char last = WORD;

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') {
            putchar(c);
            last = WORD;
        }
        else if (last == WORD) {
            printf("\n");
            last = NONWORD;
        }
    }
}