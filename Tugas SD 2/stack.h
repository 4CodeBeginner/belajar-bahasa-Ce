#ifndef STACK_H
#define STACK_H

#define SIZE_INIT 5

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
    int curSize;
} Stack;

void initStack(Stack* s);
int isEmptyStack(Stack* s);
int isFullStack(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int top(Stack* s);
void freeStack(Stack* s);

#endif
