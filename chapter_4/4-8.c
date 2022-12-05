#include <stdio.h>


int getch(void);
void ungetch(int);


int main() {
    printf("%c\n", getch());
    ungetch('a');
    ungetch('b');
    printf("%c\n", getch());
    printf("%c\n", getch());
}


int buf = EOF; 

int getch(void) {
    if (buf == EOF)
        return getchar();
    int c = buf;
    buf = EOF;
    return c;
}

void ungetch(int c) {
    if (buf != EOF)
        printf("ungetch: too many characters\n");
    else
        buf = c;
}
