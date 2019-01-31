#include<stdio.h>
#include<stdlib.h>
struct yuebing
{
	double total;
	double totalprice;
	double price;
};
int comp(const void * a,const void * b)
{
	struct yuebing * L = (struct yuebing *)a;
	struct yuebing * R = (struct yuebing *)b;
	return L->price < R ->price;
}
int main()
{
	int N,D,i;
	scanf("%d %d",&N,&D);
	
	struct yuebing sum[N];
	
	for(i=0;i<N;i++)
		scanf("%lf",&sum[i].total);
	for(i=0;i<N;i++)
	{
		scanf("%lf",&sum[i].totalprice);
		sum[i].price = sum[i].totalprice/sum[i].total;
	}
	qsort(sum,N,sizeof(struct yuebing),comp);
	//for(i=0;i<N;i++)
	//	printf("%d %d %lf\n",sum[i].total,sum[i].totalprice,sum[i].price);
	
	double toPrice =0;
	for(i=0;i<N;++i)
	{
		if(D == 0)
			break;
		if(D>=sum[i].total)
			{
				D = D-sum[i].total;
				toPrice += sum[i].totalprice;
			}
		else
			{
				toPrice += sum[i].totalprice /(sum[i].total/D); 
				D = 0;
			}
	}
	printf("%0.2lf",toPrice);
	
	return 0;
}
