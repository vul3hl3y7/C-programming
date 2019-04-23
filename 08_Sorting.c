/*
*	Project 08 : Sorting
*
*	請撰寫一個程式，程式一開始要讀入一個數字代表需要產生的亂數數量
之後使用bubble sort及insertion sort對資料進行排序
輸出兩個方法執行排序所耗費的時間，以及輸出兩個方法所排序的陣列是否sorted
之後進入查詢模式讓使用者查詢某個數字是否在這個陣列裡面，直到使用者按下ctrl+c將程式中斷
這個程式必須要實作bubble sort和insertion sort這兩種排序演算法
還需要實做兩個function
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
						// 次序不對，進行交換 //
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
				// 進行循序搜尋，同時搬移資料，以空出位置 //
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
