/*
*	Project 10 : Scoretable.
*
*		請撰寫一個程式，從標準輸入讀進資料之後讀入使用者的選擇，按照使用者的選擇對特定欄位做排序印出成績表
*
*	Date : 2013/01/08
*
*	Writer : Meng Tseng Tasi
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 101
#define min -1

void sort(int *No, char **Name, float o1[], float o2[], float o3[], float o4[], int len);
void find(int No[], char **Name, float o1[], float o2[], float o3[], float o4[], int len, char search[max]);

int
main()
{
	FILE *fp;
	char *Name[max];
	int line = 0;
	int i = 0;
	for(i= 0;i<max;i++)
			Name[i] = (char *)malloc(20);
	int No[max];
	float PD[max];
	float Cal[max];
	float LA[max];
	float preAve[max];
					char *N[max];
	for(i= 0;i<max;i++)
			N[i] = (char *)malloc(20);
					int no[max];
					float pd[max];
					float cal[max];
					float la[max];
					float preave[max];
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

	fp = fopen("test10_1.txt", "r");
	i=0;
		while(fscanf(fp, "%s\t%d\t%f\t%f\t%f", Name[i], &No[i], &PD[i], &Cal[i], &LA[i]) != EOF){
				line++;
			if (No[i] >= max || No[i] <= 0 || PD[i] >= max || PD[i] <= min || Cal[i] >= max || Cal[i] <= min || LA[i] >= max || LA[i] <= min )
				line--;
			else {
				preAve[i] = (PD[i] + Cal[i] + LA[i]) / 3;
					 strcpy(N[i],  Name[i]);
					 no[i] = No[i];
					 pd[i] = PD[i];
					 cal[i] = Cal[i];
					 la[i] = LA[i];
					 preave[i] = preAve[i];
					 
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
		
		if (line != 0)
		{
			avgPD = sumPD / line;
			avgCal = sumCal / line;
			avgLA = sumLA / line;
			avgAvg = sumAvg / line;	
				
				avgmax = (PDmax + Calmax + LAmax) / 3;
				avgmin = (PDmin + Calmin + LAmin) / 3;

		fprintf(stdout,"\nOriginal data.\n");
		printf("-----------------------------------------------------------------------------------\n");
		printf("Name\t|No\t|PD\t|Cal.\t|LA\t|Ave.\n");
		printf("-----------------------------------------------------------------------------------\n");

			for (i = 0; i < line; i++)
			{
					
				printf("%s\t|%d\t|%.2f\t|%.2f\t|%.2f\t|%.2f\n", N[i], no[i], pd[i], cal[i], la[i], preave[i]);
					}

				printf("-----------------------------------------------------------------------------------\n");
				printf("Ave\t\t|%.2f\t|%.2f\t|%.2f\t|%.2f\n", avgPD, avgCal, avgLA, avgAvg);
				printf("Max\t\t|%.2f\t|%.2f\t|%.2f\t|%.2f\n", PDmax, Calmax, LAmax, avgmax);
				printf("Min\t\t|%.2f\t|%.2f\t|%.2f\t|%.2f\n", PDmin, Calmin, LAmin, avgmin);


			sort(no, N, pd, cal, la, preave, line);

	printf("\n\nBefore name sort.\n");
		printf("-----------------------------------------------------------------------------------\n");
		printf("Name\t|No\t|PD\t|Cal.\t|LA\t|Ave.\n");
		printf("-----------------------------------------------------------------------------------\n");
			for (i = 0; i < line; i++){
				printf("%s\t|%d\t|%.2f\t|%.2f\t|%.2f\t|%.2f\n", N[i], no[i], pd[i], cal[i], la[i], preave[i]);
			}
				printf("-----------------------------------------------------------------------------------\n");
				printf("Ave\t\t|%.2f\t|%.2f\t|%.2f\t|%.2f\n", avgPD, avgCal, avgLA, avgAvg);
				printf("Max\t\t|%.2f\t|%.2f\t|%.2f\t|%.2f\n", PDmax, Calmax, LAmax, avgmax);
				printf("Min\t\t|%.2f\t|%.2f\t|%.2f\t|%.2f\n", PDmin, Calmin, LAmin, avgmin);

			// interactive mode
		char choose[max];
		return 0;
		while(1){
				printf("\n\nFind who ?\n");
				scanf("%s", choose);
						
			find(no, N, pd, cal, la, preave, line, choose);

		}
	} else printf("\nWrong !\n");
		return 0;
		}

void sort(int *No, char **Name, float o1[], float o2[], float o3[], float o4[], int len)
{
	int i, j;
	char *temp_name;
	int temp;
	fprintf(stderr,"LLLL\n");
	for (j = 0; j < len; j++)
	{
			for (i = 0; i < (len - 1); i++)
			{
					if (strncmp(Name[i], Name[i + 1], max) > 0)
					{
						temp_name = Name[i];
						Name[i] = Name[i+1];
						Name[i + 1] = temp_name;

							temp = No[i];
							No[i] = No[i + 1];
							No[i + 1] = temp;
							
							temp = o1[i];
							o1[i] = o1[i + 1];
							o1[i + 1] = temp;
							
							temp = o2[i];
							o2[i] = o2[i + 1];
							o2[i + 1] = temp;
							
							temp = o3[i];
							o3[i] = o3[i + 1];
							o3[i + 1] = temp;
							
							temp = o4[i];
							o4[i] = o4[i + 1];
							o4[i + 1] = temp;

							}
					
					}
			
			
			}
		
		
		}

void find(int No[], char **Name, float o1[], float o2[], float o3[], float o4[], int len, char search[max])
{
		int i;

		for (i = 0; i < max; i++)
		{
			while(strcasestr(Name[i], search) != NULL)
				{
		printf("\n-----------------------------------------------------------------------------------\n");
		printf("Name\t|No\t|PD\t|Cal.\t|LA\t|Ave.\n");
		printf("-----------------------------------------------------------------------------------\n");
					printf("%s\t|%d\t|%.2f\t|%.2f\t|%.2f\t|%.2f\n", Name[i], No[i], o1[i], o2[i], o3[i], o4[i]);
						break;
						}

			}
		}

