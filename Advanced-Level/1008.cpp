/***************************************************************************
 *  @file       1008.cpp
 *  @author     jzplp
 *  @date       14  Feb. 2017
 *  @remark     PAT-Advanced-Level 1008.Elevator(20)
 *  @note       answer
 ***************************************************************************/
#include<cstdio>
int main()
{
	int stay=0,t;
	int N,i,total=0;
	scanf("%d",&N);
	for(i=0;i<N;++i)
	{
		scanf("%d",&t);
		if(t==stay)
		{
			total+=5;
			continue;
			
		}
		if(t>stay)
			total+=(t-stay)*6+5;
		else
			total+=(stay-t)*4+5;
		stay=t;
	}
	printf("%d",total);
	return 0;
} 
