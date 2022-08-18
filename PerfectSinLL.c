//accept LL from user and display factor from that number.

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

void DisplayPerfect(PNODE Head)
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
		if(iSum==iNo)
		{
			printf("%d is perfect number\n",iNo);
		}
		
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
	
	InsertFirst(&first,6);
	InsertFirst(&first,28);
	InsertFirst(&first,496);
	InsertFirst(&first,24);
	InsertFirst(&first,22);
	InsertFirst(&first,128);
	
	Display(first);
	DisplayPerfect(first);

	return 0;
}

