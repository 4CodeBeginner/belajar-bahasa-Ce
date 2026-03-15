#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tries.h"

TrieNode *createNode()
{
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
    node->isEndOfWord = 0;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;

    return node;
}

void showPath(char word[])
{
    printf("Jalur huruf dalam Trie: ");

    for (int i = 0; word[i] != '\0'; i++)
    {
        printf("%c", word[i]);

        if (word[i + 1] != '\0')
            printf(" -> ");
    }

    printf("\n");
}

void insertWord(TrieNode *root, char word[])
{
    TrieNode *current = root;

    printf("\nProses memasukkan kata \"%s\"\n", word);

    for (int i = 0; word[i] != '\0'; i++)
    {
        int index = word[i] - 'a';

        if (current->children[index] == NULL)
        {
            printf("Membuat node untuk huruf '%c'\n", word[i]);
            current->children[index] = createNode();
        }
        else
        {
            printf("Node '%c' sudah ada, lanjut\n", word[i]);
        }

        current = current->children[index];
    }

    current->isEndOfWord = 1;

    printf("Kata \"%s\" berhasil disimpan di Trie\n", word);

    showPath(word);
}

int searchWord(TrieNode *root, char word[])
{
    TrieNode *current = root;

    printf("\nMencari kata \"%s\"\n", word);

    for (int i = 0; word[i] != '\0'; i++)
    {
        int index = word[i] - 'a';

        if (current->children[index] == NULL)
        {
            printf("Huruf '%c' tidak ditemukan\n", word[i]);
            return 0;
        }

        printf("Huruf '%c' ditemukan\n", word[i]);
        current = current->children[index];
    }

    if (current->isEndOfWord)
    {
        printf("Kata lengkap ditemukan di Trie\n");
        showPath(word);
        return 1;
    }

    printf("Huruf ada tetapi bukan akhir kata\n");
    return 0;
}