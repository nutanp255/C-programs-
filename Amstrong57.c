//accept number from user and check wheather number is amstrong or not.
#include<stdio.h>
#include<stdbool.h>

bool CheckAmstrong(int iNo)
{
	int iDigCnt=0;
	int iDigit=0;
	int iTemp=0;
	int iSum=0;
	int iCnt=1; int iMult=1;
	
	if(iNo<0)
	{
		iNo=-iNo;
	}
	iTemp=iNo;

//Calculate number of digits.
	
	while(iNo>0)
	{
		iDigCnt++;
		iNo = iNo/10;
	}
	
	iNo=iTemp;
	
	while(iNo>0)
	{
		iMult=1;
		iDigit=iNo%10;
		
		for(iCnt=1;iCnt<=iDigCnt;iCnt++)
		{
		iMult = iMult * iDigit;
		}
		iSum=iSum+ iMult;
		iNo=iNo/10;
	}
	if(iSum==iTemp)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	int iValue=0;
	bool bRet;
	
	printf("Enter number:\n");
	scanf("%d",&iValue);
	
	bRet=CheckAmstrong(iValue);
	if(bRet==true)
	{
		printf("%d is Amstrong number\n",iValue);
	}
	else
	{
		printf("%d is not Amstrong number\n",iValue);
	}
	return 0;
}