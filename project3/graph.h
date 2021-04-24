
struct VERTEX {
    int color;  //when it changes from white to grey, needs to be added to array. when black gets extracted?
    int pi;
    float d;  // the key 
    int pos; //index in the heap array
};

struct AdjListNode {
    int dest;
    float weight;
    struct AdjListNode* next;
};

struct AdjList {
    struct AdjListNode* head;
};

struct Graph { //array of adjecency lists, V is number of verticies
    int V;
    struct AdjList* array;
};

struct AdjListNode* newAdjListNode(int dest, float weight);
struct Graph* createGraph(int V);
struct VERTEX* newVertex(int color, float d, int pi);