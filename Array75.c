//Accept N number and extra one number and count frequency of that number in N number.
#include<stdio.h>
#include<stdlib.h>
int CountFreq(int Arr[],int iLength,int iNo)
{
	int iCnt=0;
	int iFreq=0;
	
	for(iCnt=0;iCnt<iLength;iCnt++)
	{
		if(Arr[iCnt]==iNo)
		{
			iFreq++;
		}
	}
	return iFreq;
}
int main()
{
	int iSize=0;
	int iValue=0;
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
	
	printf("enter the element to calculate the frequency:\n");
	scanf("%d",&iValue);
	
	iRet=CountFreq(ptr,iSize,iValue);
	printf("Result is: %d\n",iRet);
	free(ptr);
	return 0;
}