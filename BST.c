//Binary Search Tree.

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
}NODE,*PNODE,**PPNODE;

void Insert(PPNODE Head,int iNo)
{
	PNODE temp=*Head;
	PNODE newn=(PNODE)malloc(sizeof(NODE));
	
	newn->data=iNo;
	newn->lchild=NULL;
	newn->rchild=NULL;
	
	if(*Head==NULL)			//BST empty
	{
		*Head=newn;
	}
	else
	{
		while(1)
		{
			if(iNo>temp->data)			//add data to Right
			{
				if(temp->rchild==NULL)
				{
					temp->rchild=newn;
					break;
				}
			}
			else if(iNo<temp->data)		//add data to Left
			{
				if(temp->lchild==NULL)
				{
					temp->lchild=newn;
					break;
				}
			}
			else if(iNo==temp->data)		//same data
			{
				free(newn);
				printf("Data is already there in BST.");
				break;
			}
		}
	}
}

void Inorder(PNODE Head)
{
	if(Head!=NULL)
	{
		Inorder(Head->lchild);
		printf("%d ",Head->data);
		Inorder(Head->rchild);
	}
}

void Preorder(PNODE Head)
{
	if(Head!=NULL)
	{
		printf("%d ",Head->data);
		Inorder(Head->lchild);
		Inorder(Head->rchild);
	}
}

void Postorder(PNODE Head)
{
	if(Head!=NULL)
	{
		Inorder(Head->lchild);
		Inorder(Head->rchild);
		printf("%d ",Head->data);
	}
}
int main()
{
	PNODE First=NULL;
	
	Insert(&First,11);
	Insert(&First,21);
	Insert(&First,7);
	
	printf("Inorder data\n");
	Inorder(First);
	
	printf("\nPreorder data\n");
	Preorder(First);
	
	printf("\nPostorder data\n");
	Postorder(First);
	
	return 0;
}
//7 11 21	L D R	//Inorder
//11 7 21	D L R	//preorder
//7 21 11	L R D	//postorder.