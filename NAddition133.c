//accept N number from user and perfrom addition of that N number.
#include<stdio.h>
#include<stdlib.h>

int Summation(int Arr[],int iLength)
{
	int i=0,iSum=0;
	for(i=1;i<=iLength;i++)
	{
		iSum=iSum+Arr[i];
	}
	return iSum;	
}
int main()
{
	int iSize=0;
	
	printf("Enter number of elements: \n");
	scanf("%d",&iSize);
	int iCnt=0;
	int iRet=0;
	int *ptr=NULL;
	
	ptr=(int*)malloc(sizeof(int)*iSize);
	
	printf("enter the values: \n");
	
	for(iCnt=1;iCnt<=iSize;iCnt++)
	{
		scanf("%d",&ptr[iCnt]);
	}
	iRet=Summation(ptr,iSize);
	printf("Addition is: %d",iRet);
	
	free(ptr);
	return 0;
}