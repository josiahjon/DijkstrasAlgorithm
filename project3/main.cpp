#include <iostream>
#include <string>
#include <fstream>


void readFromFile(std::string fileName) {
    int vertices;
    int edges;
    int edgeID;
    std::string vertexu;
    std::string vertexv;
    int weight;

    std::ifstream inFile("fileName");
    if (inFile.is_open()) {
        inFile >> vertices;
        inFile >> edges;
        for (int i = 0; i < edges; i++) {
            inFile >> edgeID;
            inFile >> vertexu;
            inFile >> vertexv;
            inFile >> weight;
            std::cout << edgeID << vertexu << vertexv << weight << std::endl;

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