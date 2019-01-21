#include<stdio.h>
#include<stdlib.h>
void convertA(int N,int n[])
{
    int i;
    for(i=0;i<4;i++)
    {
        n[i] = N%10;
        N=N/10;
    }
}
int compareA(const void * a1,const void * a2)
{
    return *(int *)a2-*(int *)a1;
}
int compareB(const void * a1,const void * a2)
{
    return *(int *)a1-*(int *)a2;
}
int convertB(int n[])
{
    int i,N=0;
    for(i=0;i<4;i++)
    {
        N = N*10;
        N += n[i];
    }
    return N;
}
int main()
{
    int N,N1,cha=0;
    int n1[4];
    scanf("%d",&N);
    convertA(N,n1);
    qsort(n1,4,sizeof(int),compareA);
    N1 = convertB(n1);
    qsort(n1,4,sizeof(int),compareB);
    N = convertB(n1);
    if(N == N1)
    {
        printf("%04d - %04d = 0000",N,N);
        return 0;
    }
    while(cha != 6174)
    {
        cha = N1 - N;
        printf("%04d - %04d = %04d\n",N1,N,cha);
        convertA(cha,n1);
        qsort(n1,4,sizeof(int),compareA);
        N1 = convertB(n1);
        qsort(n1,4,sizeof(int),compareB);
        N = convertB(n1);
    }

    return 0;
}

