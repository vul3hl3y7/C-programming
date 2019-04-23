/*
 *	Project 03 : qsort, mergesort
 *
 *	請撰寫一個程式，先使用random number generator產生500萬個整數以及500萬個字串，字串長度皆為8bytes整數範圍為0~100000, 字串的char範圍為65~122之後以整數陣列為資料，使用qsort()及mergesort()輸出兩種sort的執行時間再以字串陣列為資料，使用qsort()及mergesort()輸出兩種sort的執行時間
 *
 *
 *	Writer : Meng Tseng Tasi
 *
 *	Date : 2013/3/19
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define max 5000000

void array_init(int *num, char **A);

int compare(const void * a, const void * b);
int scompare(const void * a, const void * b);

int compare(const void * a, const void * b)
{
		return ( *(int *)a - *(int *) b);		
}

int scompare(const void * a, const void * b)
{
		return (strcmp((char *)a, (char *)b));
}

int main(void)
{
		int i;	
		int *N;
		int *N2;
		char **A;
		char **B;
		char *temp;

		/* Two integer arrays for two sorting methods */
		N = (int *)malloc(max * sizeof(int));
		N2 = (int *)malloc(max * sizeof(int));

		/* Two string arrays for two sorting methods */
		A = (char **)malloc(max * sizeof(char *));
		for (i = 0; i < max; i++)
		{
				A[i] = (char *)malloc(8 * sizeof(char));
		}

		B = (char **)malloc(max * sizeof(char *));
		for (i = 0; i < max; i++)
		{
				B[i] = (char *)malloc(8 * sizeof(char));		
		}

		temp = (char *)malloc(8 * sizeof(char));

		array_init(N, A);

		/* [integer arrsy] */

		for(i = 0; i < max; i++)
		{
				N2[i] = N[i];
		}

		// qsort
		double start1 = (double) clock();
		qsort(N, max, sizeof(int), compare);
		double end1 = (double) clock();

		// mergesort
		double start2 = (double) clock();
		mergesort(N2, max, sizeof(int), compare);
		double end2 = (double) clock();
		printf("[integer array]\n");
		printf("qsort() time : %.2f secs\n", (end1 - start1) / CLOCKS_PER_SEC);
		printf("mergesort() time : %.2f secs\n", (end2 - start2) / CLOCKS_PER_SEC);

		/* [string array]] */
		
		for (i = 0; i < max; i++)
		{
			strcpy(temp, A[i]);
			strcpy(B[i], temp);
		}

		// qsort
			start1 = (double) clock();
		qsort(A, max, sizeof(char *), scompare);
			end1 = (double) clock();

		// mergesort
		start2 = (double) clock();
		mergesort(B, max, sizeof(char *), scompare);
		end2 = (double) clock();
		printf("[string array]\n");
		printf("qsort() time : %.2f secs\n", (end1 - start1) / CLOCKS_PER_SEC);
		printf("mergesort() time : %.2f secs\n", (end2 - start2) / CLOCKS_PER_SEC);
		 		
		return 0;		
}

void array_init(int *num, char **A)
{
		int i, j;

		srand(time(NULL));
		for (i = 0; i < max; i++)
		{
				num[i] = (rand() % (100000 - 0)) + (0);	
		}

		srand(time(0));
		for (i = 0; i < max; i++)
		{
				for(j = 0; j < 7; j++)
				{
						A[i][j] = (rand() % (122 - 65)) + (65);
				}
		}
		printf("initial successful\n");
		sleep(1);
}
