#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
using namespace std;
int main()
{
    int N;
    scanf("%d",&N);
    if(N==2)
    {
        printf("0");
        return 0;
    }
    N=N+1;
    int number[N];
    memset(number,1,sizeof(number));
    int i,j;
    vector<int> v;
    for(i=2;i<N;i++)
    {
        if(number[i]==0)
            continue;
        v.push_back(i);
        //printf("%d ",i);
        if((long long)i*i>N)
            continue;
        for(j=i*i;j<N;j+=i)
            number[j]=0;
    }
    for(i=1,j=0;i<v.size();i++)
        if(v[i]-v[i-1] == 2)
            j++;
    printf("%d",j);
    return 0;
}
