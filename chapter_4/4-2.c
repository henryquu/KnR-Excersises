#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atonumber(char s[]);


int main() {
    double i;
    i = atonumber("123.45E-6");
    printf("%g\n", i);
}


double atonumber(char s[]) {
    double val, power;
    int i, sign, notation_pow, notation;

    for (i = 0; isspace(s[i]); i++);

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    if (s[i] == 'e' || s[i] == 'E')
        i++;
    
    notation_pow = (s[i] == '-')? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    notation = 0;
    while (isdigit(s[i]))
        notation = notation * 10 + (s[i++] - '0');
    notation *= notation_pow;
    
    return sign * val / power * pow(10, notation);
}
