
struct MinHeap {
    int size; //size of heap
    int capacity; //capacity allowed
    struct MinHeapNode** array; //array of the heap where nodes are stored
};

struct MinHeapNode {
    int  v;
    float dist;
};

struct MinHeapNode* newMinHeapNode(int v, float dist, VERTEX *vert);
struct MinHeap* createMinHeap(int capacity);
void swapMinHeapNode(struct Minheap *minHeap, int index, int smallest, VERTEX *vert);
void minHeapify(struct MinHeap* minHeap, int idx, VERTEX *vert);
int isEmpty(struct MinHeap* minHeap);
struct MinHeapNode* extractMin(struct MinHeap* minHeap, VERTEX *vert);
void decreaseKey(struct MinHeap* minHeap, int v, float dist, VERTEX *vert, int flag);
bool isInMinHeap(struct MinHeap* minHeap, int v);
void buildMinHeap(struct MinHeap* minHeap, VERTEX *vert);