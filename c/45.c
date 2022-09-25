//Accept base and power from user and give the result(using typedef)
#include<stdio.h>
typedef unsigned long int ULONG;
ULONG Power(int iNo1,int iNo2)
{
    ULONG lMul=1;
    register int iCnt=0;
    //Registers are faster than memory to access
    for(iCnt=1;iCnt<=iNo2;iCnt++)
    {
        lMul=lMul*iNo1;
    }
    return lMul;
}
int main()
{
    auto int iValue1=0,iValue2=0;
    auto ULONG lRet=0;

    printf("Enter base\n");
    scanf("%d",&iValue1);

    printf("Enter power\n");
    scanf("%d",&iValue2);

    lRet=Power(iValue1,iValue2);
    printf("Result is: %ld\n", lRet); //%ld= long decimal

    return 0;
}