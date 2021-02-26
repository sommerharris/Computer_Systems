typedef struct vector{
	int* data;
	int size;
	int capacity;
}vector_t;

vector_t* makeNewVector();

void freeVector();

int resize();

int push_back();

int insert();

int push_front();

void print();

void enqueue();

void removeList();

int dequeue();


