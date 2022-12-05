#include <stdio.h>

void strcats(char *, char *);

int main() {
    char a[100] = "asdwq";
    char b[100] = "asdasd";

    strcats(a, b);
    printf("%s\n", a);
}

void strcats(char *s, char *t) {
    while (*s)
        s++;

    while ((*s++ = *t++) != '\0');

    *s = '\0';
}