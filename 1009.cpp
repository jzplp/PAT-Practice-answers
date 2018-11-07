#include<string>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<string > v;
    string t;
    int i;
    while(cin>>t)
        v.push_back(t);
    for(i=v.size()-1;i>0;i--)
        cout<<v[i]<<" ";
    cout<<v[0];
    return 0;
}
