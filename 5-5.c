#include <stdio.h>

void strncat2(char *, char *, int);
void strncpy2(char *, char *, int);
int strncmp2(char *, char *, int);

int main() {
    char a[100] = "asd";
    char b[100] = "asdasd";
    int n = 3;

    printf("Comparing %i characters between %s and %s: %i\n", n, a, b, strncmp2(a, b, n));
}

void strncat2(char *s, char *t, int n) {
    while (*s)
        s++;

    while (n-- > 0 && (*s++ = *t++) != '\0');

    *s = '\0';
}

void strncpy2(char *s, char *t, int n) {
    while (n-- > 0 && (*s++ = *t++) != '\0');
    *s = '\0';
}

int strncmp2(char *s, char *t, int n) {
    while (n-- > 0 && *t != '\0')
        if (*s++ != *t++)
            return 0;
    return 1;
}