#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define SIN 'S'
#define EXP 'E'
#define LAST 'L'

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);


/* reverse Polish calculator */
int main() {
    int type, var;
    double op2, last, variable[26];
    char s[MAXOP];

    var = 0;
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
                        if(op2 != 0.0)
                            push(pop() / op2);
                        else
                            printf("error:zero divisor\n");
                        break;
                case '=':
                        pop();
                        if(var >= 'A' && var <= 'Z')
                            variable[var - 'A']=pop();
                        else
                            printf("error: novariablename %c\n", var);
                            break;
                        
                case '\n':
                        last = pop();
                        printf("\t%.8g\n", last);
                        break;
                default:
                        if(type >= 'A' && type <= 'Z')
                            push(variable[type - 'A']);
                        else if (type == 'l')
                            push(last);
                        else
                            printf("error: unknown command %s\n", s);
                        break;
        }
        var = type;
    }
    return 0;
}


#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error:stack full, cant push %g\n", f);
}


double pop(void)
{
    if(sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include<ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i, c;

    while((s[0] = c = getch()) == ' ' || c == '\t');

    s[1] = '\0';
    if(!isdigit(c) && c!='.')
        return c;
    
    i = 0;
    if(isdigit(c))
        while(isdigit(s[++i] = c = getch()));

    if(c=='.')
        while(isdigit(s[++i] = c = getch()));
    
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

/* get a (possibly pushed-back) character */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}