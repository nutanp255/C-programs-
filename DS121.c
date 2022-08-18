#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node*PNODE;
typedef struct node**PPNODE;

void InsertFirst(PPNODE head,int no)
{
	PNODE newn=NULL;
	
	newn=(PNODE)malloc(sizeof(NODE));
	
	newn->data=no;
	newn->next=NULL;
	
	if(*head==NULL)		//LL is empty
	{
		*head=newn;
	}
	else				//LL contain atleast one node
	{
		newn->next=*head;
		*head=newn;
	}
}

void InsertLast(PPNODE head,int no)
{
	PNODE newn=NULL;
	PNODE temp=NULL;
	
	newn=(PNODE)malloc(sizeof(NODE));
	
	newn->data=no;
	newn->next=NULL;
	
	if(*head==NULL)						//LL is empty
	{
		*head=newn;
	}
	else								//LL contain atleast one node
	{
		temp=*head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
	}
}

void Display(PNODE head)
{
	printf("Elements from linkedlist are: \n");
	
	while(head!=NULL)
	{
		printf("|%d|->",head->data);
		head=head->next;
	}
	printf("NULL\n");
}
int Count(PNODE head)
{
	int iCnt=0;	
	while(head!=NULL)
	{
		iCnt++;
		head=head->next;
	}
	return iCnt;
}

int main()
{
	PNODE first = NULL;
	int iRet=0;
	
	InsertFirst(&first,101);		//call by address
	InsertFirst(&first,51);
	InsertFirst(&first,21);
	InsertFirst(&first,11);
	
	Display(first);					//call by value
	iRet=Count(first);
	printf("Number of node are: %d\n",iRet);

	printf("\n");
	
	InsertFirst(&first,1);
	Display(first);					//call by value
	iRet=Count(first);
	printf("Number of node are: %d\n",iRet);
	
	printf("\n");
	printf("Insert node at last:\n");
	InsertLast(&first,111);
	InsertLast(&first,121);
	Display(first);
	iRet=Count(first);
	printf("number of node are: %d\n",iRet);

	
	return 0;
}