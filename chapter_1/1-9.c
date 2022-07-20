#include <stdio.h>

int main() {
    int c;
    
    while ((c = getchar()) != EOF) {
        putchar(c);
        if (c == ' ' || c == '\t'){
            while (c  == ' ' || c == '\t')
                c = getchar();
            putchar(c);
        }
    }
}
