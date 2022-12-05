#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);


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

int getop(char s[]) {
    int i, c;
    static int buf = EOF;

    if (buf != EOF && buf != ' ' && buf != '\t') {
        s[0] = c = buf;
        buf = EOF;
    }
    else
        while ((s[0] = c = getchar()) == ' ' || c == '\t');

    i = 0;
    if (c == '-') {
        s[i] = '-';
        s[++i] = c = getchar();
        if (!isdigit(c)) {
            buf = c;
            return '-';
        }
    }

    s[2] = '\0';

    if (!isdigit(c) && c != '.')
        return c; /* not a number */

    
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getchar()));

    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getchar()));

    s[i] = '\0';

    if (c != EOF)
        buf = c;
    return NUMBER;
}
