#include <stdio.h>

int strend(char *, char *);


int main() {
    char a[] = "asdvwqe2";
    char b[] = "dvwqe2";

    printf("%i\n", strend(a, b));
}

int strend(char *s, char *t) {
    char *startt = t;

    if (!*t)
        return 1;

    while (*s) {
        t = startt;
        while (*t == *s) {
            if (!*t)
                return 1;
            s++;
            t++;
        }
        s++;
    }
    return 0;
}