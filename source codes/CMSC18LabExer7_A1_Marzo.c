/* Julienne Elyze P. Marzo 2020-10718
Upon my honor, I have accomplished this laboratory exercise
relying upon my own honest efforts without cheating. */

#include <stdio.h>

/* Function to print the description of this program*/
void Description(){
	
	printf("Program to compute the area of a rectangle given its length and width. \n");

}
/* Function to get input value from user */
int Input(char dimension[]){
	
	int val;
	
	printf("\nEnter %s: ", dimension);
	scanf(" %d", &val);
	
	while(val < 1){
		printf("\nInvalid input. Please reenter.");
		printf("\n\nEnter %s:", dimension);
		scanf(" %d", &val);
	}
	
	return val;
}

/* Function to compute for the length of the rectangle */
int ComputeArea(int length, int width){
	
	int area = length * width;
	
	return area;
}

/* Function to print out the length, width and area of the rectangle*/
void Output(int length, int width, int area){
	
	printf("\nThe area for a rectangle with the length of %d and a width of %d is %d.", length, width, area);
}

/* Main function of the program */
int main(){
	
	int width, length, area;
	
	Description();
	length = Input("length");
	width = Input("width");
	area = ComputeArea(length, width);
	Output(length, width, area);
	return 0;
}
