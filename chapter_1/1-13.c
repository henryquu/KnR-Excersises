#include <stdio.h>


#define WORD 'w'
#define NONWORD 'n'


int main()
{
    int c, i, length;
    int lengths[50];
    char last = WORD;

    for (i = 0; i < 50; i++)
        lengths[i] = 0;

    length = 0;
    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') {
            last = WORD;
            length++;
        }
        else if (last == WORD) {
            last = NONWORD;
            lengths[length]++;
            length = 0;
        }
    }

    printf("count of lengths =\n");

    int max = 0;
    for (i = 1; i < 50; i++)
        if (lengths[i] > max)
            max = lengths[i];
    
    for (i = max; i > 0; i--, printf("\n")) {
        printf(" %4d|", i);
        for (int j = 1; j < 50; j++)
            if (lengths[j] >= i)
                printf(" |");
            else
                printf("  ");
    }

    for (i = 1; i < 75; i++, printf(" -"));
    printf("\n      ");

    for (i = 1; i < 50; i++)
        printf(" %d", i);
}