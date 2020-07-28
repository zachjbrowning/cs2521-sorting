#include <stdbool.h>
#include <stdio.h>


#include "check.h"

void printArray(Item *src, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            printf("(%d,%d), ", src[i].key, src[i].secondary);
        } else {
            printf("(%d,%d)]\n", src[i].key, src[i].secondary);
        }
    }
}


void duplicateArray(Item *src, Item *dest, int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}


bool isEqual(Item *src, Item *dest, int n) {
    for (int i = 0; i < n; i ++) {
        if (dest[i].key != src[i].key || dest[i].secondary != src[i].secondary) return false;
    }
    return true;
}
