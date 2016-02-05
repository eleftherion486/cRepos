/**
* Name: Andy Eleftherion
* Lab/task: Lab 1 Task 8
* Date: 9-2-15
**/
#include <string.h>
#include <stdlib.h>
#include "person.h"

int numOfEmployees = 0;

void add(PERSON *employees,PERSON addPerson){
	strcpy(employees[numOfEmployees].name,addPerson.name);
	employees[numOfEmployees].salary = addPerson.salary;
	employees[numOfEmployees].bday.day = addPerson.bday.day;
	employees[numOfEmployees].bday.month = addPerson.bday.month;
	employees[numOfEmployees].bday.year = addPerson.bday.year;
	numOfEmployees++;
}

