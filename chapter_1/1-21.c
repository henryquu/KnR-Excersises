#include <stdio.h>

#define N 7


int main() {
    int c, i, j, spaces;
    i = 0;
    spaces = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            while (c == ' ') {
                c = getchar();
                spaces++;
            }

            for (j = 0; j < spaces;) {
                if ((spaces >= j + 4) && ((N - i % N) >= 4)) {
                    printf("\\t");
                    i += 4;
                    j += 4;
                    while ((i % N) != 0) {
                        putchar(' ');
                        i++;
                        j++;
                    }
                }
                else {
                    i++;
                    j++;
                    putchar(' ');
                }
            }
            spaces = 0;
        }
        putchar(c);
        i++;
        if (c == '\n')
            i = 0;
    }
    
    return 0;
}


