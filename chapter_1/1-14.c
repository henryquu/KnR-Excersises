#include <stdio.h>

/*just alphabet counter, non-case sensitive for visual aspect*/

int main() {
    int c, i;
    int frequency[26];

    for (i = 0; i < 26; i++)
        frequency[i] = 0;

    while ((c = getchar()) != EOF)
        if (c >= 'A' && c <= 'Z')
            frequency[c - 'A']++;
        else if (c >= 'a' && c <= 'z')
            frequency[c - 'a']++;

    int max = 0;
    for (i = 0; i < 26; i++)
        if (frequency[i] > max)
            max = frequency[i];
    
    for (i = max; i > 0; i--, printf("\n")) {
        printf(" %4d|", i);
        for (int j = 0; j < 26; j++)
            if (frequency[j] >= i)
                printf(" |");
            else
                printf("  ");
    }

    for (i = 0; i < 30; i++, printf(" -"));
    printf("\n      ");

    for (i = 0; i < 26; i++)
        printf(" %c", i + 'a');
}