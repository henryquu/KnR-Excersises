#include <stdio.h>

void lower();


int main() {
    int c;
    lower();
}

void lower() {
    int c;

    while((c = getchar()) != EOF)
        printf("%c", (c >= 'A' && c <= 'Z') ? c-'A'+'a': c);
}