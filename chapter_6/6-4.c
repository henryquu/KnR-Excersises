/*
Write a program that prints the distinct words in its input sorted into decreasing order of
frequency of occurrence. Precede each word by its count.
*/

// now adding word

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "../utils.c"


#define MAXWORD 100


struct word *add_word(struct word *, char *);
void print_delete(struct word *);
int getword(char *, int);
struct word *talloc(void);
void sort_list(struct word *);


struct word {
    char *word;
    int count;
    struct word *next;
};


int main(){
    struct word *root;
    root = NULL;

    char word[MAXWORD];

    // keep getting and adding words until EOF reached
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = add_word(root, word);
    
    // print the list
    if (root)
        print_delete(root);

    return 0;
}

// sort the linked list
void sort_list(struct word *){

}

// print and delete word structures
void print_delete(struct word *p){
    struct word *tmp;
    
    while (p){
        printf("%d %s\n", p->count, p->word);

        tmp = p;
        p = p->next;

        free(tmp); 
    }
}

// adds word if not in list, otherwise increases it's count
struct word *add_word(struct word *root, char *w){
    if (root == NULL){
        // creaate new word structure
        root = talloc();
        const char *ww = w;

        // copying data
        root->word = strdup(ww);
        root->count = 1;
        root->next = NULL;
    }
    else{
        // struct used for searching
        struct word *tmp = root;
        // comparing word in structure with word w
        int cond = 1;
        
        // go through linked list until end or word found
        while (tmp->next && (cond = strcmp(w, tmp->word)))
            tmp = tmp->next;

        // word w found
        if (cond == 0)
            tmp->count++;
        //reached end of the list
        else{
            tmp->next = talloc();
            const char *ww = w;

            // copying data
            tmp->word = strdup(ww);
            tmp->count = 1;
            tmp->next = NULL;
        }
    }

    return root;
}

// allocate memory for word structure
struct word *talloc(void){
    return (struct word *) malloc(sizeof(struct word));
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