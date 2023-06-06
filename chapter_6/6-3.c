#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


#define MAXWORD 100
#define NOISE_COUNT 5

struct node *addtree(struct node *, char *, int);
void group_print(struct node *, char *);
int getword(char *, int, FILE *);
struct node *talloc(void);
int compare_strings(char *, char *, int);
int getch(FILE *);
void ungetch(int);
int is_noise(char *);


struct node {
    char *word;
    int **list;
    struct node *left;
    struct node *right;
} node;


int main(int argc, char **argv){
    struct node *root;
    root = NULL;

    char word[MAXWORD];
    
    FILE *file = fopen("../utils.c", "r");
    if (!file){
        printf("No file found!\n");
        fclose(file);
        return -1;
    }
    
    while (getword(word, MAXWORD, file) != EOF)
        if (isalpha(word[0]) && !is_noise(word))
            root = addtree(root, word, 5);
    
    group_print(root, NULL);

    fclose(file);
    return 0;
}


struct node *addtree(struct node *p, char *w, int line){
    int cond;

    if (p == NULL) {
        p = talloc();
        const char *ww = w;
        p->word = strdup(ww);
        p->left = p->right = NULL;
    } 
    else if ((cond = strcmp(w, p->word)) < 0)
        p->left = addtree(p->left, w, line);
    else if (cond > 0)
        p->right = addtree(p->right, w, line);

    return p;
}


void group_print(struct node *p, char *prev){
    if (p != NULL) {
        // left nodes recursive
        group_print(p->left, prev);

        printf("%s: ", p->word);
        // while (p->list){
        //     printf("%d", p->list++);
        // }
        printf("\n");

        // right recursive
        group_print(p->right, p->word);

        // clear memory along the way
        free(p);
    }
}


struct node *talloc(void){
    return (struct node *) malloc(sizeof(struct node));
}


int getword(char *word, int lim, FILE *file){
    int c, prev;
    char *w = word;

    while (isspace(c = getch(file)))
    ;

    if (c != EOF)
        *w++ = c;

    if (!isalpha(c)) {
        prev = c;

        if (c == '/' && (c = getch(file) == '*'))
            while (c != '*' && (c = getch(file)) != '/')
                ;
        else if (c == '_')
            while ((c = getch(file)) != ' ' || c != '\n' || c != EOF)
                ;
        else if (c == '#')
            while ((c = getch(file)) != '\n' || prev == '/')
                prev = c;
        else if (c == '"')
            while ((c = getch(file)) != '"')
                ;

        *w = '\0';
        return c;
    }

    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch(file))) {
            ungetch(*w);
            break;
        }
    *w = '\0';

    return word[0];
}


int is_noise(char *word){
    char *noise_words[NOISE_COUNT] = {"the", "and", "but", "so", "that"};

    for (int i = 0; i < NOISE_COUNT; i++)
        if (strcmp(noise_words[i], word) == 0)
            return 1;

    return 0;
}


#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(FILE *file){
    return (bufp > 0) ? buf[bufp--] : fgetc(file);
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}