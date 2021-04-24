
void printGraph(struct Graph* graph);
void addEdge(struct Graph* graph, int src, int dest, float weight, int dFlag);
void deleteAll(int vertices, struct Graph* graph);
//void readFromFile(std::string fileName);
void printArr(int dist[], int n);
int dij(struct Graph* graph, struct VERTEX* vert, int s, int t, int flag);
void printPath(int source, int destination, struct VERTEX* vert);
void readFromFile(Graph *graph, std::string fileName, std::string direction);
