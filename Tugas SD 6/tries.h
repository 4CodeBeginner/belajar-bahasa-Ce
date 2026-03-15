#ifndef TRIES_H
#define TRIES_H

#define ALPHABET_SIZE 26

typedef struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    int isEndOfWord;
} TrieNode;

TrieNode *createNode();
void insertWord(TrieNode *root, char word[]);
int searchWord(TrieNode *root, char word[]);
void showPath(char word[]);

#endif