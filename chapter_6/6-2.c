#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "../utils.c"

#define MAXWORD 100

struct node *addtree(struct node *, char *);
void group_print(struct node *, int , char *);
int getword(char *, int);
struct node *talloc(void);
int compare_strings(char *, char *, int);

struct node {
    char *word;
    struct node *left;
    struct node *right;
} node;



int main(int argc, char **argv){
    struct node *root;
    root = NULL;

    char word[MAXWORD];

    int width = 6;
    if (argc > 1){
        if (!isdigit(argv[1][0]))
            return -1;
        width = (int) (argv[1][0] - '0');
    }

    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);

    group_print(root, width, NULL);

    return 0;
}


struct node *addtree(struct node *p, char *w){
    int cond;
    
    if (p == NULL) {
        p = talloc();
        const char *ww = w;
        p->word = strdup(ww);
        p->left = p->right = NULL;
    } 
    else if ((cond = strcmp(w, p->word)) < 0)
        p->left = addtree(p->left, w);
    else if (cond > 0)
        p->right = addtree(p->right, w);

    return p;
}


void group_print(struct node *p, int width, char *prev){
    if (p != NULL) {
        // left nodes recursive
        group_print(p->left, width, prev);

        // compare characters
        if (prev == NULL || !compare_strings(p->word, prev, width) || (p->left != NULL && !compare_strings(p->word, p->left->word, width)))
            printf("\n");
        printf("%s\n", p->word);

        // right recursive
        group_print(p->right, width, p->word);

        // clear memory along the way
        free(p);
    }
}


int compare_strings(char *string1, char *string2, int width){
    // iterate over both strings, compare them
    // if width is 0, string have to change
    while (*string1 != '\0' && *string2 != '\0' && width >= 0){
        if (*string1 != *string2 && width > 0)
            return 0;
        if (*string1 == *string2 && width == 0)
            return 0;
    
        string1++;
        string2++;
        width--;
    }
    
    if (width > 0 && *string1 != *string2)
        return 0;

    return 1;
}


struct node *talloc(void){
    return (struct node *) malloc(sizeof(struct node));
}


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
