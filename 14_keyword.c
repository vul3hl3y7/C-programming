/*
*	Project #4 : keyword counting
*
*	撰寫一個計算關鍵字數量的程式，程式執行會讀兩個file, keywordFile，存關鍵字，dataFile，存一篇文章, keywordFile 至多會有100000個keyword, 計算每個關鍵字在文章裡出現的次數，並印出．
*
*	Date : 2013/3/25
*
*	Writer : Meng Tseng Tasi
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100000

int part(char L[], char **text);
int count(char K[], char **text, int end);

int main(int argc, char *argv[])
{
	FILE *fk, *fd;
	char **text;
	char line[max];
	char **key;
	int *ct;
	int num = 0, con = 0, end = 0,i = 0, l = 1;

	text = (char **)malloc(max * sizeof(char *));
	for(i = 0; i < max; i++)
	{
		text[i] = (char *)malloc(256 * sizeof(char));	
	}

	/* Maybe have 100000 key words */
	ct = (int *)malloc(max * sizeof(int));
	key = (char **)malloc(max * sizeof(char *));
	for(i = 0; i < max; i++)
	{
		key[i] = (char *)malloc(256 * sizeof(char));	
	}

	/* Sure user input key file and data file */
	if(argc == 3)
	{
	
		fk = fopen(argv[1], "r");
		fd = fopen(argv[2], "r");

		if(fk == NULL)
		{
			printf("File not found !\n");
			return 0;
		}

		/* Read key words */
		i = 0;
		while(fscanf(fk, "%s\n", key[i]) != EOF)
		{	
			num++;
			i++;
		}

		/* Read the content of file line by line and check how many key words are there in the line. */
		while(fgets(line, 256, fd) != NULL)
		{	
			con = part(line, text);

			for(i = 0; i < num; i++)
			{
			end = count(key[i], text, con);
		//	printf("In line %d , %s : %d\n", l, key[i], end);
			ct[i] += end;
			}
			l++;
		}

		for (i = 0; i <num; i++)
		{
			printf("keyword : %s %d\n", key[i], ct[i]);		
		}
	}
	else
	{
		printf("Numbers of files wrong !\n");
		return 0;
	}

	return 0;		
}

int part(char L[], char **text)
{
	int i = 0;	
	int count = 0;
	char *test;

	test = strtok(L, " \t");
	while (test != NULL)
	{
		strcpy(text[i], test);
		i++;
		count++;
		test = strtok(NULL, " \t");
	}
	return count;				
}

int count(char K[], char **text, int up)
{
	int each = 0;
	int i;

	for (i = 0; i < up; i++)
	{
		if(strcmp(K, text[i]) == 0)
		{
			each++;		
		}
	}
	return each;
		}
