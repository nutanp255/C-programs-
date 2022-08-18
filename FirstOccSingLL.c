//First occurence

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

int SearchFirstOccurence(PNODE Head,int iNo)
{
	int iPos=1;
	
	while(Head!=NULL)
	{
		if(Head->data==iNo)
		{
			break;
		}
		iPos++;
		Head=Head->next;
	}
	if(Head==NULL)
	{
		return -1;
	}
	else
	{
		return iPos;
	}
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
	
	Display(first);
	
	iRet=SearchFirstOccurence(first,28);
	if(iRet==-1)
	{
		printf("There is no such element\n");
	}
	else
	{
		printf("Element is there at index: %d\n",iRet);
	}
	return 0;
}

