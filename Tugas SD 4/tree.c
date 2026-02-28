#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

typedef struct Node {
    char jabatan[50];
    struct Node *firstChild;
    struct Node *nextSibling;
} Node;

struct Tree {
    Node *root;
};

Node* createNode(char jabatan[]) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->jabatan, jabatan);
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}

Node* findNode(Node *root, char name[]) {
    if (root == NULL) return NULL;

    if (strcmp(root->jabatan, name) == 0)
        return root;

    Node *found = findNode(root->firstChild, name);
    if (found != NULL)
        return found;

    return findNode(root->nextSibling, name);
}

void print(Node *root, int level) {
    if (root == NULL) return;

    for (int i = 0; i < level; i++)
        printf("  ");

    printf("- %s\n", root->jabatan);

    print(root->firstChild, level + 1);
    print(root->nextSibling, level);
}

Tree* createTree() {
    Tree *t = (Tree*) malloc(sizeof(Tree));
    t->root = NULL;
    return t;
}

void destroyTree(Tree *t) {
    free(t);
}

int isEmpty(Tree *t) {
    return (t->root == NULL);
}

void createRoot(Tree *t, char jabatan[]) {
    if (t->root == NULL)
        t->root = createNode(jabatan);
    else
        printf("Root sudah ada!\n");
}

void addChild(Tree *t, char parentName[], char childName[]) {
    if (t->root == NULL) {
        printf("Tree masih kosong!\n");
        return;
    }

    Node *parent = findNode(t->root, parentName);
    if (parent == NULL) {
        printf("Parent tidak ditemukan!\n");
        return;
    }

    Node *child = createNode(childName);

    if (parent->firstChild == NULL) {
        parent->firstChild = child;
    } else {
        Node *temp = parent->firstChild;
        while (temp->nextSibling != NULL)
            temp = temp->nextSibling;

        temp->nextSibling = child;
    }
}

void printTree(Tree *t) {
    if (t->root == NULL)
        printf("Tree kosong.\n");
    else
        print(t->root, 0);
}