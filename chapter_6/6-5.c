#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nlist *lookup(char *);
unsigned hash(char *);
int undef(char *);


struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};


int main() {

}


#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];

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

struct nlist *install(char *name, char *defn){
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

    return np;
}
