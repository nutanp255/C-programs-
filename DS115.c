#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node*next;
};
int main()
{
	//static memory allocation
	struct node obj;
	
	//Dyanamic memeory allocation
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	
	obj.data=11;		//direct accessing operator.
	obj.next=NULL;
	
	ptr->data=11;		//indirect accessing operator->
	ptr->next=NULL;
	
	free(ptr);
	
	return 0;
}