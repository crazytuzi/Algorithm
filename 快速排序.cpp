#include<stdio.h>
int arr[50001];
int division(int left,int right)
{
	int base = arr[left];
	while (left<right)
	{
		while(left<right && arr[right]>=base)
			right--;
		arr[left] = arr[right];
		while (left<right && arr[left]<=base)
			left++;
		arr[right]=arr[left];
	}
	arr[left]=base;
	return left;
}
void quicksort(int left,int right)
{
	if (left<right)
	{
		int base = division(left,right);
		quicksort(left,base-1);
		quicksort(base+1,right);
	}
}
int main()
{
	int i,n;
	scanf("%d",&n);
	for (i=0;i<n;++i)
	{
		scanf("%d",&arr[i]);
	}
	quicksort(0,n-1);
	for (i=0;i<n;++i)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}