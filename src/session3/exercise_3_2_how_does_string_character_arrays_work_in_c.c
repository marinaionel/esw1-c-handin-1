//
// Created by Marina Ionel on 01/03/2020.
//

#include <stdio.h>

main() {
    char text[] = "The quick brown fox jumps over lazy dog";
    char *endS = text + 39; /* Don't worry about this */

    printf("The string now says: \"%s\"\n", text);
    *endS = '\0';
    printf("The string now says: \"%s\"\n", text);

    // Repeat the following three lines in your own example, but experiment
    // with different values than just subtracting 1 from endS

    endS = endS - 1;
    *endS = '\0';
    printf("The string now says: \"%s\"\n", text);

    endS++;
    *endS = '\0';
    printf("The string now says: \"%s\"\n", text);

    endS = endS - 10;
    *endS = '\0';
    printf("The string now says: \"%s\"\n", text);

    *endS = 'r';

    endS = endS + 30;
    *endS = '\0';
    printf("The string now says: \"%s\"\n", text);
    return 0;
}
