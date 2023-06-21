#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../utils.c"


struct nlist *lookup(char *);
unsigned hash(char *);
int undef(char *);
int getword(char *);
struct nlist *install(char *, char *, char *);
int is_type(char *);
int def();


struct nlist {
    struct nlist *next;
    char *name;
    char *type;
    char *defn;
};


int main() {

}


#define HASHSIZE 101
#define WORDLENGTH 50
#define TYPESCOUNT 4

const char *types[TYPESCOUNT] = {"int", "char", "float", "double"};
static struct nlist *hashtab[HASHSIZE];

// define a word
int def(){
    char *name, *definition, *type;
    char *c;
    
    // name has to start with _ or letter and that or digits afterwards
    if (getword(name) == -1)
        return -1;

    // valid type?
    if (getword(type) == -1 || !is_type(type))
        return -2;
    
    getword(definition);

    // assign function, woks just with char and int / long really
    int (*func)();
    if (strcmp(type, "char") == 0)
        func = isalnum;
    else
        func = isdigit;

    // validate the definition according to type used
    c = definition;
    while (*c != '\0')
        if (!func(*c++))
            return -3;
    
    // everything is great, assign value
    int index = hash(name);

    struct nlist *x = install(name, definition, type);

    // free memory, delete if function actually needed
    free(x);

    return 0;
}


// check if word is a valid type
int is_type(char *word){
    for (int i=TYPESCOUNT; i>0; i--)
        if (strcmp(word, types[i]) == 0)
            return 1;

    return 0;
}


// remove node with word from hashtab
int undef(char *word){
    struct nlist *np;

    // go to index calculated by hash
    for (np = hashtab[hash(word)]; np != NULL; np = np->next)
        // move forward looking for word
        if (strcmp(word, np->name) == 0){
            free(np->name);

            // deletion succesfull
            return 0;
        }

    // no such word in hashtab
    return 1;
}

int getword(char *word){
    int c, prev;
    char *w = word;

    while (isspace(c = getch()))
    ;

    if (c != EOF)
        *w++ = c;

    if (!isalpha(c) && c != '_') {
        prev = c;

        if (c == '/' && (c = getch() == '*'))
            while (c != '*' && (c = getch()) != '/')
            ;
        else if (c == '#')
            while ((c = getch()) != '\n' || prev == '/')
                prev = c;
        else if (c == '"')
            while ((c = getch()) != '"')
            ;

        *w = '\0';
        return -1;
    }

    for (int i=WORDLENGTH; --i > 0; w++)
        if (!isalnum(*w = getch()) && *w != '_'){
            ungetch(*w);
            break;
        }

    *w = '\0';

    return word[0];
}

unsigned hash(char *s){
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;

    return hashval % HASHSIZE;
}


struct nlist *lookup(char *s){
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;

    return NULL;
}

struct nlist *install(char *name, char *defn, char *type){
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL){
        np = (struct nlist *) malloc(sizeof(*np));

        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;

        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } 
    else
        free((void *) np->defn);

    if ((np->defn = strdup(defn)) == NULL)
        return NULL;

    np->type = strdup(type);

    return np;
}
