#include <stdio.h>

#define N 100

void squeeze(char[], char[]);


int main() {
    int c, i;
    char s1[N];
    char s2[N];
    
    i = 0;
    while ((c = getchar()) != '\n')
        s1[i++] = c;
    s1[i] = '\0';

    i = 0;
    while ((c = getchar()) != '\n')
        s2[i++] = c;
    s2[i] = '\0';

    squeeze(s1, s2);
    printf("%s\n", s1);
    return 0;
}


void squeeze(char s1[], char s2[]) {
    int i, j, k;

    for (i = 0; s2[i] != '\0'; i++, s1[k] = '\0')
        for (j = k = 0; s1[j] != '\0'; j++)
            if (s1[j] != s2[i])
                s1[k++] = s1[j];
        
}