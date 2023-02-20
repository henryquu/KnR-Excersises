#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

#define CAPITAL_LETTER(a) (a >= 'A' && a <= 'Z')
#define SMALL_LETTER(a) (a >= 'a' && a <= 'z')
#define BLANK(a) (a == ' ' || a == '\t' || a == '\n')

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *),
           int reverse, int fold_case, int directory);
int numcmp(const char *, const char *);

int main(int argc, char *argv[]){
    int nlines;
    int numeric = 0;
    int reverse = 0;
    int fold_case = 0;
    int directory = 0;

    for (int i = 0; i < argc; i++){
    if (strcmp(argv[i], "-n") == 0)
        numeric = 1;
    else if (strcmp(argv[i], "-r") == 0)
        reverse = 1;
    else if (strcmp(argv[i], "-f") == 0)
        fold_case = 1;
    else if (strcmp(argv[i], "-d") == 0)
        directory = 1;
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(
            (void**) lineptr, 0, nlines - 1, 
            (int (*)(void*, void*))(numeric ? numcmp: strcmp), 
            reverse, fold_case, directory);
        writelines(lineptr, nlines);
        return 0;
    } 
    else {
        printf("input too big to sort\n");
        return 1;
    }
}

void qsort(void *v[], int left, int right, int (*comp)(void *, void *), 
           int reverse, int fold_case, int directory)
{
    int i, last;
    char folded1, folded2;

    if (left >= right)
        return;

    swap(v, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++){
        if (directory){
            if (!CAPITAL_LETTER(v[i]) && !SMALL_LETTER(v[i]) && !BLANK(v[i]))
                continue;
            if (!CAPITAL_LETTER(v[left]) && !SMALL_LETTER(v[left]) && !BLANK(v[left]))
                continue;
        }

        folded1 = (CAPITAL_LETTER(v[i]) && fold_case) ? v[i] + 'a' - 'A': v[i];
        folded2 = (CAPITAL_LETTER(v[left]) && fold_case) ? v[left] + 'a' - 'A': v[left];
        if (reverse == 0 && (*comp)(folded1, folded2) < 0)
            swap(v, ++last, i);
        else if(reverse && (*comp)(folded1, folded2) < 0)
            swap(v, left, last);
    }
    qsort(v, left, last - 1, comp, reverse, fold_case);
    qsort(v, last + 1, right, comp, reverse, fold_case);
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

