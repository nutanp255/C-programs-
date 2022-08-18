//accept LL from user and return value of middle element.

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

int MiddleElement(PNODE Head)
{
	int iSize=0;
	int i=0;
	PNODE temp=Head;
	
	while(Head!=NULL)
	{
		iSize++;
		Head=Head->next;
	}
	Head=temp;
	
	for(i=0;i<iSize/2;i++)
	{
		Head=Head->next;
	}
	return Head->data;
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
	
	InsertFirst(&first,6);
	InsertFirst(&first,28);
	InsertFirst(&first,496);
	InsertFirst(&first,24);
	InsertFirst(&first,22);
	InsertFirst(&first,28);
	InsertFirst(&first,25);
	
	Display(first);
	iRet=MiddleElement(first);
	printf("Middle element is:%d",iRet);
	
	return 0;
}

