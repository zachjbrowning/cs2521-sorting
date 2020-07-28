#ifndef LIST_H
#define LIST_H

typedef struct node {
    int value;
    struct node *next;
} Node;
typedef Node *List;

List selectSort(List LL);
List insertSort(List LL);
List insertList (List L, int v);
List newNode(int v);
List generateList(int *array, int n);
void printList(List LL);
List copy(List og);
List findMax(List LL);
List removeNode(List LL, List n);
void freeList(List LL);

#endif