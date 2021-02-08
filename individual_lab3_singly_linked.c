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
	slist_t* newList = (slist_t*)malloc(sizeof(slist));
	if ( newList != NULL){
		return;
	}

	newList->head = NULL;
	newList->tail = NULL;
	newList->size = 0;
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
	//2. if the head is not NULL, then the next pointer of NewNode 
	//will point to the head, and the head will become the NewNode.
	//--when we free the list we have to free every node inside the list.
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


int main(){
	node_t* node1 = makeNode(1);
	node_t* node2 = makeNode(2);
	node_t* node3 = makeNode(3);

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	printNodes(node1);

	freeNode(node1);
	freeNode(node2);
	freeNode(node3);
	return 0;
}
