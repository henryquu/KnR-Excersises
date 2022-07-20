#include <stdio.h>

int main() {
    float fahr, celsius;
    
    printf("Celsius\t\tFahrenheit\n");
    for (celsius = 300; celsius >= 0; celsius -= 20) {
        fahr = (9.0 / 5.0) * celsius + 32 ;
        printf("%3.0f\t\t%6.1f\n", celsius, fahr);
    }
}