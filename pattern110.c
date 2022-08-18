//Input: 4 4
/*

* * * *
* * *
* * 
*
*
* * 
* * * 
* * * *

*/

#include<stdio.h>

void Display(int iRow,int iCol)
{
	int i=0;
	int j=0;
	if(iRow!=iCol)
	{
		return;
	}
	
	printf("Pattern is:\n");
	
	for(i=iRow;i>=1;i--)
	{
		for(j=1;j<=i;j++)      //optimization of loop
		{
			if(i>=j)
			{
				printf("*\t");
			}
		
		}
		printf("\n");
	}
	for(i=2;i<=iRow;i++)
	{
		for(j=1;j<=i;j++)      //optimization of loop
		{
			printf("*\t");
		}
		printf("\n");
	}
}
int main()
{
	int iValue1=0, iValue2=0;
	
	printf("Enter the rows:\n");
	scanf("%d",&iValue1);
	
	printf("Enter the columns: \n");
	scanf("%d",&iValue2);
	
	Display(iValue1,iValue2);
	
	return 0;
}

