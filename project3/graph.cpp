#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "heap.h"

struct VERTEX* newVertex(int color, float d, int pi) {
    struct VERTEX* vert = (struct VERTEX*) malloc(sizeof(struct VERTEX));
    vert->color = color;
    vert->d = d;
    vert->pi = pi;
    return vert;
}


struct AdjListNode* newAdjListNode(int dest, float weight) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode) );
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}
struct Graph* createGraph(int V){
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
    int i;
    for (i = 1; i <= V; ++i)
        graph->array[i].head = NULL;
    return graph;
}