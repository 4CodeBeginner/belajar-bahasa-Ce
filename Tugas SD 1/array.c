#include <stdio.h>
#include "array.h"

void initArray(Array* A) {
    A->size = 0;
}

bool isEmptyArray(Array A) {
    return A.size == 0;
}

bool isFullArray(Array A) {
    return A.size == MAX;
}

void insertArray(Array* A, int x) {
    if (!isFullArray(*A)) {
        A->data[A->size++] = x;
    }
}

int searchArray(Array A, int x) {
    for (int i = 0; i < A.size; i++) {
        if (A.data[i] == x)
            return i;
    }
    return -1;
}

void deleteArray(Array* A, int x) {
    int idx = searchArray(*A, x);
    if (idx != -1) {
        for (int i = idx; i < A->size - 1; i++) {
            A->data[i] = A->data[i + 1];
        }
        A->size--;
    }
}

int lengthArray(Array A) {
    return A.size;
}

void destroyArray(Array* A) {
    A->size = 0;
}

void printArray(Array A) {
    for (int i = 0; i < A.size; i++) {
        printf("%d ", A.data[i]);
    }
    printf("\n");
}
