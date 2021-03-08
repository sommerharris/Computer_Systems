#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include "print_test.h"

void printCorrect(int expected, int actual){
	if (expected == actual){
		return;
	}
	else{
		printf("Print fail\n");
		return;
	}
}

void* task1(){
          for ( int i = 0; i < 100; i++){
			printStatement();	
            printf("Running task1: %d\n", i);
          }
          return NULL;
}

int main(){
//int value = printStatement();
task1();
//void printCorrect( 3, value);
return 0;
}	