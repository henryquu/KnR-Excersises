#include <stdio.h>

#define N 1000

int escape(char[], char[]);
int unescape(char[], char[]);

int main() {
    int c, i;
    char s[N], t[N];

    i = 0;
    while ((c = getchar()) != EOF)
        t[i++] = c;
    t[i] = '\0';

    escape(s, t);
    printf("%s\n", s);
}

int escape(char s[], char t[]) {
    int c, i, j;

    i = j = 0;
    while ((c = t[i++]) != '\0') {
        switch (c) {
            case '\t':
                s[j] = '\\';
                s[++j] = 't';
                break;
            case '\n':
                s[j] = '\\';
                s[++j] = 'n';
                break;
            default:
                s[j] = c;
        }
        j++;
    }
    s[j] = '\0';
}

int unescape(char s[], char t[]) {
    int c, i, j;

    i = j = 0;
    while ((c = t[i++]) != '\0') {
        switch (c) {
            case '\\': {
                switch (t[i]) {
                    case 't':
                        s[j] = '\t';
                        break;
                    case 'n':
                        s[j] = '\n';
                        break;
                    default:
                        s[j] = c;
                        s[j++] = t[i];
                        break;
                }
                i++;
                break; 
            }
            default:
                s[j] = c;
                break;
        }
        j++;
    }
    s[j] = '\0';
}