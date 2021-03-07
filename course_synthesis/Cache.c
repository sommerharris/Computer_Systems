#include <stdio.h>
#include <stdlib.h>

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

//Cache method declarations
cache_t* implementCache(int capacity);

//DLL method declarations
dlist_t* makeDList(int capacity);
node_t* makeNode(int key, int data);
void freeNode(node_t* node);
void freeDList(dlist_t* dlist);
void printList(dlist_t* dlist); //does this print a list or a node?
int push_front(dlist_t* dlist, int key, int value); //make sure key is integrated
int dequeue(dlist_t* dlist);

//Array method declarations
vector_t* makeNewVector(int initCapacity);
void freeVector(vector_t* vector);
void print(vector_t* vector);
int insert(vector_t* vector , int pos, node_t* p_value);
int push_front_vector(vector_t* vector, node_t* p_value);
void removeList(vector_t* vector, int position);
node_t* get(vector_t* vector, int position);
int push_back(vector_t* vector, node_t* p_value);
int resize(vector_t* vector);

//make methods
vector_t* makeNewVector(int initCapacity){
	vector_t* vector = (vector_t*)malloc(sizeof(vector_t));
	if ( vector == NULL ){
		return NULL;
	}
	vector->p_value = (int*)malloc(sizeof(int) * initCapacity);
	vector->size = 0;
	vector->capacity = initCapacity;
	return vector;
}

node_t* makeNode(int key, int data){ //make sure key is integrated
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	if ( newNode == NULL){
		return NULL;
	}
    newNode->key = key;
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
	if ( vector->p_value != NULL){
		free(vector->p_value);
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

	if ( vector->p_value == NULL )
		return;

	for ( int i = 0; i < vector->size; i++){
		printf("%d ", vector->p_value[i]);
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

//adding/removing methods
int push_front(dlist_t* dlist, int key, int value){//integrate key fully
	if ( dlist == NULL){
			return 0;
	}
	node_t* newNode = makeNode(key, value);
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

int dequeue(dlist_t* dlist){
	if (dlist == NULL){
		return NULL;
	}
	if (dlist->head == NULL && dlist->tail == NULL){
		return NULL;
	}
	node_t* currentHead = dlist->head;
	int data = currentHead->data;

	dlist->head = currentHead->next;
	dlist->size -= 1;

	free(currentHead);

	return data;
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

	if ( vector->p_value == NULL ){
		return 0;
	}

	for (int i = vector->size-1; i >= pos; i--){
		vector->p_value[i+1] = vector->p_value[i];
	}
    //just added star in front of p_value
	vector->p_value[pos] = *p_value;
	vector->size += 1;
	return 1;
}

int push_front_vector(vector_t* vector, node_t* p_value){ //make sure name is correct everywhere
	return insert(vector, 0, p_value);
}

void removeList(vector_t* vector, int position){
	if (vector->size == 0){
		return;
	}
	int i = position;
	for(i; i < vector->size; i++){
		vector->p_value[i] = vector->p_value[i+1];
	}
	vector->size -= 1;
	return;
}

node_t* get(vector_t* vector, int position){
    if (vector->size == 0){
        return NULL;
    }
    //return vector->p_value[position];
    //add new material instead of above line
    node_t returnValue = vector->p_value[position];
    return &returnValue;
    //end of add new

}

int push_back(vector_t* vector, node_t* p_value){
	if ( vector == NULL){
		return 0;
	}
	
	if ( vector->p_value == NULL ){
		return 0;
	}

	//check to make sure that we have enough room
	//do we have to resize our data array?
	if ( vector->size == vector->capacity){
		int resizeSuccess = resize(vector);
		if (resizeSuccess== 0){
			return 0;
		}
	}
	//Lets go ahead and append to the back of the array;
    //added star before p_value to dereference
	vector->p_value[vector->size] = *p_value;
	vector->size += 1;
	return 1;
}

int resize(vector_t* vector){
	if ( vector == NULL){
		return 0;
	}

	vector->capacity = vector->capacity * 2;
	node_t* newNodeArray = (node_t*)malloc(sizeof(node_t) * vector->capacity);

	if ( newNodeArray == NULL || vector->p_value == NULL){
		return 0;
	}

	//We need to copy the data from the old array into
	//our new array.
	for( int i = 0; i < vector->size; i++){
		newNodeArray[i] = vector->p_value[i];
	}
	//We have to free hte old data
	//The data is already stored into the newData;
	free(vector->p_value);
	vector->p_value = newNodeArray;
	return 1;
}

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
    if (newCache->size >= key) {//if key exists
        //use index(key) element in array with pointer to find node that has value
        node_t* valueNode = get(newCache->hashmap, key);
        //update value on actual node --don't need to update pointer here because we can use same node
        valueNode->data = value;
        //move value node to front of singly linked list:
        //if node's prev = NULL, return
        if (valueNode->previous == NULL) {
            return 0;
        }
        //link nodes on either side together (if next = null, link to null)
        node_t* previousNode = valueNode->previous;
        if (valueNode->next == NULL) {
            previousNode->next = NULL;
        }
        node_t* nextNode = valueNode->next; //are these node* or node_t*??
        previousNode->next = nextNode;
        nextNode->previous = valueNode->previous;
        //link value node to front of list
        valueNode->next = newCache->dll->head;
        valueNode->previous = NULL;
        return 0;
    }
    if (newCache->size = newCache->capacity) {
        //get index with pointer to tail node (from key on tail node)
        node_t* tailNode = newCache->dll->tail;
        int keyIndex = tailNode->key;
        //delete tail pointer from array
        vector_t* vector = newCache->hashmap;
        removeList(vector, keyIndex);
        //delete tail node
        dlist_t* dlist = newCache->dll;
        dequeue(dlist);
    }
    //put value node at front of the list
    dlist_t* dlist = newCache->dll;
    push_front(dlist, key, value);//should I add key as an attribute here?
    //take address of node
    node_t* frontAddress = newCache->dll->head;
    //put address at key index in list
    vector_t* vector = newCache->hashmap;
    insert(vector , key, frontAddress); //need to have initialized the array with null values but at capacity
    return 0;
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
