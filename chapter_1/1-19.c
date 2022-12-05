#include <stdio.h>


#define MAXLINE 1000


int getline(char line[], int maxline);
void reverse(char c[], int i);



int main() {
    int len;
    char line[MAXLINE];

    while ((len  = getline(line, MAXLINE)) > 0){
        reverse(line, len - 1);
        printf("%s", line);
    }

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
void reverse(char s[], int len) {
    int i, j, c;
    for (j = 0, i = len - 1; i > ((len - 1) / 2); i--, j++) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}