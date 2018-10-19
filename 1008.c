#include<stdio.h>
void revesal(int *num, int beg, int len)
{
    int i,temp;
    for(i=0;i<len/2;i++)
    {
        temp = num[i+beg];
        num[i+beg] = num[beg+len-1-i];
        num[beg+len-1-i] = temp;
    }
}

int main()
{
    int n,m,i;
    scanf("%d %d",&n,&m);
    m = m%n;

    int num[n];
    for(i=0;i<n;i++)
        scanf("%d",&num[i]);

    if(n == 1)
    {
        printf("%d",num[0]);
        return 0;
    }

    revesal(num,0,n);
    revesal(num,0,m);
    revesal(num,m,n-m);

    for(i=0;i<n-1;i++)
    {
        printf("%d ",num[i]);
    }
    printf("%d",num[i]);

    return 0;
}
