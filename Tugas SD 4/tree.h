#ifndef TREE_H
#define TREE_H

typedef struct Tree Tree;

Tree* createTree();
void destroyTree(Tree *t);

void createRoot(Tree *t, char jabatan[]);
void addChild(Tree *t, char parentName[], char childName[]);
void printTree(Tree *t);
int isEmpty(Tree *t);

#endif