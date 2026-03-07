#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

void initHashMap(HashMap *map)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        map->table[i] = NULL;
    }
}

int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

void insert(HashMap *map, int key, char value[])
{
    int index = hashFunction(key);

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    strcpy(newNode->value, value);
    newNode->next = map->table[index];

    map->table[index] = newNode;

    printf("Data berhasil ditambahkan\n");
}

void search(HashMap *map, int key)
{
    int index = hashFunction(key);

    Node *temp = map->table[index];

    while (temp != NULL)
    {
        if (temp->key == key)
        {
            printf("Data ditemukan: NIM %d - Nama %s\n", key, temp->value);
            return;
        }
        temp = temp->next;
    }

    printf("Data tidak ditemukan\n");
}

void deleteNode(HashMap *map, int key)
{
    int index = hashFunction(key);

    Node *temp = map->table[index];
    Node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->key == key)
        {

            if (prev == NULL)
            {
                map->table[index] = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }

            free(temp);
            printf("Data berhasil dihapus\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Data tidak ditemukan\n");
}

void display(HashMap *map)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {

        Node *temp = map->table[i];

        if (temp != NULL)
        {
            printf("Index %d : ", i);

            while (temp != NULL)
            {
                printf("[NIM:%d Nama:%s] -> ", temp->key, temp->value);
                temp = temp->next;
            }

            printf("NULL\n");
        }
    }
}