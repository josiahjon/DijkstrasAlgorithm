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
#include "main.h"


void command() {
    std::string fileName;
    std::string direction;
    int dFlag;
    std::cin >> fileName;
    std::cin >> direction;
    bool findCommandDone = false;
    int commandSourceW = 0;
    int commandDestinationW = 0;
    int flag = 0;
    int commandSource = 0;
    int commandDestination = 0;
    int vertices;
    int edges;
    int edgeID;
    int vertexu;
    int vertexv;
    float weight;
    std::string command1;
    std::string command2;
    if (direction == "directed") {
            dFlag = 1;
        }
    else {
            dFlag = 0;
        }
    std::ifstream inFile(fileName);
    inFile >> vertices;
    inFile >> edges;
    struct Graph* graph = createGraph(vertices);
    for (int i = 1; i <= edges; i++) {
            inFile >> edgeID;
            inFile >> vertexu;
            inFile >> vertexv;
            inFile >> weight;
            addEdge(graph, vertexu, vertexv, weight, dFlag);
    }
    int i;
    VERTEX* vert = new VERTEX[vertices + 1];
    for (i = 1; i <= vertices; i++) {
            vert[i].color = 0;
            vert[i].pi = 0;
            vert[i].d = FLT_MAX;

    }
    while (true) {
    
        std::cin >> command1;
        if (command1 == "find") {

            std::cin >> commandSource;
            std::cin >> commandDestination;
            std::cin >> flag;
            std::cout << "Query: find " << commandSource 
                      << " "            << commandDestination
                      << " "            << flag << std::endl;
            dij(graph, vert ,commandSource, commandDestination, flag);
            findCommandDone = true;
        }
        if (command1 == "write") {
            std::cin >> command2;
            std::cin >> commandSourceW;
            std::cin >> commandDestinationW;
            if (findCommandDone == false) {
                printf("Error: no path computation done\n");
            }
            else {
                if (commandSourceW != commandSource) {
                    printf("Error: invalid source destination pair\n");
                }
                else {
                    std::cout << "Query: write path " << commandSourceW
                              << " "                  << commandDestinationW
                              << std::endl;
                    printPath(commandSourceW, commandDestinationW, vert);
                }
            }
           
        }
        if (command1 == "stop") {
            free(graph);
            free(vert);
            return;
        }
    }
}

int main() {
    command();
    return 0;
}