#include <stdio.h>
int n,arr[50001],bucket[50001],count[10];
int MaxBit()
{
	int max_data = arr[0];
	for (int i=1;i<n;++i)
	{
		if(arr[i]>max_data)
			max_data = arr[i];
	}
	int bits_num = 0;
	while (max_data)
	{
		bits_num++;
		max_data/=10;
	}
	return bits_num;
}
int digit(int num,int d)
{
	int pow = 1;
	while (--d>0)
	{
		pow*=10;
	}
	return num/pow%10;
}
void RadixSort()
{
	int i;
	for (int d = 1;d<=MaxBit();++d)
	{
		for (i=0;i<10;++i)
		{
			count[i]=0;
		}
		for (i=0;i<n;++i)
		{
			count[digit(arr[i],d)]++;
		}
		for (i=1;i<10;++i)
		{
			count[i]+=count[i-1];
		}
		for (i=n-1;i>=0;--i)
		{
			int k = digit(arr[i],d);
			bucket[count[k]-1] = arr[i];
			count[k]--;
		}
		for (i=0;i<n;++i)
		{
			arr[i]=bucket[i];
		}
	}
}
int main()
{
	int i;
	scanf("%d",&n);
	for (i=0;i<n;++i)
	{
		scanf("%d",&arr[i]);
	}
	RadixSort();
	for (i=0;i<n;++i)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
