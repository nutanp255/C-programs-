//accept  number and accept LL from user and frequency of that number from that LL.

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

typedef struct node NODE;
typedef struct node*PNODE;
typedef struct node**PPNODE;

void InsertFirst(PPNODE Head,int iNo)
{
	PNODE newn=NULL;
	
	newn=(PNODE)malloc(sizeof(NODE));
	
	newn->data=iNo;
	newn->next=NULL;
	
	if(*Head==NULL)				//if LL is empty.
	{
		*Head=newn;
	}
	else						//if LL contains atleast one node.
	{
		newn->next=*Head;
		*Head=newn;
		
	}
}

int Frequency(PNODE Head,int iNo)
{
	int iCnt=0;
	while(Head!=NULL)
	{
		if(Head->data==iNo)
		{
			iCnt++;
		}
		Head=Head->next;
	}
	return iCnt;
}

void Display(PNODE Head)
{
	printf("Elements of Linked List are:\n");
	while(Head!=NULL)
	{
		printf("|%d|->",Head->data);
		Head=Head->next;
	}
	printf("\n");
}

int main()
{
	PNODE first=NULL;
	int iRet=0;
	
	InsertFirst(&first,50);
	InsertFirst(&first,20);
	InsertFirst(&first,30);
	InsertFirst(&first,20);
	InsertFirst(&first,20);
	
	Display(first);
	iRet=Frequency(first,20);
	printf("count of element is:%d",iRet);

	return 0;
}

