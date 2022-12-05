#include <stdio.h>
#include <math.h>

void ungetch(int c);
void ungets(char[]);

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int main() {
    ungets("qwrlpmpwc");
    printf("%s\n", buf);
}

void ungets(char s[]) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (bufp >= BUFSIZE) {
            printf("ungets: string too long, stopped adding at s[%i] = %c\n", i, s[i]);
            return;
        }
        buf[bufp++] = s[i];
    }
}
