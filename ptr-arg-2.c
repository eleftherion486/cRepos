/**
* Name: Andy Eleftherion
* Lab/task: Lab 1 Task 6
* Date: 08-29-15
**/
#include <stdio.h>

void swap(char **, char **);

int main() {
  char *num1 = "World";
  char *num2 = "Hello";
  swap(&num1, &num2);
  printf("num1 = %s and num2 = %s\n", num1, num2);
}

void swap(char **n1, char **n2) { /* passed and returned by reference */

  char *temp = *n1;
  *n1 = *n2;
  *n2 = temp;
}
