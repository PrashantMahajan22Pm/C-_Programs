#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define BUFFERSIZE 1024


 int CountCaptil(char FName[])
 {
  int iCout=0;
   int fd = 0;
    int iRet = 0, iCnt = 0;
     char Arr[BUFFERSIZE];
  
  fd = open(FName,O_RDONLY);

    while(1)
    {
        iRet = read(fd,Arr,sizeof(Arr));     // 10
        if(iRet == 0)
        {
            break;
        }
        for(iCnt = 0; iCnt < iRet ;iCnt++)
        {
            if((Arr[iCnt] >= 'a') && (Arr[iCnt] <= 'z'))
            {
                iCout++;
            }
        }
    }

   close(fd);
    
  return iCout;
 }



int main()
{
    char FileName[50];
   int iAns = 0;
   

    printf("Enter the file that you want to open\n");
    scanf("%s",FileName);
   
    
   iAns = CountCaptil(FileName);
    printf("Number of small case letters are : %d\n",iAns);

  
    return 0;
}