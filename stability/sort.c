#include <stdbool.h>
#include <stdio.h>

#include "check.h"
#include "sort.h"


void bubble(Item *list, int n);
void selection(Item *list, int n);
static void swap(Item *list, int i, int j);


// sorted is an array sorted by our unkown algorithm
// how can we verify that the sorted array was stable sorted?
bool isStableSort(Item *unsorted, Item *sorted, int n) {

    return false;

}



// Function returns -ve is a is lesser, +ve if a is greater, 0 if equal
// Looks at both primary and secondary key
int itemCmp(Item a, Item b) {
    return 0;
}



































// // Function returns -ve is a is lesser, +ve if a is greater, 0 if equal
// int itemCmp(Item a, Item b) {
//     if (a.key < b.key) {
//         return -1;
//     } else if (a.key > b.key) {
//         return 1;
//     } else { //now check secondary key
//         if (a.secondary < b.secondary) {
//             return -1;
//         } else if ((a.secondary < b.secondary)) {
//             return 1;
//         }
//         else return 0;
//     }
// }

// //sorted is an array sorted by our unkown algorithm
// //how can we verify that the sorted array was stable sorted?
// bool isStableSort(Item *unsorted, Item *sorted, int n) {
//     //Create a duplicate of the unsorted array
//     Item stable[n];
//     duplicateArray(unsorted, stable, n);
//     //sort it using a known stable algorithm
//     bubble(stable, n);
//     return isEqual(stable, sorted, n);
//     //Compare the two sorted arrays


// }


void selection(Item *list, int n) {
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i; j < n; j++) {
			if (list[j].key < list[min].key) {
				min = j;
			}
		}
		swap(list, i, min);
	}
}

void bubble(Item *list, int n) {
    bool modified = false;
    for (int upper = n - 1; upper > 0; upper--) {
        modified = false;
        for (int j = 0; j < upper; j++) {
            if (list[j].key > list[j + 1].key) {
                swap(list, j, j + 1);
                modified = true;
            }
        }
        if (!modified) break;
    }
}

static void swap(Item *list, int i, int j) {
    Item temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}