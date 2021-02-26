#include <math.h>
#include <stdio.h>

int timeDifference(int arg1, int arg2){
	return arg2 - arg1;
}	
int main(){
	int difference = timeDifference(1000, 1200);
	double rawHours = floor(difference / 100); // 100; //time needs to be written as four consecutive digits	
	double rawMinutes = difference - floor(difference / 100) * 100;
	int intRawMinutes = (int)rawMinutes;
	double hours = rawHours + floor(rawMinutes / 60);
	int minutes = intRawMinutes % 60;

	printf("Hours:, %f, Minutes:, %d\n", hours, minutes);
}
