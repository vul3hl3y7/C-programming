/*
*	Project 09 : Scoretable.
*
*		請撰寫一個程式，從標準輸入讀進資料之後讀入使用者的選擇，按照使用者的選擇對特定欄位做排序印出成績表
*
*	Date : 2012/12/17
*
*	Writer : Meng Tseng Tasi
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 101
#define min -1

void mergeso(int No[], float C[], float o1[], float o2[], float o3[], int low, int high);
void merge(int No[], float C[], float o1[], float o2[], float o3[], int low1, int high1, int low2, int high2);

int
main()
{
	FILE *fp;
	int No[max];
	float PD[max];
	float Cal[max];
	float LA[max];
	float preAve[max];
	int line = 0;
	int i = 0;
			float sumPD = 0;
			float sumCal = 0;
			float sumLA = 0;
			float sumAvg = 0;
			float avgPD = 0;
			float avgCal = 0;
			float avgLA = 0;
			float avgAvg = 0;
		float PDmax = min;
		float PDmin = max;
		float Calmax = min;
		float Calmin = max;
		float LAmax = min;
		float LAmin = max;
					float avgmax = 0;
					float avgmin = 0;

	fp = fopen("./testdata", "r");
	
		printf("No.\t|\tPD\t|\tCal.\t|\tLA\t|\tAve.\n");
		printf("-----------------------------------------------------------------------------------\n");

		while(fscanf(fp, "%d\t%f\t%f\t%f", &No[i], &PD[i], &Cal[i], &LA[i]) != EOF){
				line++;
			if (No[i] > max || No[i] < min || PD[i] > max || PD[i] < min || Cal[i] > max || Cal[i] < min || LA[i] > max || LA[i] < min )
				break;
			else {
				preAve[i] = (PD[i] + Cal[i] + LA[i]) / 3;
				printf("%d\t|\t%.2f\t|\t%.2f\t|\t%.2f\t|\t%.2f\n", No[i], PD[i], Cal[i], LA[i], preAve[i]);
		
				sumPD += PD[i];
				sumCal += Cal[i];
				sumLA += LA[i];
				sumAvg += preAve[i];
		
		// calculate max & min value & their 
		
				if (PDmax < PD[i])
						PDmax = PD[i];
				if (PDmin > PD[i])
						PDmin = PD[i];
				if (Calmax < Cal[i])
						Calmax = Cal[i];
				if (Calmin > Cal[i])
						Calmin = Cal[i];
				if (LAmax < LA[i])
						LAmax = LA[i];
				if (LAmin > LA[i])
						LAmin = LA[i];

				i++;
			}
		}
			
			avgPD = sumPD / line;
			avgCal = sumCal / line;
			avgLA = sumLA / line;
			avgAvg = sumAvg / line;	
				
				avgmax = (PDmax + Calmax + LAmax) / 3;
				avgmin = (PDmin + Calmin + LAmin) / 3;

				printf("-----------------------------------------------------------------------------------\n");
				printf("Ave.\t|\t%.2f\t|\t%.2f\t|\t%.2f\t|\t%.2f\n", avgPD, avgCal, avgLA, avgAvg);
				printf("Max\t|\t%.2f\t|\t%.2f\t|\t%.2f\t|\t%.2f\n", PDmax, Calmax, LAmax, avgmax);
				printf("Min\t|\t%.2f\t|\t%.2f\t|\t%.2f\t|\t%.2f\n", PDmin, Calmin, LAmin, avgmin);

		// interactive mode
		int choose = 0;
		while(1){
				printf("Select the object to sort transcript.\n");
				printf("1) PD\n");
				printf("2) Cal\n");
				printf("3) LA\n");
				printf("4) Average\n");
				scanf("%d", &choose);
					
		printf("No.\t|\tPD\t|\tCal.\t|\tLA\t|\tAve.\n");
		printf("-----------------------------------------------------------------------------------\n");
					switch(choose)
					{
							case 1 :
								{
								mergeso(No, PD, Cal, LA, preAve, 0, line);
								break;
								}
							case 2 :
							//	merge(Cal, 0, line - 1);
								{
								mergeso(No, Cal, PD, LA, preAve, 0, line);
								break;
								}
							case 3 :
							//	merge(LA, 0, line - 1);
								{
								mergeso(No, LA, Cal, PD, preAve, 0, line);
								break;
								}
							case 4 :
							//	merge(preAve, 0, line - 1);				
								{
								mergeso(No, preAve, Cal, LA, PD, 0, line - 1);
								break;
								}
							}

				for (i = 0; i < line; i++){
				printf("%d\t|\t%.2f\t|\t%.2f\t|\t%.2f\t|\t%.2f\n", No[i], PD[i], Cal[i], LA[i], preAve[i]);
						}
				}
		
		return 0;
		}

void mergeso(int No[], float C[], float o1[], float o2[], float o3[], int low, int high)
{			
	mergeso(No, C, o1, o2, o3, low, (low + high) / 2);
	mergeso(No, C, o1, o2, o3, (low + high) / 2 + 1, high);

	merge(No, C, o1, o2, o3, low, (low + high) / 2, (low + high) / 2 + 1, high);

}

void merge(int No[], float C[], float o1[], float o2[], float o3[], int low1, int high1, int low2, int high2)
{
	int temp[max];
	int leftp = low1, rightp = low2, sp = 0;
	int i;

	while (leftp < high1 && rightp < high2)
	{
			if (C[leftp] < C[rightp]){
					temp[sp++] = C[leftp++];
					} else { 
							temp[sp++] = C[rightp++];
							}
		}
}

