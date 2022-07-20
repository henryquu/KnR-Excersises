#include <stdio.h>
/* print Fahrenheit−Celsius table
for fahr = 0, 20, ..., 300 */

int celsius(int fahr);

int main() {
    int fahr;
    int lower, upper, step;

    lower = 0; /* lower limit of temperature scale */
    upper = 300; /* upper limit */
    step = 20; /* step size */
    fahr = lower;

    while (fahr <= upper) {
        printf("%d\t%d\n", fahr, celsius(fahr));
        fahr = fahr + step;
    }
}

int celsius(int fahr) {
    int celsius;
    return celsius = 5 * (fahr - 32) / 9;
}