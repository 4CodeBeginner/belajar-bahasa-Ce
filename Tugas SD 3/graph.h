#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME 50

typedef struct AdjNode {
    int dest;
    int weight;
    struct AdjNode* next;
} AdjNode;

typedef struct {
    int numVertices;
    char location[MAX_NODES][MAX_NAME];  // Nama lokasi
    AdjNode* adjLists[MAX_NODES];
} Graph;

Graph* createGraph(int vertices);
void setLocationName(Graph* graph, int index, char name[]);
void addEdge(Graph* graph, int src, int dest, int weight);
void printGraph(Graph* graph);
void freeGraph(Graph* graph);

#endif