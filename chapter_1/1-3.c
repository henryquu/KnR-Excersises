#include <stdio.h>

int main() {
    float fahr, celsius;
    float lower, upper, step;
    
    lower = 0;
    upper = 300;
    step = 20;
    
    printf("Fahrad\t\tCelsius\n");
    fahr = lower;
    while (fahr <= upper)   {
        celsius = (5.0 / 9.0) * (fahr - 32.0) ;
        printf("%3.0f\t\t%6.1f\n", fahr, celsius);
        fahr += step;
    }
}