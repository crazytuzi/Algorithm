#include <stdio.h>
#define INF 0x3f3f3f3f
#define min(a,b) a>b?b:a
int main()
{
	int i,j,n;
	int arr[10001]={0};
	scanf("%d",&n);
	for (i=1;i<=n;++i)
	{
		int curMin=INF;
		// 多组输入的话，可以考略预处理先生成平方
		for (j=1;j*j<=i;++j)
		{
			curMin = min(curMin,arr[i-j*j]+1);
		}
		arr[i]=curMin;
	}
	printf("%d",arr[n]);
	return 0;
}