#ifndef ARRAY_H
#define ARRAY_H

#include <stdbool.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int size;
} Array;

// OPERASI ADT ARRAY
void initArray(Array* A);          // init/create
bool isEmptyArray(Array A);        // isEmpty
bool isFullArray(Array A);
void insertArray(Array* A, int x); // add/insert
int searchArray(Array A, int x);   // search
void deleteArray(Array* A, int x); // del/remove
int lengthArray(Array A);          // length
void destroyArray(Array* A);       // destroy
void printArray(Array A);

#endif
