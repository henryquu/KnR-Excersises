#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

int gettoken(void);
int getch(void);
void ungetch(int);

int tokentype; 
char token[MAXTOKEN];
char out[1000];


int main(){
    int type;
    int previous = 0;
    char temp[MAXTOKEN];
    
    while (gettoken() != EOF) {
        strcpy(out, token);
        while ((type = gettoken()) != '\n'){
            if (type == PARENS || type == BRACKETS)
                strcat(out, token);
            else if (type == '*') {
                if (previous != '*')
                    sprintf(temp, "(*%s)", out);
                else
                    sprintf(temp, "*%s", out);
                strcpy(out, temp);
            } 
            else if (type == NAME) {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            } 
            else
                printf("invalid input at %s\n", token);
            previous = type;
        }
        printf("%s\n",out);
    }
    return 0;
}

int gettoken(void){
    int c;
    char *p = token;

    while ((c = getch()) == ' ' || c == '\t');

    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } 
        else {
            ungetch(c);
            return tokentype = '(';
        }
    } 
    else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']'; );
            *p = '\0';
        return tokentype = BRACKETS;
    } 
    else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch()); )
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } 
    else
        return tokentype = c;
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}