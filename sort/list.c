#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


#include "list.h"



List selectSort(List LL) {
    List result = NULL;
    return result;
    
}

List insertSort(List LL) {
    List result = NULL;
    return result;
}





























// /* Selection sort LL version:
//  - Make a copy of LL
//  - One by one, choose largest element of copy, insert at start of new list
//  - Once we run out of nodes, the new list should have them all sorted!
// */
// List selectSort(List LL) {
//     List duplicate = copy(LL);
//     List result = NULL;
//     while (duplicate != NULL) {
//         //Find the maximum element in the list
//         List max = findMax(duplicate);
//         //Remove it from duplicate
//         duplicate = removeNode(duplicate, max);
//         //Insert at the start of result
//         max->next = result;
//         result = max;
//     }
//     return result;
    
// }




// /* Insertion sort LL version:
//  - For each node in old list, remove it and insert it in new list
// */
// List insertSort(List LL) {
//     List result = NULL;
//     List curr = LL;
//     while (curr != NULL) {
//         List next = curr->next;
//         result = insertList(result, curr->value);
//         free(curr);
//         curr = next;
//     }
//     LL = result;
//     return LL;
    
// }












List insertList (List L, int v) {
    List new = newNode(v);
    if (L == NULL) return new;
    else if (L->value > v) {
        new->next = L;
        return new;
    }
    else {
        List curr = L;
        List prev = L;
        while (curr != NULL && curr->value <= v) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = new;
        new->next = curr;
        return L;
    }

}

List newNode(int v) {
    List new = malloc(sizeof(Node));
    assert(new != NULL);
    new->value = v;
    new->next = NULL;
    return new;
}

List generateList(int *array, int n) {
    List head = NULL;
    for (int i = n - 1; i >=0; i--) {
        List new = newNode(array[i]);
        new->next = head;
        head = new;
    }
    return head;
}

void printList(List LL) {
    List curr = LL;
    while (curr != NULL) {
        printf("(%d) -> ", curr->value);
        curr = curr->next;
    }
    printf("x\n");
}

List copy(List og) {
    if (og == NULL) return NULL;

    List new = malloc(sizeof(Node));
    new->value = og->value;
    new->next = copy(og->next);
    return new;
}


List findMax(List LL) {
    List currMax = LL;
    for (List curr = LL; curr != NULL; curr = curr->next) {
        if (curr->value > currMax->value) currMax = curr;
    }
    return currMax;
}

List removeNode(List LL, List n) {
    if (LL == n) return LL->next;
    LL->next = removeNode(LL->next, n);
    return LL;
}

void freeList(List LL) {
    while (LL != NULL) {
        List temp = LL;
        LL = LL->next;
        free(temp);
    }
}
