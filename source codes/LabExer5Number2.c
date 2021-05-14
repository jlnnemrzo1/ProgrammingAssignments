/* Julienne Elyze P. Marzo 2020-10718 
“Upon my honor, I have accomplished this laboratory exercise relying upon my own honest efforts without cheating.” */

#include <stdio.h>

int main(){
int array[10], secondarray[10];
int test, i;

for(i = 0; i < 10; i++){ //to store values in the array
	array[i] = i;
}
	printf("\nFirst array: \n");
for(i = 0; i < 10; i++){ //prints first array
	printf("\nNumber[%d]: ", i);
	printf("%d", array[i]);
}
secondarray[i] = array[i]; //takes the values in the first array into another array
for(i = 0; i < 10; i++){ 
	secondarray[i] = i+10; //values of the second array plus 10
}
printf("\n\nSecond array: \n");
for(i = 0; i < 10; i++){ //prints the second array
	printf("\nNumber[%d]: ", i);
	printf("%d", secondarray[i]);
}
return 0;
}
