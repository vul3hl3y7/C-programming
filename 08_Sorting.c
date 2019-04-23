/*
*	Project 08 : Sorting
*
*	�м��g�@�ӵ{���A�{���@�}�l�nŪ�J�@�ӼƦr�N��ݭn���ͪ��üƼƶq
����ϥ�bubble sort��insertion sort���ƶi��Ƨ�
��X��Ӥ�k����ƧǩүӶO���ɶ��A�H�ο�X��Ӥ�k�ұƧǪ��}�C�O�_sorted
����i�J�d�߼Ҧ����ϥΪ̬d�߬Y�ӼƦr�O�_�b�o�Ӱ}�C�̭��A����ϥΪ̫��Uctrl+c�N�{�����_
�o�ӵ{�������n��@bubble sort�Minsertion sort�o��رƧǺt��k
�ٻݭn�갵���function
*
*	Date : 2012/12/09
*
*	Writer : Meng Tseng Tasi
*
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"


int main()
{
	int num = 0;
	int A[Nummax];
	int data[Nummax];

	printf("How many numbers do you want to sort ?\n");
	scanf("%d", &num);

	array_init(A, num);

		int i;
		int j;

		// Bubble sort //
		for (i= 0; i < num; i++){
				data[i] = A[i];
				}
		
		double start1 = (double) clock();
			for (i = num - 1; i > 0; i--){
					for (j = 0; j <= i - 1; j++){
						// ���Ǥ���A�i��洫 //
						if (data[j] > data[j + 1]){
								int temp = data[j];
								data[j] = data[j + 1];
								data[j + 1] = temp;
								}
						}
			}
		double end1 = (double) clock();
		
		int currect = isSorted(data, num);
		if (currect == 1)
		printf ("Bubble sort => sorted, elapsed time : %f sec\n", (end1 - start1) / 100);

		// insertion sort //
		int x;
		int y;

		for (x = 0; x < num; x++){
				data[x] = A[x];	
				}

		double start2 = (double) clock();
		for (x = 1; x < num; x++){
				int key = data[x];
				// �i��`�Ƿj�M�A�P�ɷh����ơA�H�ťX��m //
				for (y = x - 1; y >= 0 && data[y] > key; y--){
								data[y + 1] = data[y];
						}
						data[y + 1] = key;
				}
		double end2 = (double) clock();
		int currect2 = isSorted(data, num);
		if (currect2 == 1)
		printf ("Insertion sort => sorted, elapsed time : %f sec\n", (end2 - start2) / 100);

		while(1)
		{
			// Binary search //
			int search = 0;
			printf("Which number do you want to find ?\n");
			scanf("%d", &search);
					int left = 0;
					int right = num - 1;

					while (left <= right){
						int mid = (left + right) / 2;
						if (data[mid] < search)
								left = mid + 1;
						else if (data[mid] == search){
							printf("Found! At the position %d .\n", mid + 1);
							break;
						}
						else 
							right = mid - 1;

							mid = (left + right) / 2;
						}
						if (left > right)
							printf("Not Found!\n");					
				}
	return 0;
}
