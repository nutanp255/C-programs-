#include<stdio.h>

int DisplayCount(int iNo)
{
	int iDigCnt=0;
	int iCnt=0;
	while(iNo>0)
	{
		int iDigit=iNo%10;
		iDigCnt++;
		iNo=iNo/10;
	}
	return iDigCnt;
}
int main()
{
	int iValue=0;
	int iRet=0;
	
	printf("Enter number");
	scanf("%d",&iValue);
	
	iRet=DisplayCount(iValue);
	printf("Digit count is: %d\n",iRet);
	
	return 0;
	
}