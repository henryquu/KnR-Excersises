#include <stdio.h>


#define N 1000
int expand(char[], char[]);

int main(void) {
    int c, i;
    char s1[N], s2[N];

    i = 0;
    while ((c = getchar()) != EOF)
        s1[i++] = c;
    s1[i] = '\0';

    expand(s1, s2);
    printf("%s\n", s2);
}

int expand(char s1[], char s2[]) {
    int c;
    int i = 0;
    int j = 0;

    while ((c = s1[i]) != '\0') {
        if (c == '-' && i > 0 && s1[i + 1] != '\0') {
            if (s1[i + 1] >= 'A' && s1[i + 1] <= 'Z' && s1[i - 1] >= 'A' && s1[i - 1] <= 'Z') {
                c = s1[i - 1] + 1;
                while (c <= s1[i + 1])
                    s2[j++] = c++;
                i++;
            }
            else if (s1[i + 1] >= 'a' && s1[i + 1] <= 'z' && s1[i - 1] >= 'a' && s1[i - 1] <= 'z') {
                c = s1[i - 1] + 1;
                while (c <= s1[i + 1])
                    s2[j++] = c++;
                i++;
            }
            else if (s1[i + 1] >= '0' && s1[i + 1] <= '9' && s1[i - 1] >= '0' && s1[i - 1] <= '9') {
                c = s1[i - 1] + 1;
                while (c <= s1[i + 1])
                    s2[j++] = c++;
                i++;
            }
            else
                s2[j++] = '-';
        }
        else {
            s2[j++] = s1[i];
        }
    i++;
    }
    s2[j] = '\0';
}