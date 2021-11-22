//
// Created by Marina Ionel on 01/03/2020.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


/* read_line: read a line into s, return length */
int read_line(char s[]) {
    int c = 0, i = 0, done = 0;
    do {
        c = getchar();
        if (c == EOF || c == '\n') { done = 1; } else { s[i++] = c; }
    } while (!done);
    s[i] = '\0';
    return i;
}

void my_to_upper(char *str_in, char *str_out) {
    for (int i = 0; str_in[i] != '\0'; i++) {
        if (str_in[i] >= 'a' && str_in[i] <= 'z') {
            str_out[i] = str_in[i] - 32;
        } else {
            str_out[i] = str_in[i];
        }
    }
    int size = strlen(str_out);
    str_out[size] = '\0';

//    strupr(string)
}

void read_from_file() {
    FILE *in_file = fopen("..\\src\\session3\\my_text_file.txt", "r+");
    if (!in_file) {
        printf("Error! Could not door_open file\n");
        exit(-1);
    }
    char c;
    c = fgetc(in_file);
    while (c != EOF) {
        printf("%c", toupper(c));
        c = fgetc(in_file);
    }
    fclose(in_file);
}
