/**
* Name: Andy Eleftherion
* Lab/task: Lab 1 Task 6
* Date: 9-2-15
**/
#include <stdio.h>

int main(void) {
	/* file handles */
	FILE *output_file=NULL;
	FILE *input_file=NULL;
	char fileName[] = "testInputData.txt";
	char words[20];

	printf("Enter name of file: ");
	scanf("%s", fileName);

	/* open files for reading and writing*/
	output_file = fopen(fileName, "w");
	input_file = fopen("data.txt", "r");

	if(output_file == NULL || input_file == NULL)
		return(1); 

	/* write some data into the file */
    while (fscanf(input_file, "%s", words) != EOF)
    {
  		fprintf(output_file, "%s ", words );
	}

	//close file handlers
	fclose(output_file);
	fclose(input_file);
    return 0;
}
