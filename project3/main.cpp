#include <iostream>
#include <string>
#include <fstream>
#include <vector>

typedef struct TAG_NODE {
    int v;          //vertex
    float w;        //weight
    TAG_NODE* next;
}NODE;
typedef NODE* pNODE;

void addEdge(pNODE* A, int u, int v) {
    pNODE->v = u;
   
}

void readFromFile(std::string fileName) {
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
        pNODE* A;
        //char* theVertices = (char*)malloc(sizeof(int) *vertices);
        //char* a = new char[vertices];
        A = (pNODE*)calloc(vertices + 1, sizeof(pNODE));

        /* for (int i = 0; i < edges; i++) {
            // a[i] = i + 1;
         }*/

        for (int i = 0; i < edges; i++) {
            inFile >> edgeID;
            inFile >> vertexu;
            inFile >> vertexv;
            inFile >> weight;
            addEdge(A, vertexu, vertexv);

            std::cout << edgeID << vertexu << vertexv << weight << std::endl;
        }
        //delete[] a;
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