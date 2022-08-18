/*
1gram  4000
2gram  8000
5gram  20000
10gram 40000

*/
#include<stdio.h>

void JwelersPortal(int iWeigth)
{
	if(iWeigth==1)
	{
		printf("your bill amount is 4000\n");
	}	
	
	else if (iWeigth==2)
	{
		printf("your bill amount is 8000\n");
	}

	else if(iWeigth==5)
	{
		printf("your bill amount is 20000\n");
	}	
	
	else if(iWeigth==10)
	{
		printf("your bill amount is 40000\n");
	}	
	
	else
	{
		printf("Invalid weigth\n");
	}
	
}
int main()
{
	int iValue=0;
	printf("Enter the gold coin size that you want to puechase\n");
	scanf("%d",&iValue);
	
	JwelersPortal(iValue);
	
	return 0;
}