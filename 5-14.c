#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(void *lineptr[], int left, int right,
           int (*comp)(void *, void *), int reverse);
int numcmp(const char*, const char*);
void swap(void *v[], int, int);

int main(int argc, char *argv[]){
    int nlines;
    int numeric = 0;
    int reverse = 0;

    if (argc > 1 &strcmp(argv[1], "-n") == 0)
        numeric = 1;
    
    if (argc > 2 &strcmp(argv[2], "-r") == 0)
        reverse = 1;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(
            (void**) lineptr, 0, nlines - 1, 
            (int (*)(void*, void*))(numeric ? numcmp: strcmp), reverse);
        writelines(lineptr, nlines);
        return 0;
    } 
    else {
        printf("input too big to sort\n");
        return 1;
    }
}

void qsort(void *v[], int left, int right, int (*comp)(void *, void *), int reverse)
{
    int i, last;

    if (left >= right)
        return;

    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (reverse == 0 && (*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
        else if(reverse && (*comp)(v[i], v[left]) < 0)
            swap(v, left, last);
    qsort(v, left, last - 1, comp, reverse);
    qsort(v, last + 1, right, comp, reverse);
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
