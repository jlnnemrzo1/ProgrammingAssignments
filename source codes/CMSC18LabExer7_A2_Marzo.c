/* Julienne Elyze P. Marzo 2020-10718
Upon my honor, I have accomplished this laboratory exercise
relying upon my own honest efforts without cheating. */

#include <stdio.h>

/* Function to input date and validate */
int Input(int *date, int *month, int *year){
	
	int d, m, y, flag;
	
	printf("\n\nEnter date: ");
	scanf("%d %d %d", &d, &m, &y);
  
    if(y >= 1982 && y <= 2048) // checks if year is from 1982-2048
    {
        
        if(m >= 1 && m <= 12) // checks if month input is from 1 - 12
        {
            if((d>=1 && d<=31) && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)){ // checks if day input is compatible with month
				flag = 0; // flag = 0 means the date entered is valid
			}else if((d >= 1 && d <= 30) && (m == 4 || m == 6 || m == 9 || m == 11)){
				flag = 0;
			}else if((d >= 1 && d <= 28) && (m == 2)){ 
				flag = 0;
			}else if(d == 29 && m == 2 && (y % 400 == 0 ||(y % 4 == 0 && y % 100 != 0))){ //checks if year is a leap year, if it is and the day input reaches 29, date is still valid
            	flag = 0;
            }else{
                flag = 1; // flag = 1 means the date entered is invalid 
        }
        }else
        {
            flag = 1;
        }
    }
    else
    {
        flag = 1;
    }
    
    if(flag == 0){ // if the date is valid, the values are returned using pointers 
 
		*date = d;
		*month = m;
		*year = y;
		
	
	}else{ // if the date is invalid, the program will end
		printf("You have entered an invalid input. Program will now terminate.");
		exit(0);
	}
	
}

/* Function for calculating and displaying the output */
int Output(int day, int month, int year){
	
	int day_of_the_week, flag;
	day_of_the_week = (day+=month<3?year--:year-2,23*month/9+day+4+year/4-year/100+year/400)%7;
	
	printf("Day: ");
	switch(day_of_the_week) {
		
		case 0:
						printf(" Sunday \n");
			break;
		case 1:
                        printf(" Monday \n");
			break;
		case 2:
                        printf(" Tuesday \n");
			break;
		case 3:
                        printf(" Wednesday \n");
			break;
		case 4:
                        printf(" Thursday \n");
			break;
		case 5:
                        printf(" Friday \n");
			break;
		case 6:
                        printf(" Saturday \n");
            break;
	}
	
	flag = 0; // this is used to for the do while loop in the main function 
	return flag;
}

/* Main function for the program */
int main(){
	
	int date, month, year, flag;
	
	printf("Program to give week day from given date.");
	do{
	Input(&date, &month, &year);
	Output(date, month, year);
	}while(flag == 0);
	return 0;
}

