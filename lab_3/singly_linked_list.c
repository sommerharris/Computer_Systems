#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
        int data;
        struct node* next;
}node_t;

typedef struct slist{
        node_t* head;
        node_t* tail;
        int size;
}slist_t;

node_t* makeNode(int data);
void freeNode(node_t* node);
void printNodes(node_t* node);

int push_front(slist_t* slist, int value);
int push_back(slist_t* slist, int value);
void enqueue(slist_t* slist, int data);
int dequeue(slist_t* slist);

slist_t* makeSList();

slist_t* makeSList(){
    slist_t* newList = (slist_t*)malloc(sizeof(slist_t));
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
    if (slist->size == 0){

		slist->head = newNode;
		slist->tail = newNode;
		slist->size += 1;
		newNode->next = NULL;

		return 0;
	}
    else{
		newNode->next = slist->head;
		slist->head = newNode;
		slist->size += 1;

		return 0;	
	}
}

int push_back(slist_t* slist, int value){
    if ( slist == NULL){
		return 0;
	}
    node_t* newNode = makeNode(value);
    newNode->next = NULL;

    if ( newNode == NULL){
		return 0;
	}

    if (slist->size == 0) {
        slist->head = newNode;
        slist->tail = newNode;
        slist->size += 1;

        return 0;
    }
    else{
        node_t* tail = slist->tail;
        tail->next = newNode;
        slist->tail = newNode;
        slist->size += 1;

        return 0;
    }
}

void enqueue(slist_t* slist, int data){
	push_back(slist, data);
}

int dequeue(slist_t* slist){
	if ( slist == NULL){
		return NULL;
	}
	if (slist->size == 0){
		return NULL;
	}
	
	node_t* currentHead = slist->head;
	int data = currentHead->data;

	slist->head = currentHead->next;
	slist->size -= 1;
	free(currentHead);

	return data;
}

bool contains(slist_t* slist, int item){
    node_t* itr = slist->head;
    while(itr != NULL){
        if(item == itr->data){
            return true;
        }
        itr = itr->next;
    }
    return false;
}

bool isEmpty(slist_t* slist){
    if (slist->size == 0){
        return true;
    }
    return false;
}

void printList(slist_t* slist){
	printNodes(slist->head);
}

//lets see what happens when node is node1 (from main)
void printNodes(node_t* node) { 
                                //itr = &node3;
        node_t* itr = node;
        while( itr != NULL) {
                                //(&node3)->data, 1 2 3
            printf("%d ", itr->data);
            itr = itr->next;
            //itr = (&node3)->next;
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

void freeNode(node_t* node) {
    if ( node == NULL ){
            return;
    }

    free(node);
}

void freeSList(slist_t* slist) {
    if (slist == NULL) {
        return;
    }
    node_t* itr = slist->head;
    node_t* previous;
    while(itr != NULL) {
        previous = itr;
        itr = itr->next;
        freeNode(previous);
    }
    free(slist);
}

int size(slist_t* slist){
    if (slist == NULL){
        return 0;
    }
    return slist->size;
}

int add(slist_t* slist, int position, int number){
    if (position < 0|| position > slist->size){
        return 0;
    }
    if (slist == NULL){
        return 0;
    }
    node_t* newNode = makeNode(number);
    if (newNode == NULL) {
        return 0;
    }
    node_t* itr = slist->head;
    node_t* previous = NULL;

    if (position == 0){
        push_front(slist, number);
        return 0;
    }

    for (int i = 0; i < position; i++) {
        previous = itr;
        itr = itr->next;
    }
    previous->next = newNode;
    newNode->next = itr;

    slist->size += 1;

    return 0;
}

int get(slist_t* slist, int position){
    if (position > slist->size || position < 0) {
        return NULL;
    }
    if (slist == NULL){
        return NULL;
    }
    node_t* itr = slist->head;

    if (position == 0) {
        return itr->data;
    }
    for (int i = 0; i < position; i++){
        itr = itr->next;
    }
    return itr->data;
}

int removeItem(slist_t* slist, int position){
    if (slist == NULL){
        return NULL;
    }
    if (position >= slist->size || position < 0){
        return NULL;
    }
    node_t* itr = slist->head;
    node_t* previous = NULL;
    int* data;

    if (position == 0){
        data = dequeue(slist);
        return(data);
    }

    for (int i = 0; i < position; i++){
        previous = itr;
        itr = itr->next;    
    }
    previous->next = itr->next;
    slist->size -= 1;
    data = itr->data;

    if (position == slist->size -1){
        slist->tail = previous;  
    }
    freeNode(itr);
    return data;
}

int main(){
    node_t* node1 = makeNode(1);
    node_t* node2 = makeNode(2);
    node_t* node3 = makeNode(3);

    node1->next = &node2;
    node2->next = &node3;
    node3->next = NULL;

    printNodes(node1);
    
    freeNode(node1);
    freeNode(node2);
    freeNode(node3);
    return 0;
}