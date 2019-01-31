#include<stdio.h>
int main()
{
	int i;
	char num[1001];
	scanf("%s",num);
	int count[10];
	for(i=0;i<10;++i)
		count[i] = 0;
	for(i=0;num[i]!=0;++i)
		count[num[i]-'0']++;
	for(i=0;i<10;++i)
		if(count[i]!=0)
			printf("%d:%d\n",i,count[i]);
 
	return 0;
} 
