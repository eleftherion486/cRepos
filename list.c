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

//typedef struct list {PERSON data; struct list *next;} LIST;



//display has a copy of head so it doenst lose the memory adress
void display(LIST **head)
{
	PERSON displayPerson;
	do{
		displayPerson = (*head)->data;
		printf("%s %d %.2f %d %d %d \n", displayPerson.name, displayPerson.age, displayPerson.height, displayPerson.bday.day, displayPerson.bday.month, displayPerson.bday.year);
		*head=(*head)->next;
	}while(*head!=NULL);

}

//add to front of list, no need for tail anymore
void add(LIST **head, PERSON person){
	LIST *temp;
	temp = (LIST *) malloc(sizeof(LIST));
	temp->data=person;
	temp->next=*head;
	*head=temp;
}

int delete (LIST **head, char nameDelete[41]){
	LIST *temp, *current, *previous;
	PERSON currentPerson;

	if (*head == NULL)
		return 0;

	currentPerson = (*head)->data;

	//if head equals deleted entry
	if (strcmp(currentPerson.name,nameDelete)==0){
		temp=(*head)->next;
		free(*head);
		*head=temp;
		return 1;
	}

	//iterate through rest of list checking for deleted entry
	current = *head;
	do{
		currentPerson = current->data;

	//if current node equals deleted entry
	if (strcmp(currentPerson.name,nameDelete)==0){
		temp=current->next;
		free(current);
		previous->next=temp;
		current=temp;
		return 1;
	}
		previous=current;
		current=current->next;
	}while(current!=NULL);


	return 0;




}