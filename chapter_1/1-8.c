#include <stdio.h>

int main() {
    int c, nl, blanks, tabs;

    nl = 0;
    blanks = 0;
    tabs = 0;

    while ((c = getchar()) != EOF){
        if (c == '\t')
            ++tabs;
        else if (c == ' ')
            ++blanks;
        else if (c == '\n')
            ++nl;
    }
    printf("newlines: %d\n", nl);
    printf("blanks: %d\n", blanks);
    printf("tabs: %d\n", tabs);
}
