#include <stdio.h>
#include <string.h>

int strindex(char[], char[]);


int main () {
    char s[] = "dacsmkowmqrpop51asdac";
    printf("%i\n", strindex(s, "dac"));
}


int strindex(char s[], char t[]) {
    int j;
    int last = -1;

    for (int i = 0; i < strlen(s); i++) 
        if (s[i] == t[0]) {
            for (j = 0; j < strlen(t); j++)
                if (s[i + j] != t[j])
                    break;
            if (j == strlen(t))
                last = i;
        }
    return last;        
}