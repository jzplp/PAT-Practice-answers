/***************************************************************************
 *  @file       1007.cpp
 *  @author     jzplp
 *  @date       13  Feb. 2017
 *  @remark     PAT-Advanced-Level 1007.Maximum Subsequence Sum(25)
 *  @note       answer
 ***************************************************************************/
#include<cstdio>
int Se[10000];
long sumT[10000]={0};
int main()
{
	int i,j,K;
	int st,sti,stj;
	long sum=-1;
	scanf("%d",&K);
	for(i=0;i<K;++i)
		scanf("%d",&Se[i]);
	for(i=0;i<K;++i)
	{
		if(i==0)
			sumT[0]=Se[0];
		else
			sumT[i]=sumT[i-1]+Se[i];
	}
	for(i=0;i<K;++i)
		for(j=i;j<K;++j)
		{
			if(i==0)
			{
			
				if(sum<sumT[j])
				{
					sum=sumT[j];
					sti=0;
					stj=j;
				}
			}
			else
			{
				if(sum<sumT[j]-sumT[i-1])
				{
					sum=sumT[j]-sumT[i-1];
					sti=i;
					stj=j;
				}
			}
		}
	if(sum<0)
		printf("%d %d %d\n",0,Se[0],Se[K-1]);
	else
		printf("%ld %d %d\n",sum,Se[sti],Se[stj]);
	return 0;
}
