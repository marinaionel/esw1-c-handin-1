//
// Created by Marina Ionel on 24/02/2020.
//

#include <stdio.h>

void main() {
    int seven = 7, three = 3;
//  If 'seven' and 'three' are both integers, then the result is 2 (not 2.333333)
    printf("%d\n", seven / three);

    int remainder = (7 % 3);
    printf("%d\n", remainder);

//  But when at least one of them is float then the result is 2.333333 (a float)
    printf("%f\n", (7.0 / 3));
    printf("%f\n", (7.0 / 3.0));
}