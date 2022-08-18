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

void DeleteFirst(PPNODE head)
{
	PNODE temp=NULL;
	if(*head==NULL)
	{
		return;
	}
	else
	{
		temp=*head;
		*head=temp->next;
		free(temp);
	}
}

void DeleteLast(PPNODE head)
{
	PNODE temp=NULL;
	
	if(*head==NULL)
	{
		return;
	}
	else if((*head)->next==NULL)
	{
		free(*head);
		*head=NULL;
	}
	else
	{
		temp=*head;
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		free(temp->next);
		temp->next=NULL;
	}
}

void InsertAtPos(PPNODE head,int no,int pos)
{
	int size=0;
	int iCnt=0;
	PNODE temp=NULL;
	PNODE newn=NULL;
	size=Count(*head);
	
	if((pos<1)||(pos>(size+1)))
	{
		printf("Position is invalid\n");
		return;
	}
	if(pos==1)
	{
		InsertFirst(head,no);
	}
	else if(pos==(size+1))
	{
		InsertLast(head,no);
	}
	else
	{
		newn=NULL;
		newn=(PNODE)malloc(sizeof(NODE));
	
		newn->data=no;
		newn->next=NULL;
		
		temp=*head;
		for(iCnt=1;iCnt<pos-1 ;iCnt++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next=newn;
	
	}
	
}

void DeleteAtPos(PPNODE head,int pos)
{
	int size=0,iCnt=0;
	PNODE temp=NULL;
	PNODE tempdelete=NULL;
	
	size=Count(*head);
	if((pos<1)||(pos>size))
	{
		printf("Position is invalid\n");
		return;
	}
	if(pos==1)
	{
		DeleteFirst(head);
	}
	else if(pos==(size))
	{
		DeleteLast(head);
	}
	else
	{
		temp=*head;
		for(iCnt=1;iCnt<pos-1;iCnt++)
		{
			temp=temp->next;
		}
		tempdelete=temp->next;
		temp->next=temp->next->next;
		free(tempdelete);
	}
}

int main()
{
	PNODE first = NULL;
	int iRet=0;
	
	InsertFirst(&first,101);		//call by address
	InsertFirst(&first,51);
	InsertFirst(&first,21);
	InsertFirst(&first,11);
	
	InsertAtPos(&first,75,3);
	
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
	
	printf("\n");
	printf("Delete first node: \n");
	DeleteFirst(&first);
	Display(first);
	iRet=Count(first);
	printf("Number of node are: %d\n",iRet);
	
	DeleteFirst(&first);
	Display(first);
	iRet=Count(first);
	printf("Number of node are: %d\n",iRet);
	
	printf("\n");
	printf("Delete last node: \n");
	DeleteLast(&first);
	Display(first);
	iRet=Count(first);
	printf("Number of node are: %d\n",iRet);
	
	printf("\n");
	printf("DeleteAtPos node: \n");
	DeleteAtPos(&first,3);
	Display(first);
	iRet=Count(first);
	printf("Number of node are: %d\n",iRet);
	
	
	return 0;
}