#include<stdio.h>
int main()
{
    int t,i;
    scanf("%d",&t);
    long long a,b,c;
    for(i=0;i<t;i++)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        printf("Case #%d: ",i+1);
        if(a+b>c)
            printf("true");
        else
            printf("false");
        if(i!=t-1)
            putchar('\n');
    }
    return 0;
}
