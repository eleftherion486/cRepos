/**
* Name: Andy Eleftherion
* Lab/task: Lab 1 Task 4
* Date: 08-27-15
**/
#include <stdio.h>

#define NUM_OF_CELLS 5

int main(void) 
{
    double number[NUM_OF_CELLS]; /* 12 cells, one cell per student */
    int index = 0;
    double sum = 0;
		/* Always initialize array before use */
    for (index = 0; index < NUM_OF_CELLS; index++) {
	number[index] = 0.0; 
    }
    /* now, number[index]=index; will cause error:why ?*/

    printf("Data: ");
    for (index = 0; index < NUM_OF_CELLS; index = index + 1) {
	scanf("%lf", &number[index]);
    sum += number[index];  /* sum array elements */
    }
    printf("Average: %.1lf \n", (sum / NUM_OF_CELLS));
	
    return 0;
}
