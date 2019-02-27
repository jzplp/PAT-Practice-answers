#include<vector>
#include<stdio.h>
using namespace std;
struct stu
{
	int exponent;
	float coefficient;
};
int main()
{
	vector<stu> A;
	vector<stu> B;
	vector<stu> C;
	vector<stu> D;
	int ka,kb,i;
	stu stemp;
	scanf("%d",&ka);
	for(i = 0;i<ka;i++)
	{
		scanf("%d %f",&stemp.exponent,&stemp.coefficient);
		A.push_back(stemp);
	}
	scanf("%d",&kb);
	for(i = 0;i<kb;i++)
	{
		scanf("%d %f",&stemp.exponent,&stemp.coefficient);
		B.push_back(stemp);
	}
	ka = ka-1;
	kb = kb-1;
	while(ka>=0 && kb>=0)
	{
		if(A[ka].exponent==B[kb].exponent)
		{
			A[ka].coefficient+=B[kb].coefficient;
			C.push_back(A[ka]);
			ka--;
			kb--;
			continue;
		}
		if(A[ka].exponent>B[kb].exponent)
		{
			C.push_back(B[kb]); 
			kb--;
			continue;
		}
		if(A[ka].exponent<B[kb].exponent)
		{
			C.push_back(A[ka]); 
			ka--;
			continue;
		}
	}
	while(ka>=0)
	{
		C.push_back(A[ka]); 
		ka--;
	}
	while(kb>=0)
	{
		C.push_back(B[kb]); 
		kb--;
	}
	for(i=0;i<C.size();i++)
	{
		if(C[i].coefficient <0.1 && C[i].coefficient > -0.1)
			continue;
		D.push_back(C[i]);
	}
	printf("%d",D.size());
	if(D.size()==0)
		return 0;
	printf(" ");
	for(i=D.size()-1;i>=0;i--)
	{
		printf("%d %.1f",D[i].exponent,D[i].coefficient);
		if(i!=0)
			printf(" ");
	}
	return 0;
}

