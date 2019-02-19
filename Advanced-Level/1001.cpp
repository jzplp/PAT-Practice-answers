#include<stdio.h>
int main()
{
	int a, b;
	scanf("%d %d",&a,&b);
	int sum = a+b;
	if(sum == 0)
	{
		printf("0");
		return 0;
	}
	if(sum<0)
	{
		printf("-");
		sum = -sum;
	}
	int arr[10] ={0};
	int i;
	a =sum;
	b = 0;
	for(i=0;a>0;i++)
	{
		b = a%10;
		a = a/10;
		arr[i]=b;
	}
	for(i=i-1;i>=0;i--)
	{		
		printf("%d",arr[i]);
		if((i)%3 == 0 && i>0 )
		{
			printf(",");
		}
	}
	
	return 0;
 } 
