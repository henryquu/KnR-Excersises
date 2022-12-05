#include <stdio.h>


double pop(void);
void push(double f);
void print(void);
void duplicate(double[]);
void swap(void);
void clear(void);


int main() {
    print();

    double t[100];
    int i = 0;
    duplicate(t);
    while (t[i] != '\0')
        printf("%0.2f ", t[i++]);
    putchar('\n');

    swap();
    print();

    clear();
    print();
}


#define MAXVAL 100 /* maximum depth of val stack */
int sp = 8; /* next free stack position */
double val[MAXVAL] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0}; /* value stack */

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void print(void) {
    for (int i = 0; i < sp + 1 && val[i] != '\0'; i++)
        printf("%.2f ", val[i]);
    putchar('\n');
}

void duplicate(double t[]) {
    int i = 0;

    if (sp == 0)
        return;

    for (i = 0; val[i] != '\0'; i++)
        t[i] = val[i];

    t[i] = '\0';
}

void swap() {
    double c, p;

    if (sp < 2) 
        return;

    c = pop();
    p = pop();
    push(c);
    push(p);
    // c = val[sp - 2];
    // val[sp - 2] = val[sp - 1];
    // val[sp - 1] = c;
}

void clear() {
    sp = 0;
    val[0] = 0.0;
}