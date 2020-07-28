#include <stdio.h>


#include "check.h"
#include "sort.h"

static void tester(Item *list, int n);
static void cmpTest(Item a, Item b);

int main(void) {
    Item same1[] = {{1, 9}, {1, 4}, {2, 7}, {2, 3}}; 
    Item same2[] = {{2, 7}, {2, 3}, {1, 1}, {1, 9}};
    Item diff1[] = {{2, 3}, {1, 6}, {2, 2}, {1, 7}};

    tester(same1, 4);
    tester(same2, 4);
    tester(diff1, 4);


    Item a1 = {1,1};
    Item b1 = {1,8};
    Item a2 = {6,1};


    cmpTest(a1, b1);
    cmpTest(a2, b1);
    cmpTest(b1, b1);
}


static void tester(Item *list, int n) {
    printf("\n\n");
    Item stable[n];
    duplicateArray(list, stable, n);
    Item unstable[n];
    duplicateArray(list, unstable, n);

    printf("Original array:\n ");
    printArray(list, n);

    printf("Stable sorted array:\n ");
    bubble(stable, n);
    printArray(stable, n);
    printf(" --> Is stable: %s\n", isStableSort(list, stable, n) ? "true" : "false");

    printf("Unstable sorted array:\n ");
    selection(unstable, n);
    printArray(unstable, n);
    printf(" --> Is stable: %s\n", isStableSort(list, unstable, n) ? "true" : "false");
}


static void cmpTest(Item a, Item b) {
    printf("\n\nA is [%d, %d]\n", a.key, a.secondary);
    printf("B is [%d, %d]\n", b.key, b.secondary);
    int res = itemCmp(a,b);
    if (res == 0) printf("A and B are equal\n");
    else printf("%s\n", res < 0 ? "A is lesser than B" : "B is lesser than A");
}