/*
 *	Project02:Temperature translate.
 *		
 *		A project for translating temperature from Celsius to Fahrenheit.
 *	
 *	Writer: Meng Tseng Tasi	
 *	Date: 2012/10/16

 */



#include <stdio.h>


#define Max 500
#define min -273


int 
main(void)
{
		int lower, upper, step;
		int i, c, tempc, sc;
		float f, tempf;

		printf("Please input lower, upper, step\n");
		scanf("%d %d %d", &lower, &upper, &step);
		/* Avoid gab cannot move */
		if (step <= 0) {
				printf("Step cannot lower than 0 !\n");
				/* Avoid too big or small value */
		} else if ( (lower < min) || (upper > Max) ) {
				printf("Iuput value out of translating range !\n");
				/* Avoid minmum value bigger than Maximun */
		} else if (lower > upper) {
				printf("The lower value cannot bigger than upper !\n");
		}else{	
				printf("\n---------------------\nCelaius | Fahrenheit\n---------------------\n");
				for(i = lower; lower <= upper; i++)
				{
						c = lower;
						f = c * ((float)9 / (float)5) + (float)32;
						printf("%d \t| %.2f\n", c, f);
						lower = lower + step;
				}		
				printf("---------------------\n");
		}
		printf("Please iuput temperature for search.\n");
		scanf ("%d", &tempc);
		/* Avoid too big or too small value */
		if (tempc < min || tempc > Max) {
			printf("Input value out of translating range !\n");
		}else{
			sc = tempc;
			tempf = sc * ((float)9 / (float)5) + (float)32; 
			printf("\n---------------------\nCelaius | Fahrenheit\n---------------------\n");		
			printf("%d \t| %.2f\n", sc, tempf);
			printf("---------------------\n");
		}
		return 0;

}
