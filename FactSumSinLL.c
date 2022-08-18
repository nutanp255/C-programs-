//accept LL from user and display summation of factor from that number.

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

void FactorSum(PNODE Head)
{
	int iFact=1,iSum=0,iNo=0,i=0;
	
	while(Head!=NULL)
	{
		for(i=1,iNo=Head->data,iSum=0;i<=iNo/2;i++)
		{
			if(iNo%i==0)
			{
				iSum=iSum+i;
			}
		}
		printf("%d: %d\n",Head->data,iSum);
		
		Head=Head->next;
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
	
	InsertFirst(&first,50);
	InsertFirst(&first,20);
	InsertFirst(&first,38);
	InsertFirst(&first,24);
	InsertFirst(&first,22);
	
	Display(first);
	FactorSum(first);

	return 0;
}

