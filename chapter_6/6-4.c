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


// adds word to word list, returns head pointer
struct word *add_word(struct word *, char *);
// prints and delets word list
void print_delete(struct word *);
// get word from input
int getword(char *, int);
// return ptr to new default word structure
struct word *talloc(const char *);
// sort word list
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
    if (root == NULL)
        root = talloc(w);
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
        else
            tmp->next = talloc(w);
    }

    return root;
}

// allocate memory for word structure
struct word *talloc(const char *word){
    struct word *ptr = malloc(sizeof(struct word));

    // copying data
    ptr->word = strdup(word);
    ptr->count = 1;
    ptr->next = NULL;

    return ptr;
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