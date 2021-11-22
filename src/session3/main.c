//
// Created by Marina Ionel on 16/04/2020.
//

#include <stdbool.h>
#include "my_string_func.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

main() {
    read_from_file();
    while (true) {
        printf("\nType \"esc\" to exit\n");
        char line[MAX_LENGTH] = {0};
        char upper[MAX_LENGTH] = {0};
        scanf("%s", line);

        if (strcmp(line, "esc") == 0) exit(0);

        my_to_upper(line, upper);

        printf("%s", upper);
        printf("\nThe length of the string: %d", strlen(line));
    }
}