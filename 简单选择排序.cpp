#include<stdio.h>
int main()
{
	int i,j,n;
	int arr[50001];
	scanf("%d",&n);
	for (i=0;i<n;++i)
	{
		scanf("%d",&arr[i]);
	}
	for (i=0;i<n-1;++i)
	{
		int index = i;
		for (j=i+1;j<n;++j)
		{
			if (arr[j]<arr[index])
				index = j;
		}
		int temp = arr[index];
		arr[index] = arr[i];
		arr[i] = temp;
	}
	for (i=0;i<n;++i)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}