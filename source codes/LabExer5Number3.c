/* Julienne Elyze P. Marzo 2020-10718 
“Upon my honor, I have accomplished this laboratory exercise relying upon my own honest efforts without cheating.” */

#include <stdio.h>

int main(){
	int array[5];
	int i, largestnum, choice;
	
	do{
	printf("\nEnter 5 numbers in the array. \n");

	for (i = 0; i < 5; ++i) { //to store user given numbers to the array
        printf("\nEnter number %d: ", i + 1);
        scanf("%d", &array[i]);
	}
	printf("\nNumbers entered: "); 
	
	for (i = 0; i < 5; ++i) { //to print user given numbers
		printf("%d ", array[i]);
    }
	for (i = 1; i < 5; ++i){ //to determine the largest number
        if (array[0] < array[i])
            array[0] = array[i];
    }
	printf("\nLargest number: %d ", array[0]); //prints largest number
	printf("\n\nDo you want to quit? [1]Yes [2]No: "); //asks the user whether to quit or not
	scanf("%d", &choice);

}while(choice == 2);
return 0;
}

