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
                int reverse, int fold, int directory, int column);
int numcmp(const char *, const char *);
void swap(void *v[], int, int);

int main(int argc, char *argv[]){
    int nlines;
    int numeric = 0;
    int reverse = 0;
    int fold = 0;
    int directory = 0;
    int column = 0;
    int ind;

    if ((nlines = readlines(lineptr, MAXLINES)) < 0){
        printf("input too big to sort\n");
        return 1;
    }

    for (int i = 0; i < argc; i++){
        ind = 1;
        if (argv[i][0] != '-')
            continue;
        if (argv[i][1] >= '0' && argv[i][1] <= '9')
            ind++;

        numeric = 0;
        reverse = 0;
        fold = 0;
        directory = 0;

        if (argv[i][ind] == 'n'){
            numeric = 1;
            if (argv[i][ind + 1] == 'r')
                reverse = 1;
        }
        else if (argv[i][ind] == 'r')
            reverse = 1;
        else if (argv[i][ind] == 'd'){
            directory= 1;
            if (argv[i][ind + 1] == 'f')
                fold = 1;
        }
        quick_sort(
            (void**) lineptr, 0, nlines - 1, 
            (int (*)(void*, void*))(numeric ? numcmp: strcmp), 
            reverse, fold, directory, column);
        writelines(lineptr, nlines);
    }
        
    return 0;
}

void quick_sort(void *v[], int left, int right, int (*comp)(void *, void *), 
                int reverse, int fold, int directory, int column)
{
    int i, last;
    char *folded1, *folded2;

    if (left >= right)
        return;

    swap(v, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++){
        strcpy(folded1, v[i]);
        if (CAPITAL_LETTER(folded1[column]) && fold)
            folded1[column] += 'a' - 'A';
        strcpy(folded2, v[left]);
        if (CAPITAL_LETTER(folded2[column]) && fold)
            folded2[column] += 'a' - 'A';

        if (directory){
            if (!CAPITAL_LETTER(folded1[column]) && !SMALL_LETTER(folded1[column]) && !BLANK(folded1[column]))
                continue;
            if (!CAPITAL_LETTER(folded2[column]) && !SMALL_LETTER(folded2[column]) && !BLANK(folded2[column]))
                continue;
        }

        if (reverse == 0 && (*comp)(folded1, folded2) < 0)
            swap(v, ++last, i);
        else if(reverse && (*comp)(folded1, folded2) > 0)
            swap(v, left, last);
    }
    quick_sort(v, left, last - 1, comp, reverse, fold, directory, column);
    quick_sort(v, last + 1, right, comp, reverse, fold, directory, column);
}
