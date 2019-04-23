/*
*	Project 01 : Dictionary
*
*			The program can read words and for search.
*
*
*	Date : 2013/2/26
*
*	Writer : Tasy Meng Tseng
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max 100

void lookfor(int line, char **eword, char **cword, char word[Max]);

int
main(void)
{
		FILE *fp;
		int i = 0, line = 0;
		char *eword[Max], *cword[Max];
		for (i = 0; i < Max; i++){
				eword[i] = (char *)malloc(20);
				cword[i] = (char *)malloc(20);
		}

		fp = fopen("dict.txt", "r");

		i = 0;
		while(fscanf(fp, "%s\t%s\n", eword[i], cword[i]) != EOF)
		{
			line++;
			i++;
		}

		for (i = 0; i < line; i++)
		{
				printf("%s\t%s\n", eword[i], cword[i]);
				}
	
		char word[Max];
		while(1)
		{
			printf("Please input query: ");
			scanf("%s", word);
				lookfor(line, eword, cword, word);
				}		
		return 0;
		}

void lookfor(int line, char **eword, char **cword, char search[Max])
{
	int i;

	for(i = 0; i < line; i++)
	{
		if(strcasestr(eword[i], search) != NULL)
			printf("%s\n", cword[i]);	
		else if(strcasestr(cword[i], search) != NULL)
			printf("%s\n", eword[i]);
			}
		}
