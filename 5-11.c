#include <stdio.h>


int entab(char **, int);
int detab(char **, int);


int main(int argc, char **argv) {
    detab(++argv, argc - 1);
}

int detab(char **tabs_list, int length) {
    int c, out_index, current_tab, tab_sum;
    char **start;

    if (length == 0) {
        char x[] = {"7"};
        *tabs_list = x;
        length = 1;
    }
    start = tabs_list;

    out_index = 0;
    tab_sum = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            if (**tabs_list > '9' || **tabs_list < '1')
                return -1;
            
            while (tab_sum <= out_index){
                current_tab = **tabs_list++ - '0';
                tab_sum += current_tab;

                if (tabs_list - length == start)
                    tabs_list = start;
            }
                
            while (out_index < tab_sum){
                out_index++;
                putchar(' ');
            }

            
        }
        else {
            putchar(c);
            out_index++;
            if (c == '\n') {
                out_index = 0;
                tabs_list = start;
                tab_sum = 0;
            }
        }
    }
}

int entab(char **tabs_list, int length) {
    int c, i, j, spaces, tabs;
    char **start;

    if (length == 0) {
        char *x[] = {"7"};
        tabs_list = x;
        length = 1;
    }
    start = tabs_list;

    i = 0;
    spaces = 0;
    int tab_index = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (**tabs_list > '9' || **tabs_list < '0')
                return -1;
    
            while (c == ' ') {
                c = getchar();
                spaces++;
            }

            tabs = **tabs_list++ - '0';
            tab_index++;
            
            if (tab_index == length) {
                tabs_list = start;
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
