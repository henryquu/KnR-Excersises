#include <stdio.h>

#define N 100

int any(char[], char[]);


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

    printf("First character at index: %i\n", any(s1, s2));
    return 0;
}


int any(char s1[], char s2[]) {
    int i, j;

    for (i = 0; s1[i] != '\0'; i++)
        for (j = 0; s2[j] != '\0'; j++)
            if (s1[i] == s2[j])
                return i;
    return -1;
}