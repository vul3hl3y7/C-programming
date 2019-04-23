/*

*	Project 05 : tcount_l
*
*	½Ð¼¶¼g¤@­Ó³z¹LLinked-list ²Î­pÃöÁä¦r¼Æ¶qªºµ{¦¡µ, {¦¡·|Åª¤J¤@­ÓDataFile
*	DataFile format : A name (term) in a line, ½Ð¥Hbubble sortªº¤è¦¡sort ¾ã­ÓLinked list, ¨Ã¥Hcountingµ²ªGdecreasing order ¿é¥Xµ²ªG
*
*	Date : 2013/4/5
*
*	Writer : Meng Tseng Tasi
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 1000

struct data
{
	char name[64];
	struct data *next;
} ;

struct data *current = NULL;
struct data *first = NULL;
struct data *new = NULL;

int indexstr(struct data *top, int num, int *count, char **S);
void swap(char *p, char *q);
struct data *bubble_sort(struct data *top, int num);
void print(int item, int *count, char **S);

int main(int argc, char *argv[])
{ 
	FILE *fp;

	first = (struct data*)malloc(max * sizeof(struct data));
//	current = (struct data*)malloc(sizeof(struct data));

	if(argc != 2)
	{
		printf("Error argument !\n");
		return 0;
	}

	fp = fopen(argv[1], "r");

	if(fp == NULL)
	{
		printf("Wrong file !\n");
		return 0;
	}

	char **N;
	int i;

	N = (char **)malloc(max * sizeof(char *)); 
	for(i = 0; i < max; i++)
	{
		N[i] = (char *)malloc(64 * sizeof(char));		
	}

	int num = 0;

	current = first;
	current->next = NULL;

	while(fscanf(fp, "%s\n", N[num]) != EOF)
	{
		strcpy(current->name, N[num]);
		num++;

		new = (struct data*)malloc(sizeof(struct data));
		new->next = NULL;
		current->next = new;
		current = current->next;
	}

	first = bubble_sort(first, num);

	int item = 0;
	int *count;
	char **S;

	count = (int *)malloc(max * sizeof(int));

	S = (char **)malloc(max * sizeof(char *));
	for(i = 0; i < max; i++)
	{
		S[i] = (char *)malloc(64 * sizeof(char));	
	}
	item = indexstr(first, num, count, S);
	print(item, count, S);

	return 0;
}

struct data *bubble_sort(struct data *top, int num)
{
	struct data *head = top;
	struct data **buf = NULL;
	int i, j;
 
	if(head == NULL)
			return NULL;

	buf = (struct data **) calloc(num + 1, sizeof(struct data *));

	for(i = 0; i < num; i++)
	{
			buf[i] = head;
			head = head -> next;
	}
	
	for(i = 0; i < num; i++)
			for(j = i; j > 0; j--)
			{
					if(strcmp(buf[j] -> name, buf[j-1] -> name) <= 0)
					{
							head = buf[j];
							buf[j] = buf[j-1];
							buf[j-1] = head;
					}
			}
	for(i = 0; i < num; i++)
	{
			buf[i] -> next = buf[i+1];
	}
	head = buf[0];
	free(buf);
	return head;
}

int indexstr(struct data *top, int num, int *count, char **S)
{
	int i;
	int j = 0;
	struct data *now = NULL;

	now = top;

	for(i = 0; i < num; i++)
	{
		count[i] = 1 ;		
	}

	while(now->next != NULL)
	{
			if(strcmp(now->name, (now->next)->name) == 0)
			{
			strcpy(S[j], now->name);
				count[j]++;		
			}
			else
			{
			strcpy(S[j], now->name);
				j++;
			}
				now = now->next;
	}

	strcpy(S[j], now->name);

	return j + 1;
}	

void print(int item, int *count, char **S)
{
	int i, j;

	for(i = item - 1; i > 0; i--)
	{
		for(j = 0; j <= i - 1; j++)
		{
			if(count[j] < count[j + 1])
			{
				int temp = count[j];		
				count[j] = count[j + 1];		
				count[j + 1] = temp;
				
				char tmp[64];
					strcpy(tmp, S[j]);
					strcpy(S[j], S[j+1]);
					strcpy(S[j+1], tmp);
			}
		}
	}

	for(i = 0; i < item; i++)
	{
		printf("%d %s\n", count[i], S[i]);		
	}
}
