/***************************************************************************
 *  @file       1009.cpp
 *  @author     jzplp
 *  @date       20  Feb. 2017
 *  @remark     PAT-Advanced-Level 1009.Product of Polynomials(25)
 *  @note       answer
 ***************************************************************************/
#include<cstdio>
struct poly
{
	int k;
	int exp[10];
	double coe[10];
};
struct polyPro
{
	int k;
	int exp[100];
	double coe[100];
};
void inputPoly(poly &p)
{
	int i;
	scanf("%d",&(p.k));
	for(i=0;i<p.k;++i)
	{
		scanf("%d",&(p.exp[i]));
		scanf("%lf",&(p.coe[i])); 
	}
}
void outputPro(polyPro &p)
{
	int i;
	printf("%d",p.k);
	for(i=0;i<p.k;++i)
	{
		if(p.coe[i]>-0.05 && p.coe[i]<0.05)
			continue;
		printf(" %d %.1lf",p.exp[i],p.coe[i]);
	}
}
void output(poly &p)
{//test function
	int i;
	printf("%d ",p.k);
	for(i=0;i<p.k-1;++i)
		printf("%d %.1lf ",p.exp[i],p.coe[i]);
	printf("%d %.1lf\n",p.exp[i],p.coe[i]);
}
void exchange(polyPro &p,int i,int j)
{
	int ti;
	double td;
	ti=p.exp[i];
	p.exp[i]=p.exp[j];
	p.exp[j]=ti;
	td=p.coe[i];
	p.coe[i]=p.coe[j];
	p.coe[j]=td;
}
polyPro calPoly(poly &a,poly &b)
{
	polyPro p;
	int i1,i2,i3,i=0;
	int expT;
	double coeT;
	for(i1=0;i1<a.k;++i1)
		for(i2=0;i2<b.k;++i2)
		{
			expT=a.exp[i1]+b.exp[i2];
			coeT=a.coe[i1]*b.coe[i2];
			for(i3=0;i3<i;++i3)
			{
				if(expT==p.exp[i3])
				{
					p.coe[i3]+=coeT;
					coeT=0;
				}
			}
			if(coeT!=0)
			{
				p.exp[i]=expT;
				p.coe[i]=coeT;
				i++;
			}
		}
	p.k=i;
	
	for(i1=0,i2=0;i1<p.k;i1++)
	{
		if(p.coe[i1]>-0.05 && p.coe[i1]<0.05)
			i--;
		else
		{
			p.coe[i2]=p.coe[i1];
			p.exp[i2]=p.exp[i1];
			i2++;
		}
	}
	p.k=i2;
	int iMax;
	for(i1=0;i1<p.k-1;++i1)
	{
		iMax=i1; 
		for(i2=i1+1;i2<p.k;++i2)
		{
			if(p.exp[iMax]<p.exp[i2])
				iMax=i2;
		}
		if(iMax!=i1)
			exchange(p,iMax,i1);
	}
	return p;
}
int main()
{
	poly p1,p2;
	inputPoly(p1);
	inputPoly(p2);
	//output(p1); output(p2); 
	polyPro p=calPoly(p1,p2);
	//printf("@@@@@@@@@@@@\n");
	outputPro(p); 
	return 0;
}
