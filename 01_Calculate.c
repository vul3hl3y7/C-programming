/* *
 *
 *  Project: Calculate.
 *	
 *		In order to deal with two numbers' plus, minus, multiplt, except. 
 *	
 *	Writer: Meng Tseng Tasi
 *  Date: 2012/10/9
 *
 *
 */


#include<stdio.h>

int 
main(void)
{
		int a, b;

		printf("Input two non zero number ?\n");
		scanf("%d %d", &a, &b);
		while(a != 0 || b != 0)
		{				
				printf("%d + %d = %d\n", a, b, a + b);
				printf("%d - %d = %d\n", a, b, a - b);
				printf("%d * %d = %d\n", a, b, a * b);
				printf("%d / %d = %d\n", a, b, a / b);
				printf("Input two non zero number ?\n");
				scanf("%d %d", &a, &b);
		}

		return 0;
}
