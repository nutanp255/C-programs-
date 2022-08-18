//accept number from user and return the factorial of that number.
//4
//4*3*2*1	24
//1*2*3*4	24

#include<stdio.h>

int Factorial(int iNo)
{
	int iCnt=0;
	int iFact=1;
	for(iCnt=1;iCnt<=iNo;iCnt++)
	{
		iFact=iFact*iCnt;	//iFact*=iCnt;
	}
	return iFact;
}
int main()
{
	int iValue=0;
	int iRet=0;
	printf("Enter the number: \n");
	scanf("%d",&iValue);
	iRet=Factorial(iValue);
	printf("Factorial is: %d",iRet);
	return 0;
}