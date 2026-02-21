#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void createList(List* L) {
    L->head = NULL;
}

bool isEmptyList(List L) {
    return L.head == NULL;
}

Node* allocate(int x) {
    Node* p = (Node*)malloc(sizeof(Node));
    if (p != NULL) {
        p->data = x;
        p->next = NULL;
    }
    return p;
}

void deallocate(Node* p) {
    free(p);
}

void insertLast(List* L, int x) {
    Node* p = allocate(x);
    if (isEmptyList(*L)) {
        L->head = p;
    } else {
        Node* temp = L->head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = p;
    }
}

Node* searchList(List L, int x) {
    Node* temp = L.head;
    while (temp != NULL) {
        if (temp->data == x)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void deleteValue(List* L, int x) {
    Node* temp = L->head;
    Node* prev = NULL;

    while (temp != NULL && temp->data != x) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    if (prev == NULL)
        L->head = temp->next;
    else
        prev->next = temp->next;

    deallocate(temp);
}

int lengthList(List L) {
    int count = 0;
    Node* temp = L.head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void destroyList(List* L) {
    Node* temp;
    while (L->head != NULL) {
        temp = L->head;
        L->head = L->head->next;
        deallocate(temp);
    }
}

void printList(List L) {
    Node* temp = L.head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
