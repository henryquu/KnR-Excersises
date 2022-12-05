#include <stdio.h>

#define N 5


int main() {
    int c, i;

    i = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') 
            while ((i % N) != 0) {
                putchar(' ');
                i++;
            } 
        else {
            putchar(c);
            i++;
            if (c == '\n')
                i = 0;
        }
    }
    
    return 0;
}


