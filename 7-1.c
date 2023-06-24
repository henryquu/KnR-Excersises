#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char **argv){
    // check for proper usage: needs argument text 'upper' or 'lower'
    if (argc != 2 || (strcmp(argv[1], "upper") && strcmp(argv[1], "lower"))){
        printf("Usage: './7-1.exe lower' or './7-1.exe upper'");
        return -1;
    }
    
    // assign chosen function
    int (*function)(int) = (strcmp(argv[1], "lower") == 0)? tolower: toupper;

    // use the chosen function over iterated text
    int c;
    while ((c = getchar()) != EOF)
        putchar(function(c));

    return 0;
}

