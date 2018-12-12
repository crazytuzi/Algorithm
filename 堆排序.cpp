#include <stdio.h>
int n,arr[50001];
void HeadAdjust(int parent,int length)
{
	int temp = arr[parent];
	int child = 2*parent+1;
	while(child<length)
	{
		if (child+1<length&&arr[child]<arr[child+1])
			child++;
		if (temp>=arr[child])
			break;
		arr[parent] = arr[child];
		parent = child;
		child = 2*parent+1;
	}
	arr[parent] = temp;
}
void HeadSort()
{
	int i;
	for (i=n/2-1;i>=0;--i)
	{
		HeadAdjust(i,n);
	}
	for (i=n-1;i>0;--i)
	{
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		HeadAdjust(0,i);
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
	HeadSort();
	for (i=0;i<n;++i)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}