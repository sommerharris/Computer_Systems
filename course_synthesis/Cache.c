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
	int* data;
	int size;
	int capacity;
}vector_t;

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

int main(){
//create structures
dlist_t* dlist1 = makeDList(2);
vector_t* vector = makeNewVector(2);
//add to them
push_front(dlist1, 2);
//print them
printList(dlist1);
//free them
freeDList(dlist1);
freeVector(vector);
return 0;
}	
