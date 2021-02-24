//This file was inspired by collaboration with my teammates, Ian and Yichen. Much of this code is the same as our collective test file.
//This file may not work yet as my max_heap file is still very buggy.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "max_heap.h"

void max_heapCorrect(int expected, int actual){

	if (expected == actual){
		return;
	}
	else{
		printf("Max fail\n");
		return;
	}
}

void validMax_heap(vector_t* heap){

	for (int i = heap->size -1; i > 1; i--){
		if(heap->data[i/2] < heap->data[i]){
		printf("1: %d \n", heap->data[i/2], heap->data[i]);
		printf("fail\n");
		}
	}
}

int main(){

	vector_t* vector = createHeap();

	addNode(vector, 5);
	addNode(vector, 7);
	addNode(vector, 9);
	addNode(vector, 3);
	addNode(vector, 15);
	max_heapCorrect(15, vector->data[1]);

	validMax_heap(vector);
	print(vector);
	deleteNode(vector);
	print(vector);
	deleteNode(vector);
	print(vector);

	freeVector(vector);
	printf("end\n");

	return 0;
}
