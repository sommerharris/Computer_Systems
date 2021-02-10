#include <stdio.h>
#include <stdlib.h>

typedef struct vector{
	int* data;
	int size;
	int capacity;
}vector_t;


vector_t* makeNewVector(int initCapacity){
	vector_t* vector = (vector_t*)malloc(sizeof(vector_t));
	if ( vector == NULL ){
		return NULL;
	}
	//Allocate memory for our data array.
	vector->data = (int*)malloc(sizeof(int) * initCapacity);
	vector->size = 0;
	vector->capacity = initCapacity;
	return vector;
}

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

int resize(vector_t* vector){
	if ( vector == NULL){
		return 0;
	}

	vector->capacity = vector->capacity * 2;
	int* newData = (int*)malloc(sizeof(int) * vector->capacity);

	if ( newData == NULL || vector->data == NULL){
		return 0;
	}

	//We need to copy the data from the old array into
	//our new array.
	for( int i = 0; i < vector->size; i++){
		newData[i] = vector->data[i];
	}
	//We have to free hte old data
	//The data is already stored into the newData;
	free(vector->data);
	vector->data = newData;
	return 1;
}

int push_back(vector_t* vector, int element){
	if ( vector == NULL){
		return 0;
	}
	
	if ( vector->data == NULL ){
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
	vector->data[vector->size] = element;
	vector->size += 1;
	return 1;

}

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

//void dequeue(vector_t vector) {
	//replace last value with NULL?
//}

int main(){
	//Constructed a vector on the heap, with the help of
	//makeVector.
	vector_t* vector = makeNewVector(2);
	push_back(vector, 2);
	push_back(vector, 4);
	push_back(vector, 6);
	print(vector);
	
	//Delete the vector from the heap.
	freeVector(vector);
	return 0;
}
