#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} List;

// OPERASI ADT LINKED LIST
void createList(List* L);           
bool isEmptyList(List L);
Node* allocate(int x);
void deallocate(Node* p);
void insertLast(List* L, int x);
Node* searchList(List L, int x);
void deleteValue(List* L, int x);
int lengthList(List L);
void destroyList(List* L);
void printList(List L);

#endif
