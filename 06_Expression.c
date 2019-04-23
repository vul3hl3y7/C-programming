/*
 *	Project #6: Simple expression calculator
 *
 *		The program could do plus, minus, multiply, divide, remainder, change binary system.
 *
 *	Date : 2012/11/23
 *
 *	Writer : Meng Tseng Tasi
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void tentotwoint(unsigned long );
void tentotwofloat(float );

int 
main(void){
		
		char c;
		float a = 0;
		float b = 0;
		float result = 0;
		int round = 0;
		int x = 0;

		printf("Please input an operator.\n");

		while (( c = getchar()) != '!')
		{
				if (round == 0)
				{
						if ( c != '+' && c != '-' && c!= '*' && c!= '/' && c!= '%' && c!= '#')
								printf("You should input operator !\n");

				}
				round++;

				switch(c)
				{
						
						// plus
						case '+' :
								if (round != 0)
								{
										scanf("%f %f", &a, &b);
										result = a + b;
										printf("%f\n", result);
								}
								break;

						// minus
						case '-' :
								if (round != 0)
								{
										scanf("%f %f",&a, &b); 
										result = a - b;
										printf("%f\n",result);
								}
								break;

						// multiply
						case '*' :
								if (round != 0)
								{
										scanf("%f %f",&a, &b);
										result = a * b;
										printf("%f\n",result);
								}
								break;

						// divide
						case '/' :
								if (round != 0)
								{
										scanf("%f %f",&a, &b);
										if (b == 0){
												printf("Denominator cannot be zero !\n");
												break;
										}
										else {
												result = a / b;
												printf("%f\n",result);
												break;
										}
										break;
								}
								break;

						// reminder
						case '#' :
								if (round != 0)
								{
										scanf("%d", &x);
							
												int i;
												for (i = 31; i >= 0; i--){
														printf("%d",x>>i&1);
												}
												printf("\n");
												break;
										
								}
								break;

						// change binary system
						case '%' :
								if (round != 0)
								{
										scanf("%f %f", &a, &b);
										result = (int)a % (int)b;
										printf("%f\n", result);
								}
								break;
				}
		}

		return 0;
}

void tentotwoint(unsigned long n)
{
		int r = 0;
		r = n % 2;
		if (n >= 2)
				tentotwoint(n/2);
		putchar(r ? '1' : '0');

}

void tentotwofloat(float n)
{
		int m = 0;
		float f;
		m = (int)n;

		if (n < 0.0)
				putchar('-');
		tentotwoint((int)fabs(n));

		f = fabs((float)(n - (float)m));

		if(f > 0.0)
		{
				putchar('.');
				f *= 2.0;
				printf("%d", (int)f);
				if (f >= 1.0)
						f -= 1.0;
		}

}
