//accept LL from user and Display addition of digit.

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

void SumDigits(PNODE Head)
{
	int iSum=0,iNo=0,iDigit=0;
	
	while(Head!=NULL)
	{
		iNo=Head->data;
		while(iNo!=0)
		{
			iSum=iSum+(iNo%10);
			iNo=iNo/10;
		}
		printf("%d:%d\n",Head->data,iSum);
		iSum=0;
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
	SumDigits(first);

	return 0;
}

