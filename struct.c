/**
* Name: Andy Eleftherion
* Lab/task: Lab 1 Task 8
* Date: 9-2-15
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

int main() {
  int i;
  int numOfEmployees = 0;
  printf("How many employees?\n");
  scanf("%d", &numOfEmployees);
  PERSON employees[numOfEmployees];

  i = 0;
  for(i = 0; i < numOfEmployees; i++)
  {
    PERSON currentPerson;  //create a PERSON object to store the current Person
    printf("Enter salary, bday day, bday month, bday year, and employee name:\n");
    scanf("%lf %d %d %d %[^\n]s", &currentPerson.salary, &currentPerson.bday.day, &currentPerson.bday.month, &currentPerson.bday.year, currentPerson.name);
    add(employees,currentPerson);  //add currentPerson PERSON to employees array at ith index
  }

  //display all employees entered
  i=0;
  for(i = 0; i < numOfEmployees; i++)
  {
    printf(" %s %lf %d %d %d \n", employees[i].name, employees[i].salary, employees[i].bday.day, employees[i].bday.month, employees[i].bday.year);
  }
  
}