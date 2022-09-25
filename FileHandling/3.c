//count number of small character from file
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

#define FILESIZE 1024

int CountSmall(char Fname[])
{
    char Data[FILESIZE];     // Mug
    int fd = 0;     // File descriptor(it's like handle)
    int iRet = 0,i=0, iCnt=0;
    fd = open(Fname,O_RDWR);
    if(fd == -1)
    {
        printf("Unable to open the file\n");
        return -1;  // Failure
    }

    while((iRet = read(fd,Data,sizeof(Data))) != 0)
    {
        for(i=0;i<iRet;i++)
        {
            if(Data[i]>='a' && Data[i]<='z')
            {
                iCnt++;
            }
        }
    }

    close(fd);
    return iCnt;
}

int main()
{
    char Fname[20];
    int iRet=0;
    printf("Enter file name to open\n");
    scanf("%s",Fname);

    iRet=CountSmall(Fname);
    printf("Length of Small character is : %d\n", iRet);

    return 0;
}
