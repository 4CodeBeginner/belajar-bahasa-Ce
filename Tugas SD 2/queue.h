#ifndef QUEUE_H
#define QUEUE_H

#define SIZE_INIT 5

typedef struct NodeQ {
    int data;
    struct NodeQ* next;
} NodeQ;

typedef struct {
    NodeQ* head;
    NodeQ* tail;
    int curSize;
} Queue;

void initQueue(Queue* q);
int isEmptyQueue(Queue* q);
int isFullQueue(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int headQueue(Queue* q);
int tailQueue(Queue* q);
void freeQueue(Queue* q);

#endif
