#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getint(int *);

#define SIZE 50
#define BUFSIZE 100
char buf[BUFSIZE]; 
int bufp = 0; 

int main() {
    int n, array[SIZE], getint(int *);

    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++);
    printf("n = %i\n", n);

    for (int i = 0; i < n && array[i] != '\0'; i++)
        printf("%d\n", array[i]);
    printf("%s\n", buf);
}


int getint(int *pn) {
    int c, sign;

    while (isspace(c = getch()));

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return EOF;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
        if (!isdigit(c)) {
            ungetch(c);
            ungetch((c == 1) ? '+' : '-');
            return EOF;
        }
    }

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    *pn *= sign;
    if (c != EOF)
        ungetch(c);

    return c;
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}