#include <stdio.h>
#define max(a,b) a>b?a:b
int main()
{
	int i,j,m,n;
	int w[100];//重量
	int v[100];//价值
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
	for (i=0;i<n;++i)
	{
		for (j=0;j<=m;++j)
		{
			if (j<w[i])
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
		}
	}
	printf("%d",dp[n-1][m]);
	return 0;
}
/*
12 6 
0 1 3 2 6 2
0 2 5 3 10 4
*/