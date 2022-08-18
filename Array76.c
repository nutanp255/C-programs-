//Accept N number from user accept one another number and check wheather that number is of your arry or not with flag.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool Search(int Arr[],int iLength,int iNo)
{
	int iCnt=0;
	bool bFlag=false;
	
	for(iCnt=0;iCnt<iLength;iCnt++)
	{
		if(Arr[iCnt]==iNo)
		{
			bFlag=true;
			break;
		}
	}
	return bFlag;
}
int main()
{
	int iSize=0;
	int iValue=0;
	int iCnt=0;
	bool bRet=0;
	int *ptr=NULL;
	
	printf("Enter the element: ");
	scanf("%d",&iSize);
	
	ptr=(int*)malloc(iSize*sizeof(int));
	
	printf("values are:\n");
	for(iCnt=0;iCnt<iSize;iCnt++)
	{
		scanf("%d",&ptr[iCnt]);
	}
	
	printf("enter the element to search:\n");
	scanf("%d",&iValue);
	
	bRet=Search(ptr,iSize,iValue);
	if(bRet==true)
	{
		printf("NUmber is in your array");
	}
	else
	{
		printf("Number is not in your array");
	}
	free(ptr);
	return 0;
}