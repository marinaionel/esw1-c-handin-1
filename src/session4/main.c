//
// Created by Marina Ionel on 16/04/2020.
//

#include "myStr.h"
#include <stdio.h>

main() {
    printf("%d\n", my_strcmp("Hello World", "Hello World"));
    printf("%d\n", my_strcmp("Hello World", ""));
    printf("%d\n", my_strcmp("", ""));
    printf("%d\n", my_strcmp("Hello World", "Hello, world"));

    char str1[10] = "lalala";
    char str2[10];
    char str3[10];

    my_strcpy(str2, str1);
    my_strcpy(str3, "chacha");

    printf("%s\n", str2);
    printf("%s\n", str3);

    char source[7] = "Family\0";
    char *target = my_strdup(source);
    printf("%s", target);
}