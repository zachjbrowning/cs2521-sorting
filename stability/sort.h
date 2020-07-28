#ifndef STABLE_H
#define STABLE_H

#include <stdbool.h>
#include "check.h"

void bubble(Item *list, int n);
void selection(Item *list, int n);
bool isStableSort(Item *unsorted, Item *sorted, int n);
int itemCmp(Item a, Item b);

#endif