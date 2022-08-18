#include<stdio.h>

int DisplayFact(int iNo)
{
	int iCnt=0;
	int iSumFact=0;
	int iNonFact=0;
	int diff=0;
	
	for(iCnt=1;iCnt<iNo;iCnt++)
	{
		ifzq(iNo%iCnt==0)
		{
			printf("%d\n",iCnt);
			iSumFact=iSumFact+iCnt;
		}
		else if(iNo%iCnt!=0)
		{
			printf("%d\n",iCnt);
			iNonFact=iNonFact+iCnt;
		}
	}
	return iSumFact-iNonFact;
	//diff=iSumFact-iNonFact;
	//return diff;
}
int main()
{
	int iValue=0;
	int iRet=0;
	
	printf("Enter the number:");
	scanf("%d",&iValue);
	
	iRet=DisplayFact(iValue);
	printf("difference is:%d ",iRet);
	
	return 0;
}
