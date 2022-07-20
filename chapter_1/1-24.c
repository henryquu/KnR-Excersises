#include <stdio.h>

#define N 10000

int check_comment(int j, int i, int code[]);


int main() {
    int c, j;
    int parentheses = 0, brackets = 0, braces = 0;
    int single_quotes = 0, double_quotes = 0;
    int code[N];

    int i = 0;

    while ((c = getchar()) != EOF)
        code[i++] = c;
    code[i] = '\0';

    for (j = 0; j < i; j++) {
        c = code[j];
        if (c == '/' && code[j + 1] == '*') {
            int newj = check_comment(j, i, code);
            if (newj == -1)
                return -1;
            j = newj;
            continue;
        }
        switch (c) {
            case '"':
                double_quotes++;
                break;
            case '\'':
                single_quotes++;
                break;
            case '(':
                parentheses++;
                break;
            case ')':
                parentheses--;
                break;
            case '[':
                brackets++;
                break;
            case ']':
                brackets--;
                break;
            case '{':
                braces++;
                break;
            case '}':
                braces--;
                break;
            case '\\':
                if (
                j == i || (
                code[j + 1] != 'a' && code[j + 1] != 'b' && code[j + 1] != 'f' && code[j + 1] != 'n' && code[j + 1] != 'r' &&
                code[j + 1] != 't' && code[j + 1] != 'v' && code[j + 1] != '\'' && code[j + 1] != '\\' && code[j + 1] != '"' &&
                code[j + 1] != '?' && code[j + 1] != 'n' && code[j + 1] != 'x' && code[j + 1] != '0'))
                    printf("Invalid escape sequence at %d - %c%c\n", j++, c, code[j + 1]);
        }
    }
    if ((single_quotes % 2) != 0)
        printf("Not matched single quotes\n");
    if ((double_quotes % 2) != 0)
        printf("Not matched double quotes\n");

    if (parentheses > 0)
        printf("Not matched starting parentheses %d\n", parentheses);
    else if (parentheses < 0)
        printf("Not matched ending parentheses %d\n", -parentheses);

    if (brackets > 0)
        printf("Not matched starting brackets %d\n", brackets);
    else if (brackets < 0)
        printf("Not matched ending brackets %d\n", -brackets);

    if (braces > 0)
        printf("Not matched starting braces %d\n", braces);
    else if (braces < 0)
        printf("Not matched ending braces %d\n", -braces);
    return 0;
}


int check_comment(int j, int i, int code[]) {
    int c;
    int starting = j;
    while (j < i) {
        c = code[++j];
        if (c == '*' && code[j + 1] == '/')
            return ++j;
    }
    printf("Unfinished comment starting at %d\n", starting);
    return -1;
}