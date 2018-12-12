#include <stdio.h>
#include <string.h>
#define max(a,b) a>b?a:b
char str1[100];
char str2[100];
int dp[100][100],vec[100][100];
void path(int i,int j)
{
	if (i==0 || j==0)
	{
		return;
	}
	if (vec[i][j] == 0)
	{
		path(i-1,j-1);
		printf("%c",str1[i-1]);
	}
	else if (vec[i][j] == 1)
	{
		path(i-1,j);
	}
	else
	{
		path(i,j-1);
	}
}
int main()
{
	int i,j;
	
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
				vec[i][j]=0;
			}else if (dp[i-1][j]>=dp[i][j-1])
			{
				dp[i][j]=dp[i-1][j];
				vec[i][j]=1;
			}else
			{
				dp[i][j]=dp[i][j-1];
				vec[i][j]=2;
			}
		}
	}
	printf("%d\n",dp[strlen(str1)][strlen(str2)]);
	path(strlen(str1),strlen(str2));
	return 0;
}
//cnblogs belong