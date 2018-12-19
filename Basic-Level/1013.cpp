#include<iostream>
#include<vector>
using namespace std;

int main()
{
    const int N=110000;
    int m,n;
    cin>>m>>n;
    vector<int> v;
    int num[N];
    int i,j;

    if(n==0)
        return 0;
    if(m==0)
        m=1;

    for(i=2;i<N;i++)
        num[i]=1;
    for(i=2;i<N;++i)
    {
        if(num[i] == 0)
            continue;
        v.push_back(i);
        if((long long)i*i >= N)
            continue;
        for(j=i*i;j<N;j+=i)
            num[j] = 0;
    }
    for(i=0;i<=n-m;i++)
    {
        cout<<v[i+m-1];
        if(i == n-m)
            continue;
        if((i+1)%10 == 0)
            cout<<'\n';
        else
            cout<<' ';
    }
    return 0;
}
