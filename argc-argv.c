/**
* Name: Andy Eleftherion
* Lab/task: Lab 1 Task 10
* Date: 08-30-15
**/
#include <stdio.h>
#include <string.h>

void calc(void (* f)(int, int), int a, int b);
void add(int a, int b);
void sub(int a, int b);
void mult(int a, int b);
void div(int a, int b);

/* program called with cmd line parameters */
int main(int argc, char *argv[])
{
    int ctr;
    int a = 0, b = 0;
    char op;

    sscanf(argv[1], "%d", &a);
    sscanf(argv[2], "%c", &op);
    sscanf(argv[3], "%d", &b);

    switch(op)
    {
    	case '*':
    	calc(mult, a, b);
    	break;

    	case '+':
    	calc(add, a, b); 
    	break;

    	case '-':
    	calc(sub, a, b);
    	break;

    	case '/':
    	calc(div, a, b);
    	break;
    }

    return 0;
}

void calc(void (* f)(int, int), int a, int b)
{
	(*f)(a,b);
}

void add(int a, int b)
{
	printf("%d \n", (a + b));
}

void sub(int a, int b)
{
	printf("%d \n", (a - b));
}

void mult(int a, int b)
{
	printf("%d \n", (a * b));
}

void div(int a, int b)
{
	printf("%d \n", (a / b));
}