//this will be the cache headerfile

//node built here
typedef struct node{
	int data;
    int key; //make sure this is integrated
	struct node* next;
	struct node* previous;
}node_t;

//dlist built here
typedef struct dlist{
	node_t* head;
	node_t* tail;
	int size;
    int capacity;
}dlist_t;

//vector array for hashtable built here
typedef struct vector{
	node_t* p_value;
	int size;
	int capacity;
}vector_t;

//Cache built here
typedef struct cache{
	dlist_t* dll;
	vector_t* hashmap;
    int size;
	int capacity;
}cache_t;

//dlist functions
int dequeue(dlist_t* dlist);
int push_front(dlist_t* dlist, int key, int value);
void printList(dlist_t* dlist);
void freeDList(dlist_t* dlist);
void freeNode(node_t* node);
dlist_t* makeDList(capacity);
node_t* makeNode(int key, int data);

//vector functions
int resize(vector_t* vector);
int push_back(vector_t* vector, node_t* p_value);
node_t* getValue(vector_t* vector, int position);
void removeList(vector_t* vector, int position);
int push_front_vector(vector_t* vector, node_t* p_value);
int insert(vector_t* vector , int pos, node_t* p_value);
void print(vector_t* vector);
void freeVector(vector_t* vector);
vector_t* makeNewVector(int initCapacity);

//Cache functions
void printCache(cache_t* newCache);
int get(cache_t* newCache, int key);
int put(cache_t* newCache, int key, int value);
void freeCache(cache_t* newCache);
cache_t* implementCache(int capacity);