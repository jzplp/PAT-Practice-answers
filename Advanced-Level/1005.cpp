/***************************************************************************
 *  @file       1005.cpp
 *  @author     jzplp
 *  @date       10  Feb. 2017
 *  @remark     PAT-Advanced-Level 1005. Spell It Right (20) 
 *  @note       answer
 ***************************************************************************/
#include<cstdio>
char *english[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
char str[100];
char digit[6]="\0";

int main()
{
	int sum=0,tsum;
	int i;
	scanf("%s",str);
	for(i=0;str[i]!=0;i++)
		sum+=str[i]-'0';
	tsum=sum;
	i=0;
	while(tsum>0)
	{
		digit[i]=tsum%10;
		tsum=tsum/10;
		i++;
	}
	while(--i>0)
	{
		printf("%s ",english[digit[i]]);
	}
	printf("%s\n",english[digit[i]]);
	return 0;
}

