/**
* Name: Andy Eleftherion
* Lab/task: Lab 1 Task 5
* Date: 08-30-15
**/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	int words = 0;
	char** ptr = NULL; 
	char line[30];

while (scanf("%s", line) != EOF)
{
		words++;
		ptr = (char**)realloc(ptr, sizeof(char*)*words);	//reallocate the size of the array of pointers

		ptr[words-1] = (char*) realloc(ptr[words-1],sizeof(char)*strlen(line));
		strcpy(ptr[words-1], line);
}

	printf("There were %d words entered\n",words);
	for (int i = 0; i < words; i++)
	{
		printf("%s \n",ptr[i]);
	}

	free(ptr);		//free the memory
}