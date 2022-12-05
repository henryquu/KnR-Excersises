#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */


int getop(char []);
void push(double);
double pop(void);
int getline();


/* reverse Polish calculator */
int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push((int) pop() % (int) op2);
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

#define MAXVAL 100 /* maximum depth of val stack */
int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}


#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

/* getline: get line into s, return length */
int getline() {
    int c, i;

    i = 0;
    while (i < BUFSIZE && (c = getchar()) != EOF && c != '\n')
        buf[i++] = c;

    buf[i++] = '\n';
    buf[i] = '\0';
    return i;
}

/* getop: get next character or numeric operand */
int getop(char s[]) {
    int i, c;

    if (buf[bufp] == '\0') {
        if (getline() == 1 && buf[0] == '\n')
            return EOF;
        else
            bufp = 0;
    }
    
    while ((s[0] = c = buf[bufp++]) == ' ' || c == '\t');

    i = 0;
    if (c == '-') {
        s[i] = '-';
        s[++i] = c = buf[bufp++];
        if (!isdigit(c)) {
            bufp--;
            return '-';
        }
    }

    s[2] = '\0';

    if (!isdigit(c) && c != '.')
        return c; /* not a number */

    
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = buf[bufp++]));

    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = buf[bufp++]));

    s[i] = '\0';
    bufp--;
    
    return NUMBER;
}
