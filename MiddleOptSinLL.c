//accept LL from user and return value of middle element.(Fast forward algorithm)

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
	PNODE Fast=Head;
	PNODE Slow=Head;
	
	while((Fast!=NULL)&&(Fast->next!=NULL))
	{
		Fast=Fast->next->next;
		Slow=Slow->next;
	}
	return Slow->data;
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
	//InsertFirst(&first,25);
	
	Display(first);
	iRet=MiddleElement(first);
	printf("Middle element is:%d",iRet);
	
	return 0;
}

