#include <stdio.h>
#include <ctype.h>
#include <math.h>

int getch(void);
void ungetch(int);
float getfloat(float *);

#define SIZE 50
#define BUFSIZE 100
char buf[BUFSIZE]; 
int bufp = 0; 

int main() {
    int n; 
    float array[SIZE];
    float getfloat(float *);

    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++);
    printf("n = %i\n", n);

    for (int i = 0; i < n && array[i] != '\0'; i++)
        printf("%f\n", array[i]);
}


float getfloat(float *pn) {
    int c, sign;
    float fraction = 0.0;

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

    for (*pn = 0.0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;

    if (c != '.') {
        if (c != EOF)
            ungetch(c);
        return c;
    }
    else
        c = getch();

    for (int k = 1; isdigit(c); c = getch(), k++)
        fraction += (c - '0') / pow(10.0, k);

    *pn += sign * fraction;

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