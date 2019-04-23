/*
*	Project 08 : Print shape.
*	
*		The program can print diamond, square, triangle, quadratic.
*
*	Date : 2012/11/27 
*
*	Writer : Meng Tseng Tasi
*
*/

#include <stdio.h>
#include <string.h>

int calnoisword(char str[]);

int main()
{
		char input[100];
		char shape[100];
		
		printf("Which shape do you want to printf ?\n");
		gets(input);
		strcpy(shape, input);

		switch (calnoisword(shape))
		{		
				// diamond
				case 1 :
				{
					int i, j , k;

					// top part
					for (k = 1; k <= 5; k += 2)
					{
						for (i = ( 5 - k) / 2 ;i > 0; i--)
						{
							printf(" ");	
						}
						for (j = 1; j <= k; j++)
						{
						printf("*");		
						}
						printf("\n");			
					}

					// bottom part
					for (k = 3; k >= 0; k -= 2)
					{
						for ( i = ( 5 - k) / 2; i > 0; i--)
						{
						printf(" ");		
						}
						for (j = 1; j <= k; j++ )
						{
						printf("*");		
						}

						printf("\n");		
					}

					break;
				}
				
				// square
				case 2 :
				{
					int i, j;
					for (i = 1; i <= 5; i++)
					{
						for (j = 1; j <= 5; j++)
						{
								if (i == 1 || j == 1 || i == 5 || j == 5)
								printf("*");
								else printf(" ");

								}
						printf("\n");		
							}
					break;
					}
				
				// triangle
				case 3 :
				{
				                              int x, y;
				                                                      int s = 5;
				                                                      for (x = 1; x <= 5; x++)
				                                                      {
				                                                            for (y = 1; y < s; y++)
				                                                            {
				                                                            printf(" ");
				                                                            }
				                                                            for (y = 1; y <= x * 2 - 1; y++)
				                                                            {
				                                                            printf("*");
				                                                            }
				                                                            s--;
				                                                            printf("\n");
				                              
				                                                      }

					  break;
					  }

				// quadratic	
				case 4 :
				{
					int col, row;
					for (row = 30; row >= 0; row--)
					{
						printf("|");
						for (col = 0; col <= 5; col++)
						{
						if (row == col * col) 
						printf("*(%d, %d)", col, row);
						else printf(" ");
						}
						printf("\n");
					}
					printf("__________________________\n");
					
					break;
					}
				default :
				{
					break;	
					}
				}
		
		return 0;
		}

int calnoisword(char str[])
{
	int i;
	int j;
	char word[100];
	int choose = 0;

 // 	printf("%s\n", str);

	for (i = 0; str[i] != '\0'; i++){
			
			if (str[i] != ' ' || str[i] != '\n' || str[i] != '\t'){
					break;
					}
			}
	
	for (; str[i] != '\0'; i++){
			
			if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'){
				break;
				} else {
						for (j = 0; j <= i; j++)
						{
						word[j] = str[i];
						}
						
					}

		}
	 printf("%s\n", word);
	
	int test = strcmp(str, "diamond");

		if (test == 0)
			choose = 1;
		else {
				test = strcmp(str, "square");
				if (test == 0)
						choose = 2;
				else {
						test = strcmp(str, "triangle");
						if (test == 0)
								choose = 3;
						else {
								test = strcmp(str, "quadratic");
								if (test == 0)
										choose = 4;
								else printf("No picture !\n");
								}

						}
				}	

		return choose;
}			
