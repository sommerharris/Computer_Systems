#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

int main(){
int value = printStatement();
//void printCorrect( 3, value);
return 0;
}	