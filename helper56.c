#include"header56.h"

 ULONG Power(int iNo1,int iNo2)
{
	ULONG iMult=1;
	register int iCnt=0;
	
	for(iCnt=1;iCnt<=iNo2;iCnt++)
	{
		iMult = iMult * iNo1;
	}
	return iMult;
}
