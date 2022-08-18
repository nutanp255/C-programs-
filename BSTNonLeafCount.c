//accept tree from user and count non Leaf node(node which haven't child node) in our BST.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

bool Search(PNODE Head,int iNo)
{
	bool flag=false;
	
	if(Head==NULL)
	{
		printf("Tree is empty\n");
		return flag;
	}
	
	while(Head!=NULL)
	{
		if(Head->data==iNo)
		{
			flag=true;
			break;
		}
		else if(iNo>Head->data)
		{
			Head=Head->rchild;
		}
		else if(iNo<Head->data)
		{
			Head=Head->lchild;
		}
	}
	return flag;
}


int CountNonLeafNode(PNODE Head)
{
	static int iCnt=0;
	
	if(Head!=NULL)
	{
		if((Head->lchild!=NULL)||(Head->rchild!=NULL))
		{
			iCnt++;
		}
		CountNonLeafNode(Head->lchild);
		CountNonLeafNode(Head->rchild);
	}
	return iCnt;
}

int main()
{
	PNODE First=NULL;
	int iRet=0;
	
	Insert(&First,11);
	Insert(&First,21);
	//Insert(&First,18);
	//Insert(&First,3);
	Insert(&First,7);
	
	printf("Inorder data\n");
	Inorder(First);
	
	printf("\nPreorder data\n");
	Preorder(First);
	
	printf("\nPostorder data\n");
	Postorder(First);
	
	iRet=CountNonLeafNode(First);
	printf("NonLeaf Node are:%d",iRet);
	return 0;
}
//7 11 21	L D R	//Inorder
//11 7 21	D L R	//preorder
//7 21 11	L R D	//postorder.