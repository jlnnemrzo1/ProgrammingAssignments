#include <stdio.h>

int main(){
int array[10];
int i;

for(i = 0; i < 10; i++){ //stores values into an array
	array[i] = i;
}

for(i = 0; i < 10; i++){ //prints the array
	printf("\nNumber[%d]: ", i);
	printf("%d", array[i]);
}
return 0;
}
