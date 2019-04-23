/*
*	Project 05 : Finding
*
*		The program can identify the maximun, minimum, average of user give.  
*
*	Writer : Meng Tseng Tasi
*
*	Data : 2012/10/25
*
*/




#include <stdio.h>

int
main(void)
{
	int data[100];
	int max = 0, min = 0, sum = 0;
	float average = 0.00;
	int n, i;

	printf("How many numbers do you wnat to write ?\n");
	scanf("%d", &n);
	printf("Numbers of data : %d\n", n);
	printf("Please input data.\n");
	
	for (i = 0; i < n; i++)
		{	
				printf("Data[%d] = ", i + 1);
				scanf("%d", &data[i]);
			}

	max = data[1];
	min = data[1];

	for (i = 0; i < n; i++)
		{
			if (max < data[i])
			{max = data[i];}
			
			else if (min > data[i])
			{min = data[i];}
			sum += data[i];
		}
	
	average = (float)sum / (float)n;

	printf("\tmin : %d\n", min);
	printf("\tmax : %d\n", max);
	printf("\taverage : %.2f\n", average);

	return 0;
}
