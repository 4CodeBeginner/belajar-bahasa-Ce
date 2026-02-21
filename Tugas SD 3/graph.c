#include "graph.h"

AdjNode* createNode(int dest, int weight) {
    AdjNode* newNode = (AdjNode*) malloc(sizeof(AdjNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

void setLocationName(Graph* graph, int index, char name[]) {
    strcpy(graph->location[index], name);
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    AdjNode* newNode = createNode(dest, weight);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        AdjNode* temp = graph->adjLists[v];
        printf("%s:", graph->location[v]);

        while (temp) {
            printf(" -> (%s, %d km)", 
                   graph->location[temp->dest], 
                   temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        AdjNode* temp = graph->adjLists[i];
        while (temp) {
            AdjNode* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(graph);
}