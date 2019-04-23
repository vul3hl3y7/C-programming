 /*
  *   Project 05 : Finding the longest word and biggest number
  *
  *       The program can identify the paragraph of user input to find the longest word and biggest number.
  *
  *   Writer : Meng Tseng Tasi
  *
  *   Date : 2012/10/30
  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(void)
{
		char tmp[100] = {}, buf[1000] = {}, *p = NULL;
		int i = 0, max = 0;
		
		printf("Please input your data.\n");
		
		 while (fgets(buf, 1000, stdin) != NULL)
		{
				p = strtok(buf, "\n\t ");
				i = - 2;	// state judgment
				
				while (p != NULL)
				{
						if(i != -2) // break
						{
								if((p = strtok(NULL, "\n\t ")) == NULL )
										break;
						}
						
						for (i = 0; i < (int) strlen(p); i++)
						{
								if(p[i] - '0'> 9 || p[i] - '0' < 0) // judge number or word
								{
										if(strlen(p) > strlen(tmp)) // find longest word
												strncpy(tmp, p, 100);
												i = -1;
												break;
								}
						}
						
						if(i > 0) // find biggest number
						{
								if(atoi(p) > max)
										max = atoi(p);
						}
				}
		
		}
		if (buf != NULL)
		{
		printf("\t-----------------------------\n");
		printf("\t|Longest word : %s\n", tmp);
		printf("\t|Biggest number : %d\n", max);
		printf("\t-----------------------------\n");
		}
		
		return 0;
}
