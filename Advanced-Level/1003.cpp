/***************************************************************************
 *  @file       1003.cpp
 *  @author     jzplp
 *  @date       18  Feb. 2017
 *  @remark     PAT-Advanced-Level 1003.Emergency(25)
 *  @note       answer
 ***************************************************************************/
#include<cstdio>
#define MAXN 100000
//#define QWERTY 
int main()
{
	int N,M,C1,C2;
	scanf("%d%d%d%d",&N,&M,&C1,&C2);
	int SaveMen[N];
	int arcs[N][N];
	int Num[N];
	int Team[N];
	int i,i1,i2,d;
	for(i1=0;i1<N;++i1)
	{
		for(i2=0;i2<N;i2++)
		{
			arcs[i1][i2]=MAXN;
			if(i1==i2)
				arcs[i1][i2]=0;
		}
	}
	for(i=0;i<N;++i)
		scanf("%d",&SaveMen[i]);
	for(i=0;i<M;++i)
	{
		scanf("%d%d%d",&i1,&i2,&d);
		arcs[i1][i2]=d;
		arcs[i2][i1]=d;
	}
	
	bool S[N];
	int dist[N],path[N];
	for(i=0;i<N;++i)
	{
		S[i]=false;
		dist[i]=arcs[C1][i];
		//path[i]=C1;
		if(i==C1)
		{
			Num[C1]=1;
			Team[C1]=SaveMen[C1];
		}else
		{
			Num[i]=0;
			Team[i]=0;
		}
	}
	
	int c=-1;
	while(c!=C2)
	{
		d=MAXN;
		for(i=0;i<N;++i)
		{
			if(S[i]==true)
				continue;
			if(dist[i]<d)
			{
				i1=i;
				d=dist[i];
			}
		}
		S[i1]=true;
		c=i1;
#ifdef QWERTY
		printf("@@@@@@@ begin \n");
		for(i=0;i<N;++i)
		{	
			printf("%d ",dist[i]);
		}
		putchar('\n');
		for(i=0;i<N;++i)
		{	
			printf("%d ",Team[i]);
		}
		putchar('\n');
		printf("@@@@@@@ end \n");
#endif
		for(i=0;i<N;++i)
		{
			if(S[i]==true)
				continue;
			if(dist[i]>dist[c]+arcs[c][i])
			{
				dist[i]=dist[c]+arcs[c][i];
				//path[i]=c;
				Team[i]=SaveMen[i]+Team[c];
				Num[i]=Num[c];
			}else if(dist[i]==dist[c]+arcs[c][i])
			{
				Num[i]=Num[i]+Num[c];
				if(Team[i]<Team[c]+SaveMen[i])
					Team[i]=Team[c]+SaveMen[i];
			}
		}
	}
	int sum=0;
	//while(c!=C1)
	//{
		//printf("%d ",c);
	//	sum+=SaveMen[c];
	//	c=path[c];
	//}
	//sum+=SaveMen[C1];
	printf("%d %d",Num[C2],Team[C2]);
	return 0;
}
