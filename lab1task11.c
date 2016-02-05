/**
* Name: Andy Eleftherion
* Lab/task: Lab 1 Task 11
* Date: 9-2-15
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"
#include "list.h"

LIST *start;
LIST *startIt;

int main(void){
	PERSON tempPerson;
	int numOfPeople = 0;
	int deleted = 0;
	char command[2];
	start=NULL;
	startIt=NULL;
	char nameDelete[41];
	do
	{
		command[0] = '\0';
		startIt = start;
		printf("a to add an entry\nd to delete an entry\nv to view all records\nx to exit\n:");
		scanf("%s", command);

		if (command[0] == 'a')
		{
			printf("Enter age, height, bday day, bday month, bday year, and employee name:\n");
			scanf("%d %f %d %d %d %[^\n]s", &tempPerson.age, &tempPerson.height, &tempPerson.bday.day, &tempPerson.bday.month, &tempPerson.bday.year, tempPerson.name);
			numOfPeople++;
			add(&start, tempPerson);
		}
		else if (command[0] == 'd' && numOfPeople>0)
		{
			startIt=start;
			display(&startIt);
			printf("Enter name of employee to delete: ");
			scanf("%s", nameDelete);
			deleted = delete(&start, nameDelete);
			if (deleted)
				numOfPeople--;
			else
				printf("%s not found\n", nameDelete);
		}
		else if (command[0] == 'x'){}
		else if (command[0] == 'v' && numOfPeople > 0){
			display(&startIt);
		}
		else
		{
			printf("Invalid command, please try again\n\n");
		}
	}while(command[0] != 'x');
	return 0;
}