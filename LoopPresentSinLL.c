//accpet LL from user and Detect the loop is present or not in LL.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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
bool CheckLoop(PNODE Head)
{
	PNODE Fast=Head;
	PNODE Slow=Head;
	bool Flag=false;
	
	while((Fast!=NULL)&&(Fast->next!=NULL))
	{
		Slow=Slow->next;
		Fast=Fast->next->next;
		
		if(Fast==Slow)
		{
			Flag=true;
			break;
		}
	}
	return Flag;
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
	bool bRet=0;
	
	PNODE Third=NULL;
	PNODE Last=NULL;
	
	InsertFirst(&first,6);
	InsertFirst(&first,30);
	InsertFirst(&first,496);
	InsertFirst(&first,24);
	InsertFirst(&first,22);
	InsertFirst(&first,28);
	InsertFirst(&first,25);
	
	Third=first;	//100
	Last=first;	//100
	
	Third=Third->next->next;			//300
	Last=Last->next->next->next->next;	//500
	
	Last->next=Third;
	
	bRet=CheckLoop(first);
	if(bRet==true)
	{
		printf("There is loop in linked list.");
	}
	else
	{
		printf("there is no loop in linked list.");
	}

	return 0;
}

