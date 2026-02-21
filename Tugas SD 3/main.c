#include "graph.h"

int main() {

    Graph* graph = createGraph(4);

    // Set nama lokasi
    setLocationName(graph, 0, "Kepanjen");
    setLocationName(graph, 1, "Suhat");
    setLocationName(graph, 2, "Sengkaling");
    setLocationName(graph, 3, "Batu");

    // Tambah jarak antar lokasi
    addEdge(graph, 0, 1, 25);
    addEdge(graph, 1, 2, 5);
    addEdge(graph, 2, 3, 10);
    addEdge(graph, 3, 0, 30);

    printGraph(graph);

    freeGraph(graph);
    return 0;
}