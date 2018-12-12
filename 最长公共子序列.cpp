#include <stdio.h>
#include <string.h>
#define max(a,b) a>b?a:b
int main()
{
	int i,j;
	char str1[100];
	char str2[100];
	int dp[100][100];
	scanf("%s%s",str1,str2);
	for (i=0;i<=strlen(str1);++i)
	{
		for (j=0;j<=strlen(str2);++j)
		{
			if (i==0||j==0)
			{
				dp[i][j]=0;
			}else if (str1[i-1]==str2[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	printf("%d",dp[strlen(str1)][strlen(str2)]);
	return 0;
}
//cnblogs belong