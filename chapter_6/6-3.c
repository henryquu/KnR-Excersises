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
int getch(FILE *);
void ungetch(int);
int is_noise(char *);

// linked list
struct list {
    int val;
    struct list *next;
} list;

// word tree
struct node {
    char *word;
    struct list *lines;
    struct node *left;
    struct node *right;
} node;



int main(int argc, char **argv){
    struct node *root;
    root = NULL;

    char word[MAXWORD];
    
    // open and check file
    FILE *file = fopen("../utils.c", "r");
    if (!file){
        printf("No file found!\n");
        fclose(file);
        return -1;
    }
    
    // line counting variable
    int line = 0;
    // variable for new line checking
    char output;
    while ((output = getword(word, MAXWORD, file)) != EOF)
        if (isalpha(word[0]) && !is_noise(word))
            root = addtree(root, word, line);
        else if (output == '\n')
            line++;
    
    group_print(root, NULL);

    fclose(file);
    return 0;
}


struct node *addtree(struct node *p, char *w, int line){
    int cond;
    struct list *new;

    // new word
    if (p == NULL) {
        // new leaf
        p = talloc();
        
        // new line structure
        new = malloc(sizeof(struct list));
        new->val = line;
        new->next = NULL;

        // asigning values to leaf
        const char *ww = w;
        p->word = strdup(ww);
        p->lines = new;
        p->left = p->right = NULL;
    }
    // updating leaf lines list 
    else if ((cond = strcmp(w, p->word)) == 0){
        // go to the end of the list
        while ((p->lines = p->lines->next))
        ;
        // create a new structure
        new = malloc(sizeof(struct list));
        new->val = line;
        new->next = NULL;

        // assigning new value to leaf
        p->lines = new;
    }
    // word should be on the left of the current leaf
    else if (cond < 0)
        p->left = addtree(p->left, w, line);
    // word should be on the right
    else if (cond > 0)
        p->right = addtree(p->right, w, line);

    return p;

}


void group_print(struct node *p, char *prev){
    if (p != NULL) {
        // left nodes recursive
        group_print(p->left, prev);

        // printing current leaf
        printf("%s:", p->word);
        // tmp struct object for deletion
        struct list *previous_line = p->lines;
        // itereate over list of lines, print and delete them
        while (p->lines){
            printf(" %d", *p->lines);
            p->lines = p->lines->next;
            free(previous_line);
            previous_line = p->lines;
        }
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

    if (c == '\n')
        return c;

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
    // array of noise words
    char *noise_words[NOISE_COUNT] = {"the", "and", "but", "so", "that"};

    // compare array's words with input word
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