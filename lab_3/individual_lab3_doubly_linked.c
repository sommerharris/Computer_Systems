//This file was created with influence from Vido's videos, and from the work of my teammates, Ian and Yichen
//This file still needs a testing harness, and additional functions mentioned in the assignment

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
	struct node* previous;
}node_t;

typedef struct dlist{
	node_t* head;
	node_t* tail;
	int size;
}dlist_t;

node_t* makeNode(int data);
void freeNode(node_t* node);
void printList(dlist_t* dlist);

int push_front(dlist_t* dlist, int value);
int push_rear(dlist_t* dlist, int value);
void enqueue(dlist_t* dlist, int data);
int dequeue(dlist_t* dlist);

dlist_t* makeDList();

node_t* makeNode(int data){
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	if ( newNode == NULL){
		return NULL;
	}
	newNode->data = data;
	return newNode;
}

dlist_t* makeDList(){
	dlist_t* newList = (dlist_t*)malloc(sizeof(dlist_t));
	if ( newList != NULL){
		return;
	}

	newList->head = NULL;
	newList->tail = NULL;
	newList->size = 0;
	return newList;
}

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
		//need to add address of head to itself's previous before moving
		node_t* currentHead = dlist->head;
		currentHead->previous = dlist->head;
		//is this right?
		newNode->next = dlist->head;
		newNode->previous = NULL;
		dlist->head = newNode;
		dlist->size += 1;

		return 0;
	}
}

int push_rear(dlist_t* dlist, int value){
	if ( dlist == NULL){
		return 0;
	}
	node_t* newNode = makeNode(value);
	newNode->next = NULL;

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
		//added now
		node_t* currentTail = dlist->tail;
		currentTail->previous = dlist->tail;
		//added now
		newNode->previous = dlist->tail;
		newNode->next = NULL;
		dlist->tail = newNode;
		dlist->size += 1;

		return 0;
	}
}

void enqueue(dlist_t* dlist, int data){
	push_rear(dlist, data);
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

void printList(dlist_t* dlist){
	node_t* itr =dlist->head;

	while (itr != NULL){
		printf("%d ", itr->data);
		itr = itr->next;
	}
	printf("\n");
}

int main(){
dlist_t* dlist1 = makeDList();
push_front(dlist1, 2);
//enqueue(dlist1, 3);
//enqueue(dlist1, 5);
printList(dlist1);
//dequeue(dlist1);
printList(dlist1);

//freeDList(dlist1);
return 0;
}		
