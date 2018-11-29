/***************************************************************************
 *  @file       1010.cpp
 *  @author     jzplp
 *  @date       23  Feb. 2017
 *  @remark     PAT-Advanced-Level 1010.Radix(25)
 *  @note       answer
 ***************************************************************************/
#include<cstdio>
char N1[11]="\0",N2[11]="\0";
long long calValue(char N[],long long radix);
int minradix(char N[]);
long long judge(long long n1,char N[],int minrad);
int main()
{
	long long n1,n2;
	long long tag,radix1,radix2,minrad;
	long long out;
	scanf("%s",N1);
	scanf("%s",N2);
	scanf("%lld",&tag);
	if(tag==1)
	{
		scanf("%lld",&radix1);
		n1=calValue(N1,radix1);
		if(n1<0)
			out=0;
		else 
			minrad=minradix(N2);
		out=judge(n1,N2,minrad);
	}else
	{
		scanf("%lld",&radix2);
		n2=calValue(N2,radix2);
		if(n2<0)
			out=0;
		else 
			minrad=minradix(N1);
		out=judge(n2,N1,minrad);
	}
	if(out==0)
		printf("Impossible\n");
	else
		printf("%lld\n",out);
	return 0; 
}
long long calValue(char N[],long long radix)
{
	long long sum=0;
	long long i=0;
	while(N[i]!='\0')
	{
		if(N[i]>='0'&& N[i]<='9')
			sum=sum*radix+(N[i]-'0');
		else
			sum=sum*radix+(N[i]-'a'+10);
		if(sum<0)
			return -1;
		i++;
	}
	return sum;
}
int minradix(char N[])
{
	int i,Max=0;
	for(i=0;N[i]!=0;i++)
		if(N[i]>Max)
			Max=N[i];
	if(Max>='0'&& Max<='9')
		return Max-'0';
	else
		return Max-'a'+10; 
}
long long judge(long long n1,char N[],int minrad)
{
	unsigned long long n2;
	unsigned long long beg=minrad+1,end=n1;
	if(beg>end)
		end=beg;
	unsigned long long mid=(beg+end)/2;
	while(mid>=beg && mid<=end)
	{
		n2=calValue(N,mid);
		if(n2<0)
			return 0;
		if(n2==0 && n2==n1)
			return 1;
		if(n1==n2)
			return mid;
		if(n2>n1)
			end=mid-1;
		else
			beg=mid+1;
		mid=(beg+end)/2;
	}
	return 0;
}
