#include <stdio.h>

#define N 100

void fold();


int main() {
    fold();
}

void fold() {
    int c, i, copy, j;
    int last_nblank;
    char string[N];

    last_nblank = 0;
    i = 0;
    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\t')  
            last_nblank = i;
        string[i++] = c;
    
        if (i == N - 1) {
            string[i] = '\0';
            i = 0;
            printf("%s\n", string);
        }
        else if (c == '\n') {
            string[i] = '\0';
            printf("%s", string);
            i = 0;
        }
    }
}

