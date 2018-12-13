#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
#define max(a,b) a>b?a:b
int main()
{
	int i,j,n;
	int arr[101];
	int res=0;
	int dp[101];
	memset(dp,0,sizeof(0));
	scanf("%d",&n);
	for (i=0;i<n;++i)
	{
		scanf("%d",&arr[i]);
	}
	for (i=0;i<n;i++)
	{
		dp[i]=1;
	}
	for (i=0;i<n;++i)
	{
		for(j=i+1;j<n;++j)
		{
			if (arr[j]>arr[i])
			{
				dp[j]=max(dp[j],dp[i]+1);
			}
		}
		res = max(dp[i],res);
	}
	printf("%d\n",res);
	return 0;
}
/*
5
1 3 2 4 0
*/
/*
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
*/