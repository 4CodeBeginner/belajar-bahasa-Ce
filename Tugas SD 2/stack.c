#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void initStack(Stack* s) {
    s->top = NULL;
    s->curSize = 0;
}

int isEmptyStack(Stack* s) {
    return (s->top == NULL);
}

int isFullStack(Stack* s) {
    return (s->curSize == SIZE_INIT);
}

void push(Stack* s, int value) {
    if (isFullStack(s)) {
        printf("Stack FULL!\n");
        return;
    }

    Node* newElement = (Node*)malloc(sizeof(Node));
    newElement->data = value;
    newElement->next = s->top;
    s->top = newElement;
    s->curSize++;
}

int pop(Stack* s) {
    if (isEmptyStack(s)) {
        printf("Stack EMPTY!\n");
        return -1;
    }

    Node* temp = s->top;
    int value = temp->data;

    s->top = temp->next;
    free(temp);
    s->curSize--;

    return value;
}

int top(Stack* s) {
    if (isEmptyStack(s)) {
        printf("Stack EMPTY!\n");
        return -1;
    }

    return s->top->data;
}

void freeStack(Stack* s) {
    while (!isEmptyStack(s)) {
        pop(s);
    }
}
