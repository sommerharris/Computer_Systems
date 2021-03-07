#include <stdio.h>
#include <stdlib.h>

//node built here
typedef struct node{
	int data;
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

//Cache method declarations
cache_t* implementCache(int capacity);

//DLL method declarations
dlist_t* makeDList(int capacity);
node_t* makeNode(int data);
void freeNode(node_t* node);
void freeDList(dlist_t* dlist);
void printList(dlist_t* dlist); //does this print a list or a node?
int push_front(dlist_t* dlist, int value);

//Array method declarations
vector_t* makeNewVector(int initCapacity);
void freeVector(vector_t* vector);
void print(vector_t* vector);

//make methods
vector_t* makeNewVector(int initCapacity){
	vector_t* vector = (vector_t*)malloc(sizeof(vector_t));
	if ( vector == NULL ){
		return NULL;
	}
	vector->data = (int*)malloc(sizeof(int) * initCapacity);
	vector->size = 0;
	vector->capacity = initCapacity;
	return vector;
}

node_t* makeNode(int data){
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	if ( newNode == NULL){
		return NULL;
	}
	newNode->data = data;
	return newNode;
}

dlist_t* makeDList(capacity){
	dlist_t* newList = (dlist_t*)malloc(sizeof(dlist_t));
	if ( newList != NULL){
		return;
	}
    newList->capacity = capacity;
	newList->head = NULL;
	newList->tail = NULL;
	newList->size = 0;
	return newList;
}

//free methods
void freeVector(vector_t* vector){
	if ( vector == NULL ){
		return;
	}
	//First delete the data array, then delete the vector.
	if ( vector->data != NULL){
		free(vector->data);
	}

	free(vector);
}

void freeNode(node_t* node){
	if ( node == NULL){
		return;
	}
	free(node);
}

void freeDList(dlist_t* dlist){
	if (dlist = NULL){
		return;
	}
	node_t* itr = dlist->head;
	node_t* prev;
	while(itr != NULL){
		prev = itr;
		itr = itr->next;
		freeNode(prev);
	}
	free(dlist);
}

//print methods
void print(vector_t* vector){
	if (vector == NULL )
		return;

	if ( vector->data == NULL )
		return;

	for ( int i = 0; i < vector->size; i++){
		printf("%d ", vector->data[i]);
	}
	printf("\n");
}

void printList(dlist_t* dlist){
	node_t* itr =dlist->head;

	while (itr != NULL){
		printf("%d ", itr->data);
		itr = itr->next;
	}
	printf("\n");
}

//adding methods
int push_front(dlist_t* dlist, int value){
	if ( dlist == NULL){
			return 0;
	}
	node_t* newNode = makeNode(value);
	if ( newNode == NULL){
		return 0;
	}
	if (dlist->size == 0){
		dlist->head = newNode;
		dlist->tail = newNode;
		dlist->size += 1;
		newNode->next = NULL;
		newNode->previous = NULL;
    
		return 0;
	}

	else{
		node_t* currentHead = dlist->head;
		currentHead->previous = dlist->head;
		newNode->next = dlist->head;
		newNode->previous = NULL;
		dlist->head = newNode;
		dlist->size += 1;

		return 0;
	}
}

int insert(vector_t* vector , int pos, node_t* p_value){
	if (vector == NULL || pos < 0){
		return 0;
	}

	if ( pos == vector->size ){
		return push_back(vector, p_value);
	}
	
	if ( vector->size == vector->capacity){
		int successOnResize = resize(vector);
		if ( successOnResize == 0){
			return 0;
		}
	}

	if ( vector->data == NULL ){
		return 0;
	}

	for (int i = vector->size-1; i >= pos; i--){
		vector->data[i+1] = vector->data[i];
	}

	vector->data[pos] = p_value;
	vector->size += 1;
	return 1;
}

int push_front(vector_t* vector, node_t* p_value){
	return insert(vector, 0, p_value);

//cache functions
cache_t* implementCache(int capacity){
    cache_t* newCache = (cache_t*)malloc(sizeof(cache_t)); 
    if ( newCache != NULL){
		return;
	}

    newCache->dll = makeDList(capacity);
    newCache->hashmap = makeNewVector(capacity);
	return newCache;
}

void freeCache(cache_t* newCache){//still getting a segfault in this function
    if (newCache = NULL){
		return;
	}
    dlist_t* dlist = newCache->dll;
    vector_t* vector = newCache->hashmap;
    freeDList(dlist);
    freeVector(vector);
}

int put(cache_t* newCache, int key, int value){
    if ( newCache == NULL){
		return -1;
    }
    //if (newCache->size >= key) {//if key exists
        
        //use index(key) element in array with pointer to find node that has value
        //update value on actual node --don't need to update pointer here because we can use same node
        //move value node to front of singly linked list
        //return
    //}
    if (newCache->size = newCache->capacity) {
        //get index with pointer to tail node
        //delete tail pointer from array
        //delete tail node
    }
    //put value node at front of the list
    dlist_t* dlist = newCache->dll;
    push_front(dlist, value);
    //take address of node
    node_t* frontAddress = newCache->dll->head;
    //put address at key index in list
    vector_t* vector = newCache->hashmap;
    insert(vector_t* vector , key, frontAddress) //need to have initialized the array with null values but at capacity
}    


int main(){
//create structures
cache_t* cache = implementCache(2);
//add to them
//push_front(dlist1, 2);
//print them
//printList(dlist1);
//free them
// freeDList(dlist1);
// freeVector(vector);
freeCache(cache);
return 0;
}	
