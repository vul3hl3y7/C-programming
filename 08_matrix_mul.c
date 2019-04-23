/*
*	Homework #8 : 
*
*		Write a C program to perform:
*		Read a text file named ¡§data.txt¡¨ which contains
*		A matrix A, each element is a float data type
*		A matrix B, each element is a float data type
*		Use GCC intrinsic functions to leverage SIMD instructions.
*		Compute A x B (matrix multiplication)
*/

#include <stdio.h>
#include <stdlib.h>

#define s 200

int main()
{
		FILE *fp = fopen("data.txt", "r");
		FILE *fo = fopen("Output.txt", "w");
		float A[s][s];
		float B[s][s];
		float C[s][s];

		int i, j, k;

		// A matrix
		for(i = 0; i < s; i++)
		{
				for(j = 0; j < s; j++)
				{
						fscanf(fp, "%f", &A[i][j]);
				}
						printf("\n");
		}

		// B matrix
		for(i = 0; i < s; i++)
		{
				for(j = 0; j < s; j++)
				{
						fscanf(fp, "%f", &B[i][j]);
				}
						printf("\n");
		}

		// calculate

		for(i = 0; i < s; i++)
		{
			for(j = 0; j < s; j++)
			{
				C[i][j] = 0;	
				for(k = 0; k < s; k++)
				{
					C[i][j] += ( A[i][k] * B[k][j] );		
				}
			}
			printf("\n");
		}


		for(i = 0; i < s; i++)
		{
				for(j = 0; j < s; j++)
				{
						fprintf(fo, "%f", C[i][j]);
				}
						fprintf(fo, "\n");
		}
		
		return 0;
		}
