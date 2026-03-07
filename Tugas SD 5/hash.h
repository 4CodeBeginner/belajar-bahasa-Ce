#ifndef HASH_H
#define HASH_H

#define TABLE_SIZE 10

typedef struct Node
{
    int key;
    char value[50];
    struct Node *next;
} Node;

typedef struct
{
    Node *table[TABLE_SIZE];
} HashMap;

void initHashMap(HashMap *map);
int hashFunction(int key);
void insert(HashMap *map, int key, char value[]);
void search(HashMap *map, int key);
void deleteNode(HashMap *map, int key);
void display(HashMap *map);

#endif