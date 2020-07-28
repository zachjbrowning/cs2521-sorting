#include <stdio.h>
#include <string.h>

#include "list.h"

static void tester(List LL, List (*func) (List));


int main(int argc, char **argv) {
    if (argc < 2 || (strcmp("select", argv[1]) != 0 && strcmp("insert", argv[1]) != 0)) {
        printf("Usage : %s [select|insert]\n", argv[0]);
        return 0;
    }
    
    int ex1[10] = {6, 10, 2, 3, 0, 8, 9, 1, 4, 6};
    int ex2[10] = {6, 6, 6, -1, 0, 1, 9, 1, 4, 9};
    
    List list1 = generateList(ex1, 10);
    List list2 = generateList(ex2, 10);


    List (*func) (List) = strcmp("select", argv[1]) != 0 ? insertSort : selectSort;

    tester(list1, func);
    tester(list2, func);

    freeList(list1);
    freeList(list2);
}



static void tester(List LL, List (*func) (List)) {
    printf("\n\n");
    printf("Before sorting:\n");
    printList(LL);
    List Sorted = (*func) (LL);
    printf("After sorting:\n");
    printList(Sorted);
}


