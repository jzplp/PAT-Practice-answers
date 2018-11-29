/***************************************************************************
 *  @file       1001.cpp
 *  @author     jzplp
 *  @date       13  Jan. 2017
 *  @remark     PAT-Advanced-Level 1001. A+B Format (20) 
 *  @note       answer
 ***************************************************************************/
#include<cstdio>  
#include<queue>  
#include<stack>  
#define QWERTY  
using namespace std;  
int main()  
{  
    long a,b,sum;  
    scanf("%ld%ld",&a,&b);  
    sum=a+b;  
    long st=sum;  
    int i=0,c1,c2;  
      
    if(st<1000&&st>-1000)  
    {  
        printf("%ld\n",st);  
        return 0;  
    }  
    if(st<0)  
    {  
        printf("-");  
        st=-st;  
    }  
    stack<int> sta;  
    while(st>0)  
    {  
        i++;  
        sta.push(st%10);  
        st=st/10;  
    }  
#ifdef QWERTY  
    while(!sta.empty())  
    {  
        i--;  
        printf("%d",sta.top());  
        if(i!=0&&i%3==0)  
            printf(",");  
        sta.pop();  
  
    }  
#endif  
    printf("\n");  
    return 0;  
}  



