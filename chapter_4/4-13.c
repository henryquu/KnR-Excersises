#include <stdio.h>
#include <string.h>


void reverse(char[]);


int main() {
    char s[] = "wqtqqcawup";
    reverse(s);
    printf("%s\n", s);

    char t[] = "215fawup";
    reverse(t);
    printf("%s\n", t);
}


void reverse(char s[]) {
    static int l = 0;
    static int r = 0;
    int c;

    if (s[r] == '\0') {
        r--;
        return;
    }
    r++;
    reverse(s);

    if (l < r) {
        c = s[l];
        s[l++] = s[r];
        s[r--] = c;
    }
    else {
        r = 0;
        l = 0;
    }
}