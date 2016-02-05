/**
* Name: Andy Eleftherion
* Lab/task: Lab 1 Task 1
* Date: 08-27-15
**/
#include <stdio.h>

int main(void)
{
	int nstudents = 0; /* Initialization, required */
	int nfaculty = 0;
	double nratio = 0.0;
	
	printf("How many students does CSUCI have ?:");
 	scanf ("%d", &nstudents);  /* Read input */
	printf("CSUCI has %d students.\n", nstudents); 
	printf("How many faculty members does CSUCI have ?:");
 	scanf ("%d", &nfaculty);  /* Read input */
	printf("CSUCI has %d faculty members.\n", nfaculty);
	nratio = (double) nstudents / nfaculty;
	printf("The ratio of students to faculty is %.1lf:1 \n", nratio );

	return 0;
}

