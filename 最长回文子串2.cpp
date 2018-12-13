#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
#define max(a,b) a>b?a:b
int main()
{
	int i,j,k;
	int res=0;
	char str[101];
	int dp[101][101];
	memset(dp,0,sizeof(dp));
	scanf("%s",str);
	for (i=0;i<strlen(str);++i)
	{
		dp[i][i]=1;
		if (str[i]==str[i+1])
		{
			dp[i][i+1]=1;
			res=2;
		}
	}
	for (k=3;k<=strlen(str);++k)//子串的长度
	{
		for (i=0;i+k-1<strlen(str);++i)//子串左端点 
		{
			j=i+k-1;//子串右端点
			if (str[i]==str[j]&&dp[i+1][j-1])
			{
				dp[i][j]=1;
				res=k;
			}
		}
	}
	printf("%d\n",res);
	return 0;
}