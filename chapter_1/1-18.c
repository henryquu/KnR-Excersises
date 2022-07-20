#include <stdio.h>


#define MAXLINE 1000 /* maximum input line length */


int getline(char line[], int maxline);
int remove_trail(char c[], int i);
/* print the longest input line */


int main() {
    int len, current; /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len  = getline(line, MAXLINE)) > 0)
        if (remove_trail(line, len - 1) > 0)
            printf("%s", line);

    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[],int lim) {
    int c, i;

    for (i=0; i < lim - 1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
int remove_trail(char s[], int i) {
    for (--i; i > 0 && ((s[i] == ' ') || (s[i]) == '\t'); i--);

    if (i > 0) {
        s[++i] = '\n';
        s[++i] = '\0';
    }
    printf("%d", i);
    return i;
}