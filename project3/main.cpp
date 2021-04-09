#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

struct AdjListNode{
    int dest;
    int weight;
    struct AdjListNode* next;
};

struct AdjList{
    struct AdjListNode* head;
};

struct Graph{
    int V;
    struct AdjList* array;
};
struct AdjListNode* newAdjListNode(int dest){
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}


struct Graph* createGraph(int vertices){
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = vertices; 
    graph->array = (struct AdjList*) malloc(vertices * sizeof(struct AdjList));
    int i;
    for (i = 0; i < vertices; ++i)
        graph->array[i].head = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight){
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    newNode->weight = weight;
    graph->array[src].head = newNode;
    
    //if undirected, same back
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void readFromFile(std::string fileName){
    int vertices;
    int edges;
    int edgeID;
    int vertexu;
    int vertexv;
    int weight;

    std::ifstream inFile("network01.txt");
    if (inFile.is_open()) {
        inFile >> vertices;
        inFile >> edges;
        //pNODE* A;
        //char* theVertices = (char*)malloc(sizeof(int) *vertices);
        //char* a = new char[vertices];
       // A = (pNODE*)calloc(vertices + 1, sizeof(pNODE));
        //NODE* pointer = new NODE[vertices];
        /*for (int i = 0; i < edges; i++) {
            // a[i] = i + 1;
         }*/
        struct Graph* graph = createGraph(vertices);
        for (int i = 0; i < edges; i++) {
            inFile >> edgeID;
            inFile >> vertexu;
            inFile >> vertexv;
            inFile >> weight;
            addEdge(graph, vertexu, vertexv, weight);
        }
    }
    else {
        std::cout << "Error: cannot open file for reading" << std::endl;
    }
}
void command() {
    std::string fileName;
    std::string weight;
    while (true) {
        std::cin >> fileName;
        std::cin >> weight;
        readFromFile(fileName);
    }
}

int main() {
    command();
    return 0;
}