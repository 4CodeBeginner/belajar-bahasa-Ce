#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void initQueue(Queue* q) {
    q->head = NULL;
    q->tail = NULL;
    q->curSize = 0;
}

int isEmptyQueue(Queue* q) {
    return (q->head == NULL);
}

int isFullQueue(Queue* q) {
    return (q->curSize == SIZE_INIT);
}

void enqueue(Queue* q, int value) {
    if (isFullQueue(q)) {
        printf("Queue FULL!\n");
        return;
    }

    NodeQ* element = (NodeQ*)malloc(sizeof(NodeQ));
    element->data = value;
    element->next = NULL;

    if (isEmptyQueue(q)) {
        q->head = element;
        q->tail = element;
    } else {
        q->tail->next = element;
        q->tail = element;
    }

    q->curSize++;
}

int dequeue(Queue* q) {
    if (isEmptyQueue(q)) {
        printf("Queue EMPTY!\n");
        return -1;
    }

    NodeQ* curhead = q->head;
    int value = curhead->data;

    q->head = curhead->next;

    if (q->head == NULL) {
        q->tail = NULL;
    }

    free(curhead);
    q->curSize--;

    return value;
}

int headQueue(Queue* q) {
    if (isEmptyQueue(q)) {
        printf("Queue EMPTY!\n");
        return -1;
    }

    return q->head->data;
}

int tailQueue(Queue* q) {
    if (isEmptyQueue(q)) {
        printf("Queue EMPTY!\n");
        return -1;
    }

    return q->tail->data;
}

void freeQueue(Queue* q) {
    while (!isEmptyQueue(q)) {
        dequeue(q);
    }
}
