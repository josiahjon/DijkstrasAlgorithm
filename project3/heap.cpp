#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "graph.h"
#include "heap.h"

struct MinHeapNode* newMinHeapNode(int v, float dist, VERTEX* vert){
    struct MinHeapNode* minHeapNode = (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    minHeapNode->v = v;
    minHeapNode->dist = dist;
    vert[v].color = 1;
    return minHeapNode;
}
struct MinHeap* createMinHeap(int capacity){
    struct MinHeap* minHeap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**) malloc(capacity *sizeof(struct MinHeapNode*));
    return minHeap;
}

// node swap
void swapMinHeapNode(struct MinHeap* minHeap, int index, int smallest, VERTEX* vert){
    MinHeapNode *buffer = minHeap->array[index];
    int positionBuffer = vert[index].pos;
    vert[index].pos = vert[smallest].pos;
    vert[smallest].pos = positionBuffer;
    minHeap->array[index] = minHeap->array[smallest];
    minHeap->array[smallest] = buffer;
  
}

// minheapify the min heap
void minHeapify(struct MinHeap* minHeap, int idx, VERTEX *vert){
    int smallest, left, right;
    
    left = 2 * idx;
    right = 2 * idx + 1;
    smallest = idx;

    if (left <= minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist)
        smallest = left;

    if (right <= minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx){
        // Swap nodes
        swapMinHeapNode(minHeap, idx, smallest, vert);
        minHeapify(minHeap, smallest, vert);
    }
}
// check if heap is empty
int isEmpty(struct MinHeap* minHeap){
    return minHeap->size == 0;
}

// extracted minimum from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap, VERTEX* vert){
    if (isEmpty(minHeap)) {
        return NULL;
    }
    // Store the root node
    struct MinHeapNode* root = minHeap->array[1];
    // Replace root node with last node
    struct MinHeapNode* lastNode = minHeap->array[minHeap->size];
    minHeap->array[1] = lastNode;

    // Reduce heap size and heapify root
    --minHeap->size;
    minHeapify(minHeap, 1, vert);
    
    return root;
}

// Decrease the distance at a given vertex and update 
void decreaseKey(struct MinHeap* minHeap, int v, float dist, VERTEX* vert, int flag) {
    int newKey = dist;
    int previousKey = minHeap->array[v]->dist;
   
    // Get the node and update its dist value
    minHeap->array[v]->dist = dist;

    int parent = v / 2;
    
    // Travel up 
    while (v > 1 && minHeap->array[v]->dist < minHeap->array[v/2]->dist) {
        // Swap this node with parent
        swapMinHeapNode(minHeap, v, v/2, vert);


    }
}
void buildMinHeap(struct MinHeap* minHeap, VERTEX *vert) {
    int heapSize;
    heapSize = minHeap->size;
    for (int i = heapSize ; i > 0; i--) {
        minHeapify(minHeap, i, vert);
    }
}
