#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 100

int getline(char *, int);
int atoi(char *);
void itoa(int, char *);
void reverse(char *);
int getop(char *);
int strindex(char *, char *);

int main() {
    char s[MAXLINE];

    printf("%c \n", getop(s));
}


int getline(char *s, int lim) {
    int c;
    char* start = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;

    if (c == '\n')
        *s++ = c;

    *s = '\0';

    return s - start - 1;
}

int atoi(char *s) {
    int n = 0;

    while (*s >= '0' && *s <= '9')
        n = 10 * n + (*s++ - '0');
    
    return n;
}

void itoa(int n, char *s) {
    int i, sign;
    char* start = s;

    sign = (n > 0)? 1: -1;

    i = 0;
    do { 
        *s++ = sign * (n % 10) + '0';
    } while (n /= 10);

    if (sign < 0)
        *s++ = '-';

    *s = '\0';
    strrev(start);
}

void reverse(char *s) {
    int c, i, j;
    char* end = s + strlen(s) - 1;

    while (s < end) {
        c = *s;
        *s++ = *end;
        *end-- = c;
    }
}

int strindex(char *s, char *t) {
    int i, j;
    char* start_t = t;

    for (i = 0; *(s + i) != '\0'; i++) {
        for (j = i, t = start_t; *t != '\0' && *(s + j) == *t; j++, t++);
    
        if (t != start_t && *t == '\0')
            return i;
    }
    return -1;
}

int getop(char *s) {
    int c;
    static int buf = EOF;

    if (buf != EOF && buf != ' ' && buf != '\t') {
        *s = c = buf;
        buf = EOF;
    }
    else
        while ((*s = c = getchar()) == ' ' || c == '\t');

    if (c == '-') {
        *s = '-';
        *(++s) = c = getchar();
        if (!isdigit(c)) {
            buf = c;
            *s = '\0';
            return '-';
        }
    }

    *(s + 2) = '\0';

    if (!isdigit(c) && c != '.')
        return c; /* not a number */

    
    if (isdigit(c)) /* collect integer part */
        while (isdigit(*(++s) = c = getchar()));

    if (c == '.') /* collect fraction part */
        while (isdigit(*(++s) = c = getchar()));

    *s = '\0';

    if (c != EOF)
        buf = c;

    return '0';
}