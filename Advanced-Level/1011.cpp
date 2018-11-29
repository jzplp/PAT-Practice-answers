/***************************************************************************
 *  @file       1011.cpp
 *  @author     jzplp
 *  @date       24  Feb. 2017
 *  @remark     PAT-Advanced-Level 1011. World Cup Betting (20)
 *  @note       answer
 ***************************************************************************/
#include<cstdio>
double bet[3][3];
int main()
{
	int i1,i2;
	for(i1=0;i1<3;++i1)
		for(i2=0;i2<3;++i2)
			scanf("%lf",&bet[i1][i2]);
	char C[3]={'W','T','L'};
	int maxi[3]={0,0,0};
	double sum=0.65*2;
	for(i1=0;i1<3;++i1)
		for(i2=0;i2<3;++i2)
		{
			if(bet[i1][i2]>bet[i1][maxi[i1]])
				maxi[i1]=i2;
		}
	for(i1=0;i1<3;++i1)
	{
		printf("%c ",C[maxi[i1]]);
		sum=sum*bet[i1][maxi[i1]];
	}
	sum-=2;
	printf("%.2lf\n",sum);
	return 0;
}
