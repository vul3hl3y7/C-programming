/*
 *Proj #8 term counting using hashing
 *
 *Author: 400410043
 *
 *Date:5/12
 *
 *程式描述:從file.txt讀檔案,一次讀一行為一個斷詞,存進hash table

 hash function可使用 hash31 hash33 

 程式執行:

 ./hash file.txt

 Compare it's speed to BST version

 下載測檔:
 fetch http://0rz.tw/rnAt0
 一百萬筆資料

 按照count 由大到小輸出

 輸出

 comparsion次數(呼叫strcmp次數)

 輸入insert的次數
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAXWORD 64
#define MAXLINE 1000
#define TABSIZE 500000

struct node
{
		int count;
		char name[MAXLINE];
		struct node *lc;
		struct node *rc;
};

struct lnode { 
		char name[MAXLINE];
		int count;
		struct lnode *next;
};
struct hash{
		struct lnode *link;
};
int tcmp = 0;
int state = 0;
struct node* insert(struct node* head, char temp[]);
int match(struct node* head,struct node** array,int x);
int prnt(struct node* head,int num);
int charcmp(const void *a,const void  *b);
int charcmp2(const void *a,const void  *b);
void bst_print(struct lnode* head);
struct lnode* link(struct lnode* head, char temp[]);

int main(int argc , char *argv[])
{
		double start, end, time;
		FILE *fp;
		struct node *head = NULL;
		struct node **array = NULL;
		struct lnode **array2 = NULL;
		struct hash *tab = NULL;
		int c;
		int x = 0;
		unsigned int y = 0;
		int line = 0;
		int num = 0;
		char temp[MAXLINE];
		if(argc != 2)
		{
				printf("Usage:./hw8\t[filename]\n");
				exit(0);
		}
		fp = fopen(argv[1],"r");
		if(fp == NULL)
		{
				printf("No file\n");
				exit(0);
		}
		start = (double) clock() / CLOCKS_PER_SEC;
/*						while((c = getc(fp))!=EOF)
						{
						if(c == ' ' || c == '\t')
						{
						continue;
						}
						else if(c == '\n')
						{
						temp[num] = '\0';
		//	point = head;
		if(head == NULL)
		{
		head = insert(head,temp);
		}
		else
		{
		insert(head,temp);
		}
		//				printf("%s\n",head->name);
		num = 0;
		continue;
		}
		temp[num] = c;
		num++;
		line++;
		if(num > MAXLINE)
		{
		printf("Too long");
		exit(0);
		}
		}
		if(c == EOF && line == 0)
		{
		printf("No data\n");
		}
		num = prnt(head,0);
		array = (struct node**)malloc(sizeof(struct node*)*num);
		match(head,array,x);
		qsort(array,num,sizeof(struct node*),charcmp);
		 		end = (double) clock() / CLOCKS_PER_SEC;
				for(x = 0;x < num;x++)
				{
				printf("%d\t%s\n",array[x]->count,array[x]->name);
				}
*/		fclose(fp);
		time = end - start;
		printf("bst:\ntime: %lfs\n", time);
		//===============================================================================================
		fp = fopen(argv[1],"r");
		tab = (struct hash*)malloc(sizeof(struct hash)*TABSIZE);
		start = (double) clock() / CLOCKS_PER_SEC;
		unsigned int z = 0;
		num = 0;
		line = 0;
/*  	for(x = 0;x < TABSIZE;x++)
		{
				tab[x].count = 0;
		}*/
		while((c = getc(fp))!=EOF)
		{
				if(c == ' '|| c == '\t')
				{
						continue;
				}
				else if(c == '\n')
				{
						temp[num] = '\0';
						for(x = 0;x < num;x++)
						{
								y=(y<<5)+y+temp[x];
						}
						z = y%TABSIZE;
						if(z < 0)
						{
								printf("%d\n",z);
								exit(0);
						}
						//	for(;z < TABSIZE;)
						//	{
						if(tab[z].link == NULL)
						{
								tab[z].link = link(tab[z].link,temp);
						}
						else
						{
								link(tab[z].link,temp);
						}
						//			if(t == 1)
						//			{
						//					t = 0;
						//					break;
						//			}
						//			z++;
						//			if(z >= TABSIZE)
						//			{
						//					z = 0;
						//			}
						//	}
						//				printf("%s\n",head->name);
						num = 0;
						y = 0;
						continue;
				}
				temp[num] = c;
				num++;
				line++;
				if(num > MAXLINE)
				{
						printf("Too long");
						exit(0);
				}
		}
		if(c == EOF && line == 0)
		{
				printf("No data\n");
		}
		end = (double) clock() / CLOCKS_PER_SEC;
	//	return 0;
		struct lnode *point = NULL;
		for(z = 0;z < TABSIZE;z++)
		{
				if(tab[z].link != NULL)
				{
						point = tab[z].link;
						while(point != NULL)
						{
								state++;
								point = point->next;
						}
				}
		}
		x = 0;
		printf("%d\n",state);
		array2 = (struct lnode**)malloc(sizeof(struct lnode*)*state);
		for(z = 0;z < TABSIZE;z++)
		{
				if(tab[z].link != NULL)
				{
						point = tab[z].link;
						while(point != NULL)
						{
								array2[x] = point;
								x++;
								point = point->next;
								if(x > state)
								{
										printf("ok");
										exit(0);
								}
						}
				}
		}
		qsort(array2,state,sizeof(struct lnode**),charcmp2);
	//	end = (double) clock() / CLOCKS_PER_SEC;
		time = end - start;
		fclose(fp);
		printf("cmp:%d\n",tcmp);
		for(x = 0;x < state;x++)
		{
				printf("%d\t%s\n",array2[x]->count,array2[x]->name);			 
				//	printf("%d\n",tab[x].count);
		//			bst_print(tab[x].link);
				//				printf("\n");
		}
		printf("hash:\ntime: %lfs\n", time);
		return 0;
}
int charcmp2(const void *a, const void *b)
{
		if((*(struct lnode**)b)->count-(*(struct lnode**)a)->count != 0)
			{	return (*(struct lnode**)b)->count-(*(struct lnode**)a)->count;}
		else
		{
				return strcmp((*(struct lnode**)b)->name,(*(struct lnode**)a)->name);
		}
}

void bst_print(struct lnode* head)
{
		if(head == NULL)
		{
				return;
		}
		//		printf("%d\n",tcmp);
		printf("%d\t%s\n",head->count,head->name);
		if(head->next != NULL)
		{
				bst_print(head->next);
		}
}

struct lnode* link(struct lnode* head,char temp[])
{
		if(head == NULL)
		{
				head = (struct lnode*)malloc(sizeof(struct lnode));
				head->next = NULL;
				strcpy(head->name,temp);
				head->count=1;
		//		printf(">>%s\n",head->name);
		}
		else 
		{
				tcmp++;
				if(strcmp(temp,head->name) == 0)
				{
						head->count+=1;
				}
				else if(strcmp(temp,head->name) != 0)
				{
						head->next = link(head->next,temp);
				}
		}
		return head;
}


int match(struct node* head,struct node** array,int x)
{
		array[x] = head;
		x++;
		if(head->lc != NULL)
		{
				x = match(head->lc,array,x);
		}
		if(head->rc != NULL)
		{
				x = match(head->rc,array,x);
		}
		return x;
}

int prnt(struct node* head,int num)
{
		if(head->lc != NULL)
		{
				num = prnt(head->lc,num);
		}
		num++;
		if(head->rc != NULL)
		{
				num = prnt(head->rc,num);
		}
		return num;
}

struct node* insert(struct node* head,char temp[])
{
		if(head == NULL){
				head = (struct node*)malloc(sizeof(struct node));
				head->lc = NULL;
				head->rc = NULL;
				strcpy(head->name,temp);
				head->count=1;
		}
		else {
				if(strcmp(temp,head->name) > 0)
						head->rc=insert(head->rc,temp);
				else if(strcmp(temp,head->name) < 0)
						head->lc=insert(head->lc,temp);
				else head->count+=1;
		}
		return head;
}
int charcmp(const void *a, const void *b)
{
		return (*(struct node**)b)->count-(*(struct node**)a)->count;
}
