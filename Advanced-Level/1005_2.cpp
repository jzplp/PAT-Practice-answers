#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string s;
	int i, sum = 0;
	vector<int> v;
	const char *num[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
	cin >> s;
	for(i = 0;i < s.size();++i)
		sum += s[i]-'0';
	if(sum == 0)
	{ 
		cout << num[0];
		return 0;
	}
	while(sum>0)
	{
		v.push_back(sum%10);
		sum = sum/10;
	}
	for(i = v.size()-1;i > 0;i--)
		cout<<num[v[i]]<<" ";
	cout<<num[v[0]];
	return 0;
} 
