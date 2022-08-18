#include<stdio.h>
#include<stdlib.h>
int Add(int Arr[],int iLength)
{
	int iCnt=0;
	int iSum=0;
	for(iCnt=0;iCnt<iLength;iCnt++)
	{
		printf("%d",Arr[iCnt]);
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
	iRet=Add(ptr,iSize);
	printf("Result is: %d\n",iRet);
	free(ptr);
	return 0;
}