#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct stu
{
    int num;
    int de;
    int cai;
};

bool operator<(const stu &s1,const stu &s2)
{
    int zong1 = s1.de+s1.cai;
    int zong2 = s2.de+s2.cai;
    if( zong1!= zong2)
        return zong1>zong2;
    if(s1.de!=s2.de)
        return s1.de>s2.de;
    return s1.num<s2.num;
}
int main()
{
    int N,L,H;
    cin>>N>>L>>H;
    vector<stu> v;

    int i;

    for(i=0;i<N;++i)
    {
        stu s;
        cin>>s.num>>s.de>>s.cai;
        if(s.de<L || s.cai<L)
            continue;
        v.push_back(s);
    }
    vector<stu> v1;
    vector<stu> v2;
    vector<stu> v3;
    vector<stu> v4;
    for(i=0;i<v.size();++i)
    {
        if(v[i].de>=H && v[i].cai>=H)
        {
            v1.push_back(v[i]);
            continue;
        }
        if(v[i].de>=H)
        {
            v2.push_back(v[i]);
            continue;
        }
        if(v[i].de>= v[i].cai)
        {
            v3.push_back(v[i]);
            continue;
        }
        v4.push_back(v[i]);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    sort(v3.begin(),v3.end());
    sort(v4.begin(),v4.end());
    cout<<v.size()<<endl;

    for(i=0;i<v1.size();++i)
        cout<<v1[i].num<<" "<<v1[i].de<<" "<<v1[i].cai<<endl;
    for(i=0;i<v2.size();++i)
        cout<<v2[i].num<<" "<<v2[i].de<<" "<<v2[i].cai<<endl;
    for(i=0;i<v3.size();++i)
        cout<<v3[i].num<<" "<<v3[i].de<<" "<<v3[i].cai<<endl;
    for(i=0;i<v4.size();++i)
        cout<<v4[i].num<<" "<<v4[i].de<<" "<<v4[i].cai<<endl;
    return 0;
}
