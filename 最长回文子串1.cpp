#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
#define max(a,b) a>b?a:b
int main()
{
	int i,j;
	int res=0;
	char str[101];
	int dp[101][101];
	memset(dp,0,sizeof(dp));
	scanf("%s",str);
	for (i=0;i<strlen(str);++i)
	{
		for (j=0;j<strlen(str);++j)
		{
			if ( i == j )
				dp[i][j] = 1;
			else
				dp[i][j] = 0;
		}
	}
	for (j=0;j<strlen(str);++j)
	{
		for (i=j-1;i>=0;--i)
		{
			if (str[i] == str[j])
			{
				if (j-i==1)
				{
					dp[i][j]=2;
				}else{
					if (dp[i+1][j-1]>0)
					{
						dp[i][j]=dp[i+1][j-1]+2;
					}
					else
					{
						dp[i][j]=0;
					}
				}
			}else
			{
				dp[i][j]=0;
			}
			res = max(res,dp[i][j]);
		}
	}
	printf("%d\n",res);
	return 0;
}