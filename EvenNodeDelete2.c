//write a program which accept LL from user and delete the even node from that LL.

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

void Display(PNODE Head)
{
	printf("Elements of Linked List are:\n");
	while(Head!=NULL)
	{
		printf("|%d|->",Head->data);
		Head=Head->next;
	}
	printf("NULL\n");
}

void DisplayEven(PNODE Head)
{
	int iPos=1;
	
	while(Head!=NULL)
	{
		if((Head->data%2)==0)
		{
			printf("position : %d Data : %d\n",iPos,Head->data);
		}
		Head=Head->next;
		iPos++;
	}
}

void DeleteEvenNode(PPNODE Head)
{
	PNODE First=NULL;
	PNODE Second=NULL;
	PNODE temp=NULL;
	
	if(*Head==NULL)		//if LL empty
	{
		return;
	}
	
	if((*Head)->next==NULL)		//LL contains one node.
	{
		if((((*Head)->data)%2)==0)
		{
			free(*Head);
			*Head=NULL;
			return;
		}
		else
		{
			return;
		}
	}
	
	First=*Head;
	Second=(*Head)->next;
	
	while(Second!=NULL)
	{
		if((Second->data)%2==0)
		{
			temp=Second;
			First->next=Second->next;
			free(temp);
			Second=First->next;
		}
		else
		{
			First=Second;
			Second=First->next;
		}
	}
	
	if(((*Head)->data)%2==0)
	{
		temp=*Head;
		(*Head)=(*Head)->next;
		free(temp);
	}
}

int main()
{
	PNODE first=NULL;
	int iRet=0;
	
	InsertFirst(&first,55);
	InsertFirst(&first,41);
	InsertFirst(&first,31);
	InsertFirst(&first,29);
	InsertFirst(&first,11);
	InsertFirst(&first,21);
	InsertFirst(&first,23);
	InsertFirst(&first,51);

	
	Display(first);
	DeleteEvenNode(&first);
	Display(first);
	

	return 0;
}

