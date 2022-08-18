//accept N number from uer and return largest number from that N number.

#include<stdio.h>
#include<stdlib.h>

int Maximum(int Arr[],int iLength)
{
	int iCnt=0;
	int iMax=Arr[0];
	for(iCnt=0;iCnt<iLength;iCnt++)
	{
		if(iMax<Arr[iCnt])
		{
			iMax=Arr[iCnt];
		}
	}
	return iMax;
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
	iRet=Max(ptr,iSize);
	printf("Largest element is: %d\n",iRet);
	free(ptr);
	return 0;
}