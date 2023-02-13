#include <stdio.h>


int entab(char **, int, int);
int detab(char **, int, int);


int main(int argc, char **argv) {
    argv++;
    if (argc != 4 || argv[1][0] != '-' || argv[2][0] != '+')
        return -1;
    if (argv[1][1] < '0' || argv[1][1] > '9' || argv[2][1] < '0' || argv[2][1] > '9')
        return -1;

    char c[2] = "\0";
    c[0] = argv[2][1];
    char *tabstop[] = {c};
    int starting_point = argv[1][1] - '0';
    if (**argv == 'e'){
        entab(tabstop, 1, starting_point);
        return 0;
    }
    else if (**argv == 'd'){
        detab(tabstop, 1, starting_point);
        return 0;
    }
    return -1;
}

int detab(char **tabs_list, int length, int starting_column) {
    int c, out_index, tab_sum;
    char **start;

    if (length == 0) {
        char x[] = {"7"};
        *tabs_list = x;
        length = 1;
    }
    start = tabs_list;

    out_index = 0;
    tab_sum = starting_column;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            if (**tabs_list > '9' || **tabs_list < '1')
                return -1;
            
            while (tab_sum <= out_index){
                tab_sum += **tabs_list++ - '0';

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
                tab_sum = starting_column;
            }
        }
    }
}

int entab(char **tabs_list, int length, int starting_column) {
    int c, out_index, spaces, tab_sum;
    char **start;

    if (length == 0) {
        char *x[] = {"7"};
        tabs_list = x;
        length = 1;
    }
    start = tabs_list;

    out_index = 0;
    tab_sum = starting_column;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            spaces = 1;
            while ((c = getchar()) == ' ') {
                spaces++;
            
                if (spaces + out_index >= tab_sum) {
                    while (out_index + 4 <= tab_sum){
                        printf("\\t");
                        out_index += 4;
                        spaces -= 4;
                    }
                    while (out_index < tab_sum){
                        spaces--;
                        out_index++;
                        printf(" ");
                    }
                    while (tab_sum <= out_index){
                        if (**tabs_list > '9' || **tabs_list < '0')
                            return -1;

                        tab_sum += **tabs_list++ - '0';
                        if (tabs_list - length == start)
                            tabs_list = start;
                    }
                }
            }
            while (spaces - 4 > 0){
                printf("\\t");
                out_index += 4;
                spaces -= 4;
            }
            while (spaces > 0){
                spaces--;
                out_index++;
                printf(" ");
            }
        }
        putchar(c);
        out_index++;
        if (c == '\n') {
            out_index = 0;
            tabs_list = start;
            tab_sum = starting_column;
        }
    }
}
