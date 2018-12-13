#include <stdio.h>
#define INF 0x3f3f3f3f
#define min(a,b) a>b?b:a
int main()
{
	int i,n;
	int arr[10001];
	scanf("%d",&n);
	for (i=1;i<=n;++i)
	{
		if (i==1 || i==5 || i==10 || i==20 || i==50 || i== 100)
		{
			arr[i]=1;
			continue;
		}
		int curMin=INF;
		if (i-1>0)
			curMin = min(curMin,arr[i-1]);
		if (i-5>0)
			curMin = min(curMin,arr[i-5]);
		if (i-10>0)
			curMin = min(curMin,arr[i-10]);
		if (i-20>0)
			curMin = min(curMin,arr[i-20]);
		if (i-50>0)
			curMin = min(curMin,arr[i-50]);
		if (i-100>0)
			curMin = min(curMin,arr[i-100]);
		arr[i]=curMin+1;
	}
	printf("%d",arr[n]);
	return 0;
}