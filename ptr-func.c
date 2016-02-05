/**
* Name: Andy Eleftherion
* Lab/task: Lab 1 Task 10
* Date: 08-29-15
**/
#include <stdio.h> 

void myproc (int d);
void mycaller(void (* f)(int), int param);

int main(int argc, char *argv[]) { 
	//myproc(10);		/* call myproc with parameter 10*/
	mycaller(myproc, *argv[2]); /* and do the same again ! */
} 

void mycaller(void (* f)(int), int param){
	(*f)(param); 	/* call function *f with param */ 
}

void myproc (int d){
	printf("%d",d);
 	/* do something with d */
}
