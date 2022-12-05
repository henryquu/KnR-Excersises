#include <stdio.h>


int main(int argc, char **argv) {
    int i = 0;
    char *first;
    char *second;
    char *c;
    while (--argc > 0) {
        c = *++argv;
        if (c[1] == '\0')
            switch (c[0]) {
                case '+':
                case 'x':
                case '-':
                case '/':
                case '%':
                    second = *(argv - ++i);
                    first = (argc > 1)? *(argv - ++i): "";
                    if (i <= 2) {
                        printf("(%s %s %s) ", first, *argv, second);
                        i++;
                    }
                    else
                        printf("%s %s ", *argv, second);
                    break;
                default:
                    break;
            }
    }
    printf("\n");
    return 0;
}


