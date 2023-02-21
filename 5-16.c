#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000

#define CAPITAL_LETTER(a) (a >= 'A' && a <= 'Z')
#define SMALL_LETTER(a) (a >= 'a' && a <= 'z')
#define BLANK(a) (a == ' ' || a == '\t' || a == '\n')

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void quick_sort(void *lineptr[], int left, int right, int (*comp)(void *, void *),
           int reverse, int fold, int directory);
int numcmp(const char *, const char *);
void swap(void *v[], int, int);

int main(int argc, char *argv[]){
    int nlines;
    int numeric = 0;
    int reverse = 0;
    int fold = 0;
    int directory = 0;

    for (int i = 0; i < argc; i++){
    if (strcmp(argv[i], "-n") == 0)
        numeric = 1;
    else if (strcmp(argv[i], "-r") == 0)
        reverse = 1;
    else if (strcmp(argv[i], "-f") == 0)
        fold = 1;
    else if (strcmp(argv[i], "-d") == 0)
        directory = 1;
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        quick_sort(
            (void**) lineptr, 0, nlines - 1, 
            (int (*)(void*, void*))(numeric ? numcmp: strcmp), 
            reverse, fold, directory);
        writelines(lineptr, nlines);
        return 0;
    } 
    else {
        printf("input too big to sort\n");
        return 1;
    }
}

void quick_sort(void *v[], int left, int right, int (*comp)(void *, void *), 
           int reverse, int fold, int directory)
{
    int i, last;
    char *folded1, *folded2;

    if (left >= right)
        return;

    swap(v, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++){
        strcpy(folded1, v[i]);
        if (CAPITAL_LETTER(folded1[0]) && fold)
            folded1[0] += 'a' - 'A';
        strcpy(folded2, v[left]);
        if (CAPITAL_LETTER(folded2[0]) && fold)
            folded2[0] += 'a' - 'A';

        if (directory){
            if (!CAPITAL_LETTER(folded1[0]) && !SMALL_LETTER(folded1[0]) && !BLANK(folded1[0]))
                continue;
            if (!CAPITAL_LETTER(folded2[0]) && !SMALL_LETTER(folded2[0]) && !BLANK(folded2[0]))
                continue;
        }

        if (reverse == 0 && (*comp)(folded1, folded2) < 0)
            swap(v, ++last, i);
        else if(reverse && (*comp)(folded1, folded2) < 0)
            swap(v, left, last);
    }
    quick_sort(v, left, last - 1, comp, reverse, fold, reverse);
    quick_sort(v, last + 1, right, comp, reverse, fold, reverse);
}
