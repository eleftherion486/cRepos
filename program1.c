#include <stdio.h>
#include <stdlib.h>

//Program1
//@Author	Andy Stevens
//@Modified	1-23-15

int main()
{	
	int matrixes = 2;  //used to iterate the first nested for loop twice	
	int matrixColumns;  //used to calculate the number of columns to input for the matrix
	int matrixRows;    //used to calculate the number of rows to input for the matrix
	float total; 	  //used to add the sums of the matrixes for each cell in the output matrix

	int M, N, P;  //used to create the matrixes of the correct size
	scanf("%d %d %d", &M, &N, &P);  //take in 3 inputs for matrix sizes
	
	//create 3 arrrays to store the values of the 2 inputted matrixes and the resulting matrix
	float **matrixA;
	matrixA = malloc(M * sizeof(float *));
	for(int i = 0; i < M; i++)
	{
		matrixA[i] = malloc(N * sizeof(float));
	}

	float **matrixB;
	matrixB = malloc(N * sizeof(float *));
	for(int i = 0; i < N; i++)
	{
		matrixB[i] = malloc(P * sizeof(float));
	}

	float **result;
	result = malloc(M * sizeof(float *));
	for(int i = 0; i < M; i++)
	{
		result[i] = malloc(P * sizeof(float));
	}

	matrixColumns = N;  //first matrix is N columns
	matrixRows = M;    //by M rows



	//use a for loop and iterate through it twice, once for matrix A and the second time for matrixB
	for(int matrix=0; matrix < matrixes; matrix++)
	{	
		for (int row=0; row < matrixRows; row++)
		{
			for (int col=0; col < matrixColumns; col++)
			{
				//use an if/else block to determine where to store inputted variable by matrix
				if (matrix == 0) 
				{
					scanf("%f", &matrixA[row][col]);
				}
				else
				{
					scanf("%f", &matrixB[row][col]);
				}
			}
		}
		matrixColumns = P;  //second matrix is P columns
		matrixRows = N;	   // by N rows
	}
	
	//calculate the results by using a triple nested for loop
	//once for the columns of the resulting matrix, again for
	// the rows of the first matrix, and the last one for the columns of the first matrix
	for(int matrixBcol = 0; matrixBcol < P; matrixBcol++)
	{
		for(int row = 0; row < M; row++)
		{
			for(int col = 0; col < N; col++)
			{
				//add product of the two cells together
				total += (matrixA[row][col] * matrixB[col][matrixBcol]); 
			}
			result[row][matrixBcol] = total;  //set result to total
			total = 0;  //reset total back to 0 after totaling the current row/column
		}
	}

	//display the results by using a double nested for loop and just display each value with the correct formatting
	for(int row=0; row < M; row++)
	{
		for(int col=0; col < P; col++)
		{
			printf("%6.2f  ", result[row][col]);
		}
		printf("\n");
	}
}
