/*
*	Project 07 : 通訊錄 using BST
*
*		一個使用BST結構儲存的通訊錄

*	Date : 2013/4/30
*
*	Writer : Meng Tseng Tasi
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 1000

typedef struct treeNode
{
	char name[max];
	char phone[max];
	char email[max];
	struct treeNode *left;
	struct treeNode *right;
} treeNode;

int menu();

treeNode * insertNode(treeNode *node, char Name[], char Phone[], char Email[])
{
		
	if(node == NULL)
	{
		treeNode *temp;
		temp = (treeNode *)malloc(sizeof(treeNode));
		strcpy(temp->name, Name);
		strcpy(temp->phone, Phone);
		strcpy(temp->email, Email);
		temp->left = temp->right = NULL;
		return temp;
	}

	if(strcmp(Name, (node->name)) < 0)
	{
		node->left = insertNode(node->left, Name, Phone, Email);		
	}
	else if(strcmp(Name, (node->name)) > 0)
	{
		node->right = insertNode(node->right, Name, Phone, Email);		
	}
	else if(strcmp(Name, (node->name)) == 0)
	{
		strcpy((node->phone), Phone);				
		strcpy((node->email), Email);				
	}

	return node;
}

int inOrder(treeNode *node, treeNode **nodelist, int i)
{
	if (node == NULL)
	{
		return i;		
	}

	i = inOrder(node->left, nodelist, i);

		nodelist[i] = node;
		i++;

	i = inOrder(node->right, nodelist, i);

	return i;
}

void print_list(treeNode **nodelist, int index)
{
	int i;
	
	for (i = 0; i < index; i++)
	{
		printf("%s\t%s\t%s\n", nodelist[i]->name, nodelist[i]->phone, nodelist[i]->email);		
	}
}

void insert_menu(char N[], char P[], char E[])
{
		printf("Please input :\n");
		printf("Name :"); scanf("%s", N);
		printf("Phone :"); scanf("%s", P);
		printf("E-mail :"); scanf("%s", E);
}

void find(treeNode **nodelist, int index, char F[])
{
	int i = 0;
	int f = 0;
	
	for (i = 0; i < index; i++)
	{
		if(strcmp((nodelist[i]->name), F) != 0)
		{
			f = 0;	
		}
		else
		{
			printf("------------------------------------------------\n");
			printf("Name\tPhone\tE-mail\n");		
			printf("------------------------------------------------\n");
			printf("%s\t%s\t%s\n", nodelist[i]->name, nodelist[i]->phone, nodelist[i]->email);
			printf("------------------------------------------------\n");
			f = 1;
				
		}
	}

	if (f == 0)
	{
		printf("Name doesn't exist !\n");		
	}
}

void delete(treeNode *root, treeNode **nodelist, int index, char D[])
{
	int i;
	int f = 0;
	
	for (i = 0; i < index; i++)
	{
		if(strcmp((nodelist[i]->name), D) != 0)
		{
			f = 0;	
		}
		else
		{
			int j = i + 1;
			for (; i < index; i++)
			{
				nodelist[i] = nodelist[j];
				j++;
			}
			f = 1;			
		}
	}


	if (f == 0)
	{
		printf("Name doesn't exist !\n");		
	}		
}

int main(int argc, char *argv[])
{ 
	FILE *fp;

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

	char **P;
	P = (char **)malloc(max * sizeof(char *)); 
	for(i = 0; i < max; i++)
	{
		P[i] = (char *)malloc(64 * sizeof(char));		
	}
	
	char **E;
	E = (char **)malloc(max * sizeof(char *)); 
	for(i = 0; i < max; i++)
	{
		E[i] = (char *)malloc(64 * sizeof(char));		
	}

	int num = 0;
	treeNode *root = NULL;

	while(fscanf(fp, "%s\t%s\t%s\n", N[num], P[num], E[num]) != EOF)
	{
		root = insertNode(root, N[num], P[num], E[num]);
		num++;
	}

	int pri = 0;

	treeNode **nodelist;

	nodelist = (treeNode **)malloc(max * sizeof(treeNode *));
	for(i = 0; i < max; i++)
	{
		nodelist[i] = (treeNode *)malloc(sizeof(treeNode));		
	}

	i = 0;
	int index = inOrder(root, nodelist, i);
	
	int choose = 0;
	
	while(choose != 5)
	{
		choose = menu();

		switch(choose)
		{
			case 1:
			{
				pri = 1;
				printf("------------------------------------------------\n");
				printf("Name\tPhone\tE-mail\n");		
				printf("------------------------------------------------\n");
				print_list(nodelist, index);
				printf("------------------------------------------------\n");
				pri = 0;

				break;
			}
			case 2:
			{
				int flag = 0;

				while(flag == 0)
				{
					num++;	
					insert_menu(N[num], P[num], E[num]);
					root = insertNode(root, N[num], P[num], E[num]);
					index = inOrder(root, nodelist, i);

					flag = 1;

					while(flag == 1)
					{
						char input[max];	
						printf("Insert more ? Y/N\n");
						setbuf(stdin, NULL);
        				fgets(input, sizeof(input), stdin);
        				*(input+strlen(input)-1)='\0';

        				if(strlen(input) == 1 && (*input == 'y' || *input == 'Y'))
        					{
            					printf("------------------\n");
            					flag = 0;
        					}
        				else if(strlen(input)==1 && (*input == 'n' || *input == 'N'))
        					{
            					flag = -1;
        					}
        				else
        					{
            					printf("Wrong instruction !\n");
            					flag = 1;
        					}
        			}
				}
				break;	
			}

			case 3:
			{
				char D[max];
				printf("Input the name to delete.\n");
				scanf("%s", D);
				delete(root, nodelist, index, D);
				break;	
			}

			case 4:
			{
				char F[max]	;
				printf("Input the search name.\n");
				scanf("%s", F);
				find(nodelist, index, F);
				break;	
			}

			case 5: return 0;
			default:
			{
			   	printf("Wrong instruction !\n");
				break;
			}
		}
	}

	return 0;
}

int menu()
{
	int c = 0;	
	printf("1) list\n");		
	printf("2) insert\n");		
	printf("3) delete\n");		
	printf("4) find\n");		
	printf("5) exit\n");		
	printf("input a command : ");
	
	scanf("%d", &c);
	
	return c;
}
