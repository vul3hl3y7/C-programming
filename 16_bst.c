/*
*	Project 06 : tcount_l
*
*	請撰寫一個透過Linked-list 統計關鍵字數量的程式讀入一個DataFile
*	DataFile format : A name (term) in a line, 請以binary search tress sort counting結果decreasing order 輸出結果
*
*	Date : 2013/4/28
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
	char name[64];
	int count;
	struct treeNode *left;
	struct treeNode *right;
} treeNode;

treeNode * insertNode(treeNode *node, char name[])
{
		
	if(node == NULL)
	{
		treeNode *temp;
		temp = (treeNode *)malloc(sizeof(treeNode));
		strcpy(temp->name, name);
		temp->left = temp->right = NULL;
		temp->count = 1;
		return temp;
	}

	if(strcmp(name, (node->name)) < 0)
	{
		node->left = insertNode(node->left, name);		
	}
	else if(strcmp(name, (node->name)) > 0)
	{
		node->right = insertNode(node->right, name);		
	}
	else if(strcmp(name, (node->name)) == 0)
	{
		(node->count)++;		
	}

	return node;
}

int inOrder(treeNode *node, treeNode **nodelist, int i)
{
	if (node == NULL)
	{		
		return i;		
	}
		i =	inOrder(node->left, nodelist, i);
			nodelist[i] = node;
			i++;
		i = inOrder(node->right, nodelist, i);

	return i;
}

int compare(void const * a, void const * b)
{
		treeNode *i1 = *(treeNode **)a;
		treeNode *i2 = *(treeNode **)b;
        return i2->count - i1->count;
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

	int num = 0;
	treeNode *root = NULL;

	while(fscanf(fp, "%s\n", N[num]) != EOF)
	{
		root = insertNode(root, N[num]);
		num++;
	}
	
		treeNode **nodelist;

		nodelist = (treeNode **)malloc(max * sizeof(treeNode *));
		for (i = 0; i < max; i++)
		{
			nodelist[i] = (treeNode *)malloc(sizeof(treeNode));
		}

		i = 0;
		
		int index = inOrder(root, nodelist, i);

		qsort(nodelist, index, sizeof(treeNode *), compare);
		for (i = 0; i < index; i++)
		{
			printf("%s %d\n", nodelist[i]->name, nodelist[i]->count);		
		}

	return 0;
}
