#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include "util.h"
#include "graph.h"
#include "heap.h"



void addEdge(struct Graph* graph, int src, int dest, float weight, int dFlag) {
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    newNode->weight = weight;
    graph->array[src].head = newNode;
    
    if (dFlag == 0) {
        //if undirected, same back
        newNode = newAdjListNode(src, weight);
        newNode->next = graph->array[dest].head;
        graph->array[dest].head = newNode;
    }
}

void printGraph(struct Graph* graph)
{
    int v;
    for (v = 1; v <= graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head ;
        printf("\n Adjacency list of vertex %d\n ", v);
        while (pCrawl)
        {
            printf(" head -> %d distance -> %f |", pCrawl->dest, pCrawl->weight);

            pCrawl = pCrawl->next;
        }
        printf("\n");
    }

}

void deleteAll(int vertices, struct Graph* graph, struct VERTEX* vert) {
    int i;
    for (i = 1; i <= vertices; i++) {
        delete graph->array[i].head;
    }
}

void printPath(int source, int destination, struct VERTEX* vert) {
    int v1 = source;
    int v2 = destination;
    std::vector<int>path;
    std::vector<float>weights;
    if (vert[destination].color == 0) {
        printf("No %d-%d path exists.\n", source, destination);
        return;
    }
    if (vert[destination].color == 2 && vert[destination].pi == 0) {
        printf("No %d-%d path exists.\n", source, destination);
        return;
    }
    
    while (v1 != v2) {
        path.push_back(vert[v2].pi);
        v2 = vert[v2].pi;
    }
    if (vert[destination].color == 2 && vert[destination].pi != 0) {
        printf("Shortest path: <");
        for (auto ir = path.rbegin(); ir != path.rend(); ++ir) {
            std::cout << *ir << ", ";
        }
        std::cout << destination << ">";
        printf("\nThe path weight is: %12.4f\n", vert[destination].d);
    }
    if (vert[destination].color == 1) {
        printf("Path not known to be shortest: <");
        for (auto ir = path.rbegin(); ir != path.rend(); ++ir) {
            std::cout << *ir << ", ";
        }
        std::cout << destination << ">";
        printf("\nThe path weight is: %12.4f\n", vert[destination].d);
    }
    
    
    else return;
}


int dij(struct Graph* graph, struct VERTEX *vert, int s, int t, int flag) {
    
    // Get the number of vertices in graph
        int V = graph->V + 1;
        int i;
        float previousKey;
        float newKey;
       
        // create a min heap
        struct MinHeap* minHeap = createMinHeap(V);

     
        // set source dist to 0, extract first
        minHeap->array[1] = newMinHeapNode(s, vert[s].d, vert);
        if (flag == 1) {
            printf("Insert vertex %d, key=%12.4f\n", s, 0);
        }
        minHeap->size++;
        previousKey = vert[s].d;
        newKey = 0;
    
        vert[s].d = 0;
        vert[s].color = 1;
        vert[s].pos = 1;
        decreaseKey(minHeap, s, vert[s].d, vert, flag);
        
        // keep runing until heap is empty or source done
        while (!isEmpty(minHeap)){
            
            // Extract the vertex with minimum distance value
            struct MinHeapNode* minHeapNode = extractMin(minHeap, vert);
            // Store the extracted vertex number
            int u = minHeapNode->v;
            vert[u].color = 2;
            if (flag == 1) {
                printf("Delete vertex %d, key=%12.4f\n", u, vert[u].d);
            }
            if (u == t) {
                break;
            }
            free(minHeapNode);

         
            
            // Traverse through all adjacent vertices of u and gather distance values
            struct AdjListNode* pCrawl = graph->array[u].head;
            while (pCrawl != NULL){
                int v = pCrawl->dest;
                if (vert[v].color == 0) {
                    vert[v].d = vert[u].d + pCrawl->weight;
                    vert[v].pi = u;
                    vert[v].color = 1;
                    minHeap->size++;

                    minHeap->array[minHeap->size] = newMinHeapNode(v, vert[v].d, vert);
                    if (flag == 1) {
                        printf("Insert vertex %d, key=%12.4f\n", v, vert[v].d);
                    }
                    vert[v].pos = minHeap->size;
                    //printf("size of min heap is %d\n", minHeap->size);
                    //printf("Before min, item's new position is  %d\n", vert[v].pos);
                    minHeapify(minHeap, 1, vert);
                    //printf("After min, item's new position is  %d\n", vert[v].pos);
                    //printf("New spot 1 is:  %d\n", minHeap->array[1]->v);
                    
                } 
                else if (pCrawl->weight + vert[u].d < vert[v].d){
                    //(isInMinHeap(minHeap, v) &&
                    previousKey = vert[v].d;
                    newKey = pCrawl->weight + vert[u].d;
                    if (flag == 1) {
                        printf("Decrease key of vertex %d, from %12.4f to %12.4f\n", v, previousKey, newKey);
                    }
                    vert[v].d = vert[u].d + pCrawl->weight;
                    vert[v].pi = u;
                    vert[v].d = vert[u].d + pCrawl->weight;
                    vert[v].pi = u;
                    decreaseKey(minHeap, vert[v].pos, vert[v].d, vert, flag);
                }
                pCrawl = pCrawl->next;
            }
        }
        return 0;
}
