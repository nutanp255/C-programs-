//accept N number from user and display addition of that number.

#include<stdio.h>
#include<stdlib.h>
int Summation(int Arr[],int iLength)
{
	int iCnt=0;
	int iSum=0;
	for(iCnt=0;iCnt<iLength;iCnt++)
	{
		iSum=iSum+Arr[iCnt];
	}
	return iSum;
}
int main()
{
	int iSize=0;
	int iCnt=0;
	int iRet=0;
	int *ptr=NULL;
	
	printf("Enter the element: ");
	scanf("%d",&iSize);
	
	ptr=(int*)malloc(iSize*sizeof(int));
	printf("values are:\n");
	for(iCnt=0;iCnt<iSize;iCnt++)
	{
		scanf("%d",&ptr[iCnt]);
	}
	iRet=Summation(ptr,iSize);
	printf("Summation is: %d\n",iRet);
	free(ptr);
	return 0;
}