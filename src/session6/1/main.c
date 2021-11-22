//
// Created by Marina Ionel on 23/04/2020.
//
#include "list.h"
#include <stdio.h>

main() {
    list_t list = list_create();

    if (list == NULL) {
        printf("the list was not created\n");
    } else { printf("the list was created!\n"); }

    int a = 8;

    list_addItem(list, &a);
    printf("The number of items in the list: ");
    printf("%d", list_noOfItems(list));

    void *out = NULL;
    list_getItem(list, &out, 0);
    int *res = (int *) out;
    printf("\n%d", *res);

    if (LIST_OK == list_removeItem(list, &a)) {
        printf("\nremoved item from list");
    } else printf("\nremoval not possible");

    printf("\nThe number of items in the list: ");
    printf("%d", list_noOfItems(list));

    list_destroy(list);
}
