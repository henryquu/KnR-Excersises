#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
#define CAPITAL_LETTER(a) (a >= 'A' && a <= 'Z')

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void quick_sort(void *lineptr[], int left, int right, int (*comp)(void *, void *),
           int reverse, int fold_case);
int numcmp(const char *, const char *);
void swap(void *v[], int, int);

int main(int argc, char *argv[]){
    int nlines;
    int numeric = 0;
    int reverse = 0;
    int fold_case = 0;

    if (argc > 1 &strcmp(argv[1], "-n") == 0)
        numeric = 1;
    
    if (argc > 2 &strcmp(argv[2], "-r") == 0)
        reverse = 1;

    if (argc > 2 &strcmp(argv[3], "-f") == 0)
        fold_case = 1;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        quick_sort(
            (void**) lineptr, 0, nlines - 1, 
            (int (*)(void*, void*))(numeric ? numcmp: strcmp), reverse, fold_case);
        writelines(lineptr, nlines);
        return 0;
    } 
    else {
        printf("input too big to sort\n");
        return 1;
    }
}

void quick_sort(void *v[], int left, int right, int (*comp)(void *, void *), int reverse, int fold_case)
{
    int i, last;
    char *folded1, *folded2;

    if (left >= right)
        return;

    swap(v, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++){
        strcpy(folded1, v[i]);
        if (CAPITAL_LETTER(folded1[0]) && fold_case)
            folded1[0] += 'a' - 'A';
        strcpy(folded2, v[left]);
        if (CAPITAL_LETTER(folded2[0]) && fold_case)
            folded2[0] += 'a' - 'A';
    
        if (reverse == 0 && (*comp)(folded1, folded2) < 0)
            swap(v, ++last, i);
        else if(reverse && (*comp)(folded1, folded2) < 0)
            swap(v, left, last);
    }
    quick_sort(v, left, last - 1, comp, reverse, fold_case);
    quick_sort(v, last + 1, right, comp, reverse, fold_case);
}

int numcmp(const char *s1, const char *s2){
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);

    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

