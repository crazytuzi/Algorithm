#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
#define max(a,b) a>b?a:b
#define min(a,b) a>b?b:a
int main()
{
	int i,j,n;
	int dp[101];
	scanf("%d",&n);
	dp[0]=dp[1]=1;
	for (i=2;i<=n;++i)
	{
		dp[i]=i;
		for (j=1;j<i;++j)
		{
			int tmp=max(j,dp[i-j]+1);
			dp[i]=min(tmp,dp[i]);
		}
	}
	printf("%d\n",dp[n]);
	return 0;
}
