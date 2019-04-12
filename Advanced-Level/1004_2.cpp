#include<iostream>
#include<vector>
using namespace std;

struct node
{
	int id;
	int level;
	vector<int> v;
	int father;
};

 
int main()
{
	int N,M,i,j;
	cin>>N>>M;
	if(N==0)
		return 0;
	vector<node> list;
	node ni;
	for(i=0;i<N;++i)
	{
		ni.id = i+1;
		ni.level = 0;
		list.push_back(ni);
	}
	list[0].level  = 1;
	int id,k,idi;
	for(i=0;i<M;i++)
	{
		cin>>id>>k;
		for(j=0;j<k;++j)
		{
			cin>>idi;
			list[id-1].v.push_back(idi);
			if(list[id-1].level != 0)
				list[idi-1].level = list[id-1].level+1;
			else
			{
				list[idi-1].father = id;
			}
		}
	}
	
	bool fix;
	while(1)
	{
		fix = false;
		for(i=0;i<N;++i)
		{
			if(list[i].level == 0)
			{
				fix = true;
				if(list[list[i].father - 1 ].level != 0)
				{
					list[i].level = list[list[i].father - 1 ].level+1;
				}
			}
		}
		if(fix == false)
			break;
	}
	
	int MAX_level = 0;
	for(i=0;i<N;++i)
	{
		if(list[i].level > MAX_level)
			MAX_level = list[i].level;
	}
	int level_leaves[MAX_level];
	for(i=0;i<MAX_level;++i)
		level_leaves[i] = 0;
	
	for(i=0;i<N;i++)
	{
		if(list[i].v.empty())
			level_leaves[list[i].level-1] ++;
	}
	for(i=0;i<MAX_level;i++)
	{
		cout<<level_leaves[i];
		if(i!= MAX_level-1)
			cout<<" ";
	}
	return 0;
} 
