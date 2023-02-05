#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 200
int readlines(char *lineptr[], int maxlines);
void write_lines(char *lines[], int count, int n);
int getline(char s[], int lim);

int main(int argc, char **argv){
    int n = 2;
    if (argc == 3 && argv[1][0] == '-' && argv[1][1] == 'n')
        n = atoi(argv[2]);
    
    char *ptr[MAXLEN];
    int ind = 0;
    
    ind = readlines(ptr, MAXLEN);
    write_lines(ptr, ind, n);
}

int readlines(char *lineptr[], int maxlines)
{
    int len, lines_count;
    char *p, line[MAXLEN];

    lines_count = 0;
    while ((len = getline(line, MAXLEN)) > 1 && maxlines-- > 0){
        p = malloc(len + 1);
        line[len - 1] = '\0';
        strcpy(p, line);
        lineptr[lines_count++] = p;
        }

    return lines_count;
}

void write_lines(char *lines[], int count, int n){
    while (count--){
        if (count < n)
            printf("%s\n", lines[count]);
        free(lines[count]);
    }
}

int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    
    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}
