#include <stdio.h>
#include <ctype.h>
#include "../utils.c"

int getword(char *word, int lim){
    int c, prev;
    char *w = word;

    while (isspace(c = getch()))
    ;

    if (c != EOF)
        *w++ = c;

    if (!isalpha(c)) {
        prev = c;

        if (c == '/' && (c = getch() == '*'))
            while (c != '*' && (c = getch()) != '/')
                ;
        else if (c == '_')
            while ((c = getch()) != ' ' || c != '\n' || c != EOF)
                ;
        else if (c == '#')
            while ((c = getch()) != '\n' || prev == '/')
                prev = c;
        else if (c == '"')
            while ((c = getch()) != '"')
                ;

        *w = '\0';
        return c;
    }

    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';

    return word[0];
}