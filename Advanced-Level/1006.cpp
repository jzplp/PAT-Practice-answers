/***************************************************************************
 *  @file       1006.cpp
 *  @author     jzplp
 *  @date       12  Feb. 2017
 *  @remark     PAT-Advanced-Level 1006.Sign In and Sign Out(25) 
 *  @note       answer
 ***************************************************************************/
#include<cstdio>
#include<cstring>
using namespace std;
struct person
{
	char ID[16];
	char time[9];
};
int compNum(char c1,char c2)
{
	if(c1>c2)
		return 1;
	if(c1<c2)
		return -1;
	return 0;
}
int comp(person t1,person t2)
{
	int i,c;
	for(i=0;i<9;++i)
	{
		if((c=compNum(t1.time[i],t2.time[i]))!=0)
			return c;
	}
	return 0; 
}
int main()
{
	int M,i;
	char ID[16];
	person unlock,lock;
	person p1,p2;
	scanf("%d",&M);
	for(i=0;i<M;++i)
	{
		scanf("%s",ID);
		strcpy(p1.ID,ID);
		strcpy(p2.ID,ID);
		scanf("%s",p1.time);
		scanf("%s",p2.time);
		if(i==0)
		{
			unlock=p1;
			lock=p2;
		}else
		{
			if(comp(unlock,p1)>0)
				unlock=p1;
			if(comp(lock,p2)<0)
				lock=p2;	
		}
	}
	printf("%s %s\n",unlock.ID,lock.ID);
	return 0;
}
