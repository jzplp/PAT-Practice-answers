/***************************************************************************
 *  @file       1002.cpp
 *  @author     jzplp
 *  @date       15  Jan. 2017
 *  @remark     PAT-Advanced-Level 1002. A+B for Polynomials (25) 
 *  @note       answer
 ***************************************************************************/
#include<cstdio>
#include<map>
using namespace::std;
map<int,double> s;
int main()
{
	int i1,t1;
	double t2;
	for(int z=0;z<2;z++)
	{
		scanf("%d",&i1);
		for(int i=0;i<i1;i++)
		{
			scanf("%d%lf",&t1,&t2);
			if(s.count(t1)==0)
				s[t1]=t2;
			else
				s[t1]+=t2;
		}
	}
	i1=0;
	for(map<int,double>::const_iterator m_it=s.begin();m_it!=s.end();m_it++)
	{
		if(m_it->second!=0.0&&m_it->second!=-0.0)
			i1++;
	}
	printf("%d",i1);
	for(map<int,double>::reverse_iterator m_it=s.rbegin();m_it!=s.rend();m_it++)
	{
		if(m_it->second!=0.0&&m_it->second!=-0.0)
			printf(" %d %.1lf",m_it->first,m_it->second);
	}
	printf("\n");
	return 0;
}

