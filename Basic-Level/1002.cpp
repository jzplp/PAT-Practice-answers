//使用了栈的后进先出的特性，把所有位倒置。

#include<cstdio>
#include<stack>
using namespace std;

void changeout(int i)
{
    if(i == 0)
        printf("ling");
    if(i == 1)
        printf("yi");
    if(i == 2)
        printf("er");
    if(i == 3)
        printf("san");
    if(i == 4)
        printf("si");
    if(i == 5)
        printf("wu");
    if(i == 6)
        printf("liu");
    if(i == 7)
        printf("qi");
    if(i == 8)
        printf("ba");
    if(i == 9)
        printf("jiu");
}

int main()
{
    stack<int> stc;
    char s[101];
    scanf("%s",s);
    int i, sum = 0;
    for(i = 0;s[i]!=0;i++)
    {
        sum += s[i]-'0';
    }
    while(sum > 0)
    {
        stc.push(sum%10);
        sum = sum/10;
    }
    while(!stc.empty())
    {
        changeout(stc.top());
        stc.pop();
        if(!stc.empty())
            printf(" ");
    }
    return 0;
}
