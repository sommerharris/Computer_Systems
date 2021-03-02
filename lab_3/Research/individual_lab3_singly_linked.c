//This file was created with help from Vido's videos, and with inspiration from my teammates, Ian and Yichen.
//This file contains code that was written by my teammates, and adapted by me to fit this file.
//This file still needs several functions, as well as a testing harness added to it.

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node_t;

typedef struct slist{
	node_t* head;
	node_t* tail;
	int size;
}slist_t;

slist_t* makeSList(){
	slist_t* newList = (slist_t*)malloc(sizeof(slist_t));
	if ( newList == NULL){
		return NULL;
	}//is there an error here? my teammates did it differently than vido.

	newList->head = NULL;
	newList->tail = NULL;
	newList->size = 0;
	return newList;
}


int push_front(slist_t* slist, int value){
	if ( slist == NULL ){
		return 0;
	}

	node_t* newNode = makeNode(value);
	if ( newNode == NULL ){
		return 0;
	}

	//1. if the head and tail are both NULL
	//then the heas and the tail will be come the new node
	if ( slist->head == NULL && slist->tail == NULL){

		slist->head = newNode;
		slist->tail - newNode;
		slist->size += 1;
		newNode->next = NULL;

		return 0;
	}
	//2. if the head is not NULL, then the next pointer of NewNode 
	//will point to the head, and the head will become the NewNode.
	//--when we free the list we have to free every node inside the list.
	else{
		newNode->next = slist->head;
		slist->head = newNode;
		slist->size += 1;

		return 0;
	}
}

int push_rear(slist_t* slist, int value){
	if ( slist== NULL){
		return 0;
	}
	node_t* newNode = makeNode(value);
	newNode->next = NULL;

	if ( newNode == NULL){
		return 0;
	}

	//with an empty list, pushing the rear does nothing
	if (slist->head == NULL && slist->tail == NULL){

		slist->head = newNode;
		slist->tail = newNode;
		slist->size += 1;

		return 0;
	}

	else{
		node_t* tail = slist->tail;
		//tail to new node
		tail->next = newNode;
		//change tail
		slist->tail = newNode;
		//increase slist size
		slist->size += 1;

		return 0;
	}
}

void enqueue(slist_t* slist, int data){
	push_rear(slist, data);
}

int dequeue(slist_t* slist){
	if ( slist == NULL){
		return NULL;
	}
	if (slist->head == NULL && slist->tail == NULL){
		return NULL;
	}
	//current head is stored
	node_t* currentHead = slist->head;
	int data = currentHead->data;

	//head reassigned to next value
	slist->head = currentHead->next;
	//decrease size
	slist->size -= 1;

	//free head
	free(currentHead);

	return data;

}

//Let's see what happens when node is node1 ( from main)
void printNodes(node_t* node) {

	node_t* itr = node; //itr = &node1;
	while( itr != NULL ){
			//(&node1)->data, 1
		printf("%d ", itr->data);
		itr = itr->next;
		//itr = (&node1)->next;
	}
	printf("\n");
}

node_t* makeNode(int data){
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	if ( newNode == NULL ){
		return NULL;
	}

	newNode->data = data;
	return newNode;
}

void freeNode(node_t* node){
	if ( node == NULL ){
		return;
	}

	free(node);
}

void freeSlist(slist_t* slist){
	if (slist == NULL){
		return;
	}
	node_t* itr = slist->head;
	node_t* prev;
	while(itr != NULL){
		prev = itr;
		itr = itr->next;
		freeNode(prev);
	}

	free(slist);

}

int main(){
	slist_t* slist1 = makeSList();
	push_front(slist1, 2);
	enqueue(slist1, 3);
	enqueue(slist1, 5);
	printList(slist1);
	printf("%p\n", slist1->size);

	freeSlist(slist1);
	return 0;
}
