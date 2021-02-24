typedef struct vector{
	int* data;
	int size;
	int capacity;
}vector_t;

vector_t* makeNewVector(int initCapacity);

void freeVector(vector_t* vector);

int resize(vector_t* vector);

int push_back(vector_T* vector, int element);

int insert(vector_t* vector, int pos, int element);

int push_front(vector_t* vector, int element);

void print(vector_t* vector);

void enqueue(vector_t* vector, int data);

void removeList(vector_t* vector, int position);

int dequeue(vector_t* vector);

vector_t* createHeap();

vector_t* orderHeap();

int addNode(vector_t* heap, int data);

int deleteNode(vector_t* heap);


