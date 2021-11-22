//
// Created by Marina Ionel on 16/04/2020.
//
#include <stdio.h>

void main() {
    //    header
    printf("+---------+------------+\n");
    printf("| Celsius | Fahrenheit |\n");
    printf("+---------+------------+\n");
    int fahr, celsius;
    int lower, upper, step;
    /* lower limit of temperature scale */
    lower = 0;
    /* upper limit */
    upper = 300;
    /* step size */
    step = 20;

    celsius = lower;

    while (celsius <= upper) {
        fahr = 32.0 + (9.0 / 5.0) * celsius;

        //format the table
        printf("| %d ", celsius);
        if (celsius < 10) printf("  ");
        if (celsius > 9 && celsius < 100) printf(" ");
        printf("    | %d", fahr);
        if (fahr > 9 && fahr < 100) printf(" ");
        printf("        |\n");

        celsius = celsius + step;

        printf("+---------+------------+\n");
    }
}