//Pattern A-4
//# 1 * # 2 * # 3 * # 4 * 
#include<stdio.h>
void Pattern(int iNo)
{
    int iCnt=0;
    for(iCnt=1;iCnt<=iNo;iCnt++)
    {
        printf("#   %d  *   ",iCnt);
    }
}
int main()
{
    int iValue=0;

    printf("Enter number of elements: ");
    scanf("%d",&iValue);

    Pattern(iValue);
    return 0;
}