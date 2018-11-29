#include<vector>
#include<iostream>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> soc;
    int n;
    int temp;
    cin>>n;
    while(n-->0)
    {
        cin>>temp;
        soc.push_back(temp);
    }
    sort(soc.begin(),soc.end());

    vector<int>::iterator i;
    vector<int>::iterator j;
    for(i = soc.begin();i!=soc.end();i++)
    {
        temp = *i;
        while(temp != 1)
        {
            if(temp%2 == 0)
                temp = temp/2;
            else
                temp = (3*temp+1)/2;
            for(j = soc.begin();j!=soc.end();)
            {
                if(temp == *j)
                {
                    j = soc.erase(j);
                    if(j<i)
                        i--;
                }
                else
                    ++j;
            }
        }
    }
    vector<int>::reverse_iterator ri;
    for(ri = soc.rbegin();ri!=soc.rend()-1;ri++)
        cout<<*ri<<" ";
    cout<<*ri;
    return 0;
}
