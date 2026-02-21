#include <stdio.h>
#include "array.h"
#include "linkedlist.h"

int main() {

    // ARRAY
    Array A;
    initArray(&A);

    insertArray(&A, 5);
    insertArray(&A, 10);
    insertArray(&A, 15);

    printf("Array: ");
    printArray(A);
    printf("Length Array: %d\n", lengthArray(A));

    deleteArray(&A, 10);
    printf("Array setelah delete 10: ");
    printArray(A);

    // LINKED LIST
    List L;
    createList(&L);

    insertLast(&L, 1);
    insertLast(&L, 2);
    insertLast(&L, 3);

    printf("\nLinked List: ");
    printList(L);
    printf("Length List: %d\n", lengthList(L));

    deleteValue(&L, 2);
    printf("List setelah delete 2: ");
    printList(L);

    destroyList(&L);

    return 0;
}
