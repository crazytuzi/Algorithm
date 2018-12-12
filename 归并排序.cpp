#include <stdio.h>
int n,arr[50001],temp[50001];
void Merge(int left,int mid,int right)
{
	int i=left;
	int j=mid+1;
	int k=0;
	while (i<=mid&&j<=right)
	{
		if (arr[i]<=arr[j])
			temp[k++]=arr[i++];
		else
			temp[k++]=arr[j++];
	}
	while (i<=mid)
		temp[k++]=arr[i++];
	while (j<=right)
		temp[k++]=arr[j++];
	k=0;
	while (left<=right)
		arr[left++]=temp[k++];
}
void MergeSort(int left,int right)
{
	if (left<right)
	{
		int mid = (right+left)>>1;
		MergeSort(left,mid);
		MergeSort(mid+1,right);
		Merge(left,mid,right);
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
	MergeSort(0,n-1);
	for (i=0;i<n;++i)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}