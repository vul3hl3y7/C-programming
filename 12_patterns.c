/*
*   Project #2 : Watch patterns
*
*           The program can find specific words from the file.
*
*
*   Writer : Tasi Meng Tseng
*
*	Date : 2013/3/5
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 256

void find(char pattern[256][max], char sentence[max], int word); 

int
main(int argc, char *argv[])
{
	FILE *fd;
	char sentence[max];
	char pattern[256][max];
	int word = 0, i = 0;

		if(argc == 2) // read argvment
		{

			fd = fopen(argv[1], "r");

			if (fd == NULL)
			{	
				printf("%s not find !\n", argv[1]);
				return 0;
			}
		
			while(fscanf(fd, "%s\n", pattern[i]) != EOF) // read pattern
			{
				printf("%s\n", pattern[i]); 
				word++;
				i++;		
			}	

		}
		else
		{
			printf("Wrong data file.\n");
			return 0;
		}
		
	while(1)
	{
		printf("Write sentence.\n");
		fgets(sentence, max, stdin);
		find(pattern, sentence, word);
			}

	return 0;
}

void find(char pattern[256][max], char sentence[max], int word)
{
	char *test;
	char pat[max];
	int lenline = 0; // 計算句子長度
	int lentest = 0; 
	int len = 0;
	int lenpattern = 0;
	int i = 0;

		for(i = 0; i < word; i++)
		{
		test = strstr(sentence, pattern[i]);
		
			if (test != NULL)
			{
				lenline = strlen(sentence) + 1; // sentence length
				lentest = strlen(test) + 1;		// length of pattern and the word after it
				lenpattern = strlen(pattern[i]) + 1;	// pattern length
				len = lenline - lentest;	



				if (lentest == lenline) // if search word is the top of the sentence
				{
					strcpy(pat, "\0");
					strcat(pat, "*");
					strcat(pat, pattern[i]);
					strcat(pat, "* ");
			
		 			printf("%s", pat);
					test += lenpattern;
		 			printf("%s", test);
		 			printf("\n");
		 		}
				else
				{
					strncpy(pat, sentence, len);
					strcat(pat, "*");
					strcat(pat, pattern[i]);
					strcat(pat, "* ");

		 			printf("%s", pat);
		 
					test = test + lenpattern;
		 			printf("%s", test);
		 			printf("\n");
				}
			}

		}							
}
