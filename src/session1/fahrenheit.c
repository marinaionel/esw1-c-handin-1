#include <stdio.h>

/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300 */
void main() {
//    header
    printf("Fahrenheit-Celsius table\n");
    int fahr, celsius;
    int lower, upper, step;
    /* lower limit of temperature scale */
    lower = 0;
    /* upper limit */
    upper = 300;
    /* step size */
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}
