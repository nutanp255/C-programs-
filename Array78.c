//Accept N number from user as well as one number search that number in array and return indexed of that array.(search first occrenced)

#include<stdio.h>
#include<stdlib.h>
int SearchFirstOcc(int Arr[],int iLength,int iNo)
{
	int iCnt=0;
	int iFreq=0;
	
	for(iCnt=0;iCnt<iLength;iCnt++)
	{
		if(Arr[iCnt]==iNo)
		{
			break;
		}
	}
	if(iCnt==iLength)
	{
		return -1;
	}
	else
	{
		return iCnt;
	}
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
	
	iRet=SearchFirstOcc(ptr,iSize,iValue);
	if(iRet==-1)
	{
		printf("There is no such element in array\n");
	}
	else
	{
		printf("Element first occurance at: %d\n",iRet);
	}
	free(ptr);
	return 0;
}