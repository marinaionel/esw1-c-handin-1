//
// Created by Marina Ionel on 16/04/2020.
//

#include <stdio.h>

#include "subtraction.h"
#include "multiplication.h"
#include "addition.h"

int main (void) {
    int a = 10;
    int b = -2;

    printf ("\nHere, we add, subtract and multiply....\n\n");
    printf ("%d\t+\t%d\t=\t%d\n", a, b, esw_add(a,b));
    printf ("%d\t-\t%d\t=\t%d\n", a, b, esw_subtract(a,b));
    printf ("%d\t*\t%d\t=\t%d\n", a, b, esw_multiply(a,b));

    return 0;
}
