/**
* Name: Andy Eleftherion
* Lab/task: Lab 1 Task 3
* Date: 08-27-15
**/
#include <stdio.h>
#define DANGERLEVEL 5    /* C Preprocessor -
			- substitution on appearance */
				/* like Java ‘final’ */
int main(void)
{
	float level=0;


	scanf("%f", &level);
	/* if-then-else as in Java */


	if (level <= DANGERLEVEL) /*replaced by 5*/
      		printf("Low on gas!\n");
	else
		printf("Good driver !\n");
}
