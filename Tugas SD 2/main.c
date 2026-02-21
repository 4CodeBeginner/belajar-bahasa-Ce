#include <stdio.h>
#include "stack.h"
#include "queue.h"

int main() {

    Stack s;
    Queue q;

    initStack(&s);
    initQueue(&q);

    printf("=== STACK ===\n");
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top: %d\n", top(&s));
    printf("Pop: %d\n", pop(&s));
    printf("Top setelah pop: %d\n", top(&s));

    printf("\n=== QUEUE ===\n");
    enqueue(&q, 100);
    enqueue(&q, 200);
    enqueue(&q, 300);

    printf("Head: %d\n", headQueue(&q));
    printf("Tail: %d\n", tailQueue(&q));
    printf("Dequeue: %d\n", dequeue(&q));
    printf("Head setelah dequeue: %d\n", headQueue(&q));

    freeStack(&s);
    freeQueue(&q);

    return 0;
}
