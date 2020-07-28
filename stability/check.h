#ifndef CHECK_H
#define CHECK_H

#include <stdbool.h>

typedef struct {
    int key;
    int secondary;
} Item;

void printArray(Item *src, int n);
void duplicateArray(Item *src, Item *dest, int n);
bool isEqual(Item *src, Item *dest, int n);


#endif