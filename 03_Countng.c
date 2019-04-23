/*
*	Project03: Counting
*		
*		The program to read user input and indentify what are they.
*
*	Writer: Meng Tseng Tasi
*
*	Date: 2012/10/21
*
*/

#include <stdio.h>

int
main(void)
{
	int nl = 0, nc = 0, nb = 0, na = 0, ne = 0, ni = 0, no = 0, nu = 0, ae = 0;
	int c;
	printf("Input data.\n");
	while ((c = getchar()) != EOF)
		{
			nc++;
			switch(c)
				{
					// read numbers of line
					case '\n':
						nl++;
						
						break;

					// read numbers of digit
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
						nb++;
						break;

					// read numbers of vowel
					case 'A':
					case 'a':
						na++;
						ae++;
						break;

					case 'E':
					case 'e':
						ne++;
						ae++;
						break;
					
					case 'I':
					case 'i':
						ni++;
						ae++;
						break;
					
					case 'O':
					case 'o':
						no++;
						ae++;
						break;
					
					case 'U':
					case 'u':
						nu++;
						ae++;
						break;
					
					case 'B':
					case 'b':
					case 'C':
					case 'c':
					case 'D':
					case 'd':
					case 'F':
					case 'f':
					case 'G':
					case 'g':
					case 'H':
					case 'h':
					case 'J':
					case 'j':
					case 'K':
					case 'k':
					case 'L':
					case 'l':
					case 'M':
					case 'm':
					case 'N':
					case 'n':
					case 'P':
					case 'p':
					case 'Q':
					case 'q':
					case 'R':
					case 'r':
					case 'S':
					case 's':
					case 'T':
					case 't':
					case 'V':
					case 'v':
					case 'W':
					case 'w':
					case 'x':
					case 'X':
					case 'Y':
					case 'y':
					case 'Z':
					case 'z':
						ae++;
						break;

					
						
						
						}
				}
	printf("\t--------------------\n");
	printf("\t|Lines : %d\n", nl);
	printf("\t|Characters : %d\n", nc);
	printf("\t|Digits : %d\n", nb);
	printf("\t|'a' : %d\n", na);
	printf("\t|'e' : %d\n", ne);
	printf("\t|'i' : %d\n", ni);
	printf("\t|'o' : %d\n", no);
	printf("\t|'u' : %d\n", nu);
	printf("\t--------------------\n");
	printf("\t|Vowel\t|Proportion\n");
	printf("\t|'a'\t| %.2f percent\n", (na) / (float)ae * 100);
	printf("\t|'e'\t| %.2f percent\n", (ne) / (float)ae * 100);
	printf("\t|'i'\t| %.2f percent\n", (ni) / (float)ae * 100);
	printf("\t|'o'\t| %.2f percent\n", (no) / (float)ae * 100);
	printf("\t|'u'\t| %.2f percent\n", (nu) / (float)ae * 100);
	printf("\t--------------------\n");

	return 0;	
		}
