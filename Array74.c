//accept N number from uer and return smallest number from that N number.

#include<stdio.h>
#include<stdlib.h>

int Minimum(int Arr[],int iLength)
{
	int iCnt=0;
	int iMin=Arr[0];
	for(iCnt=0;iCnt<iLength;iCnt++)
	{
		if(iMin>Arr[iCnt])
		{
			iMin=Arr[iCnt];
		}
	}
	return iMin;
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
	iRet=Minimum(ptr,iSize);
	printf("Smallest element is: %d\n",iRet);
	free(ptr);
	return 0;
}