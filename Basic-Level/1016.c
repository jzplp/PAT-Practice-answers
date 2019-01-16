#include<stdio.h>

int main()
{
    int da,db;
    long long a,b;
    long long sa=0,sb=0;
    int t;
    scanf("%lld %d %lld %d",&a,&da,&b,&db);

    while(a>0)
    {
        t=a%10;
        if(t == da)
        {
            sa = sa*10;
            sa=sa+da;
        }
        a=a/10;
    }
    while(b>0)
    {
        t=b%10;
        if(t == db)
        {
            sb = sb*10;
            sb = sb+db;
        }
        b=b/10;
    }
    printf("%lld",sa+sb);

    return 0;
}
