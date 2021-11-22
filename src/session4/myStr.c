//
// Created by Marina Ionel on 09/03/2020.
//

#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <corecrt_memory.h>

int my_strlen(const char *str) {
    if (NULL == str) return 0;
    const char *iterator = str;
    while (*iterator != '\0') ++iterator;
    return iterator - str;
}

int my_strcmp(const char *str1, const char *str2) {
    if (NULL == str1 || NULL == str2) return 0;
    char *c1;
    char *c2;
    while (true) {
        c1 = *str1++;
        c2 = *str2++;
        if (c1 != c2) return c1 > c2 ? 1 : -1;
        if (!c1 || !c2) break;
    }
    return 0;
}

char *my_strcpy(char *dest, const char *src) {
    if (NULL == dest || NULL == src) return NULL;
//  store the source temporary
    char *_tmp_src = src;
    while ('\0' != *src) {
//      copy character by character
        *dest++ = *src++;
    }
//  the terminating null character
    *dest = '\0';
    return _tmp_src;
}

char *my_strdup(const char *str) {
    if (str == NULL) return NULL;
    size_t size = my_strlen(str) + 1;
    char *_new = malloc(size);
    if (_new == NULL) return NULL;
    memcpy(_new, str, size);
    return _new;
}
