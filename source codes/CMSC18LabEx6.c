//Julienne Elyze P. Marzo 2020-10718
//Upon my honor, I have accomplished this laboratory exercise relying upon my own honest efforts without cheating.

#include <stdio.h>
#include <string.h>
#define MAX 1000

int main() {
	char string[MAX], reverse[MAX], maxchar;
	int test, i, e, choice;
	int length;
	
	do {
		for (i = 0; i <= MAX; i++) {
			string[i] = '\0';
			reverse[i] = '\0';
		}
	int wordCount = 0;
	int vowels = 0;
	int cons = 0;
	int maxcount = 0;
	int count = 0;
	int char_count = 0;
			
		//ask user for input
		printf("Input the string: ");
		fgets(string, MAX, stdin);
		
		//reverse the string
		length = strlen(string);
		
		for (i = 0; string[i] != '\0'; i++) {
			for (e = length-2; e >= 0; e--) {
				reverse[i] = string[e];
				length--;
				break;
			}
		}
		printf("\nThe characters of the string in reverse are: ");
		puts(reverse);
		
		//count number of words
		printf("Total number of words in the string is: ");
		
		for(i = 0; string[i] != '\0'; i++){
		if(string[i] == ' ' && string[i+1] != ' '){
		wordCount++;
		}	
	}
	printf("%d", wordCount + 1); 
		
		//determine number of vowels and consonants
		for(i = 0; string[i] != '\0'; i++){
			if(string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u'
			|| string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U'){
				vowels++;
			}else if(string[i] >= 'a' && string[i] <= 'z' || string[i] >= 'A' && string[i] == 'Z'){
				cons++;
			}
		}
		printf("\nThe total number of vowel in the string is: %d", vowels);
		printf("\nThe total number of consonant in the string is: %d", cons);
		
		
		//find maximum occuring character in the string
			for(i = 0; string[i] != '\0'; i++)
		{
			count = 0;
			for(e = 0; string[e] != '\0'; e++) 
			{
				if(string[i] == string[e])
				{
					count++;
				}
			}
			
			if(maxcount < count)
			{
				maxcount = count;
				maxchar = string[i];
			}
		} printf("\nThe most occurring character is '%c' which appears the ff number of times: %d", maxchar, maxcount);
		
		//remove character except alphabets
	
	for(i=0; string[i]!='\0'; ++i)
    {
        while (!((string[i]>='a'&&string[i]<='z') || (string[i]>='A'&&string[i]<='Z' || string[i]=='\0')))
        {
            for(e = i; string[e] !='\0'; e++)
            {
                string[e]=string[e+1];
            }
            string[e]='\0';
        }
    }printf("\nAfter removing the non alphabet characters: ");    
	printf("%s", string);
		
		//asks the user for next action
		do {
			printf("\n\nInput another string?");
			printf("\n1 - Yes");
			printf("\n2 - No. Exit the Program.");
			printf("\nResponse: ");
			scanf(" %d", &choice);
			
			if (choice != 1 && choice != 2) {
				printf("\nInvalid response!");
			}
		} while (choice != 1 && choice != 2);

		int input;
		do {
		    input = getchar();
		} while (input != '\n' && input != EOF);
		
		printf("\n");
	
	} while (choice != 2);
	
	return 0;
}

