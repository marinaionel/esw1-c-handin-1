//
// Created by Marina Ionel on 01/03/2020.
//

#include <stdio.h>

long long power(int base, int exponent) {
    int result = 1;
    while (exponent != 0) {
        result *= base;
        --exponent;
    }
//    return pow(base, exponent);
    return result;
}

void multiSwap(int *x, int *y, int *z) {
    int temp;
    // swapping
    temp = *x;      //temp=x, x=x, y=y, z=z
    *x = *y;        //temp=x, x=y, y=y, z=z
    *y = *z;        //temp=x, x=y, y=z, z=z
    *z = temp;      //temp=x, x=y, y=z, z=x
}

void main() {
    int a = 2, b = 4, c = 9;
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);
//  & before a variable name means "use the address of this variable"
    multiSwap(&a, &b, &c);
    printf("After swap:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);
}
