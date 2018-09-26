#include<stdio.h>
#include<string.h>
int main()
{
    char str[4];
    char tar[31];
    scanf("%s",str);
    int len = strlen(str);
    int i,j=0,tempi;
    for(i=0;str[len-i-1]!=0;i++)
    {
        if(i==0)
           for(tempi=str[len-i-1];tempi>'0';tempi--)
           {
               tar[j++]=tempi;
           }
        if(i==1)
            for(tempi=str[len-i-1];tempi>'0';tempi--)
           {
               tar[j++]='S';
           }
        if(i==2)
            for(tempi=str[len-i-1];tempi>'0';tempi--)
           {
               tar[j++]='B';
           }
    }
    tar[j]=0;

    for(i=0;i<j/2;i++)
    {
        str[0]=tar[i];
        tar[i]=tar[j-1-i];
        tar[j-1-i]=str[0];
    }
    printf("%s",tar);
    return 0;
}
