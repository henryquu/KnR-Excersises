#include <stdio.h>
#include <string.h>
#include <math.h>


int htoi(char[]);


int main() {
    int c, i;
    char s[50];

    i = 0;
    while ((c = getchar()) != '\n')
        s[i++] = c;
    s[i] = '\0';

    printf("Decimal = %i\n", htoi(s));
    return 0;   
}

int htoi(char s[]) {
    int i, k;
    int n = strlen(s) - 1;
    int sum = 0;

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        k = 2;
    else
        k = 0;

    for (i = 0; i <= n - k; i++) {
        if (s[n - i] >= 'A' && s[n - i] <= 'F') 
            sum += (s[n - i] - 'A' + 10) * pow(16, i);
        else if (s[n - i] >= 'a' && s[n - i] <= 'f')
            sum += (s[n - i] - 'a' + 10) * pow(16, i);
        else if (s[n - i] >= '0' && s[n - i] <= '9')
            sum += (s[n - i] - '0') * pow(16, i);
        else {
            printf("Wrong input!\n");
            return -1;
        }
    }
    return sum;
}