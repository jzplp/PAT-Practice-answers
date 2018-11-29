#include<stdio.h>

int main()
{
    int n;
    char s[101];
    scanf("%d\n",&n);
    int l,m,r,i,p,t,ii;
    bool flag;
    for(ii=0;ii<n;ii++)
    {
        l=0,m=0,r=0,p=0,t=0;
        flag=true;
        scanf("%s",s);
        //fgets(s,101,stdin);
        for(i=0;s[i]!='\n'&&s[i]!=0;i++)
        {
           if(s[i]=='P')
           {
               p++;
               if(p>1)
               {
                   flag=false;
                   break;
               }
           }else if(s[i]=='T')
           {
               t++;
               if(t>1||p<1)
               {
                   //p<1代表T出现时并未出现P
                   flag=false;
                   break;
               }
           }else if(s[i]=='A')
           {
               if(p>0&&t>0)
                r++;
               else if(p>0)
                m++;
               else
                l++;
           }else
           {
               flag=false;
               break;
           }
        }
        //p或者t为0说明P和T未出现
        if(l*m!=r||m==0||p==0||t==0)
            flag=false;
        if(flag==false)
            printf("NO");
        else
            printf("YES");
        if(ii!=n-1)
        printf("\n");
    }
    return 0;
}
