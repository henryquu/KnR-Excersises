#include <stdio.h>


int entab(char **, int);
int detab(char **, int);


int main(int argc, char **argv) {
    printf("%d\n", entab(++argv, argc - 1));
}

int detab(char **tabstops, int length) {
    int c, i, j, tabs, tab_sum;
    char **start;

    if (length == 0) {
        char x[] = {"7"};
        *tabstops = x;
        length = 1;
    }
    start = tabstops;

    i = 0;
    j = 0;
    tab_sum = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            if (**tabstops > '9' || **tabstops < '0')
                return -1;
            tabs = **tabstops++ - '0';
            j++;
            tab_sum += tabs;

            while ((i % tab_sum) != 0) {
                putchar(' ');
                i++;
            }

            if (j == length) {
                tabstops = start;
                tab_sum = 0;
            }
        }
        else {
            putchar(c);
            i++;
            if (c == '\n') {
                i = 0;
                tabstops = start;
                j = 0;
                tab_sum = 0;
            }
        }
    }
}

int entab(char **tabstops, int length) {
    int c, i, j, spaces, tabs;
    char **start;

    if (length == 0) {
        char *x[] = {"7"};
        tabstops = x;
        length = 1;
    }
    start = tabstops;

    i = 0;
    spaces = 0;
    int tab_index = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (**tabstops > '9' || **tabstops < '0')
                return -1;
    
            while (c == ' ') {
                c = getchar();
                spaces++;
            }

            tabs = **tabstops++ - '0';
            tab_index++;
            
            if (tab_index == length) {
                tabstops = start;
                tab_index = 0;
            }
    
            for (j = 0; j < spaces;) {
                if ((spaces >= j + 4) && ((tabs - i % tabs) >= 4)) {
                    printf("\\t");
                    i += 4;
                    j += 4;
                    while ((i % tabs) != 0) {
                        putchar(' ');
                        i++;
                        j++;
                    }
                }
                else {
                    i++;
                    j++;
                    putchar(' ');
                }
            }
            spaces = 0;
        }
        putchar(c);
        i++;
        if (c == '\n')
            i = 0;
        }
}
