#include <stdio.h>
#define max(a,b) a>b?a:b
int maxValue=0;
int m,n;
int w[100];//重量
int v[100];//价值
int bag(int step,int weight)
{
	int res;
	if (step == n){
		res=0;
	}else if (weight<w[step]){
		res=bag(step+1,weight);
	}else{
		res = max(bag(step+1,weight),bag(step+1,weight-w[step])+v[step]);
	}
	return res;
}
int main()
{
	int i,j;
	
	int dp[100][100]={{0}};
	scanf("%d%d",&m,&n);//重量，物品数量
	for (i=0;i<n;++i)
	{
		scanf("%d",&w[i]);
	}
	for (i=0;i<n;++i)
	{
		scanf("%d",&v[i]);
	}
	
	printf("%d",bag(0,m));
	return 0;
}
/*
12 6 
0 1 3 2 6 2
0 2 5 3 10 4
*/