#include<stdio.h>

int judge(char a,char b)
{
    if(a == b)
        return 1;
    if(a == 'C' && b == 'J')
        return 0;
    if(a == 'J' && b == 'B')
        return 0;
    if(a == 'B' && b == 'C')
        return 0;
    return 2;
}
int max(int *count)
{
    int mi=0,i;
    for(i=1;i<3;++i)
        if(count[mi]<count[i])
            mi=i;
    return mi;
}
char switch_char(int i)
{
    if(i==0)
        return 'B';
    if(i==1)
        return 'C';
    return 'J';
}

int main()
{
    int n,i,r,t;
    int count[3],countcjb[6];
    char s1[2],s2[2];
    scanf("%d",&n);
    char c1,c2,ct;
    for(i=0;i<3;++i)
        count[i]=0;
    for(i=0;i<6;i++)
        countcjb[i]=0;
    for(i=0;i<n;++i)
    {
        scanf("%s %s",s1,s2);
        c1=s1[0];
        c2=s2[0];
        r = judge(c1,c2);
        //printf("%c %c %d\n",c1,c2,r);
        count[r]++;
        if(r == 1)
            continue;
        if(r == 0)
        {
            t=0;
            ct=c1;
        }else
        {
            t=3;
            ct=c2;
        }
        switch(ct)
        {
            case 'B':
                countcjb[0+t]++;
                break;
            case 'C':
                countcjb[1+t]++;
                break;
            case 'J':
                countcjb[2+t]++;
                break;
        }
    }
    printf("%d %d %d\n",count[0],count[1],count[2]);
    printf("%d %d %d\n",count[2],count[1],count[0]);
    printf("%c %c",switch_char(max(countcjb)),switch_char(max(countcjb+3)));
    return 0;
}
