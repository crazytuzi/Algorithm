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
	for (i=1;i<n;++i)
	{
		j = i-1;
		int temp = arr[i];
		while (temp < arr[j] && j>= 0)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[++j]=temp;
	}
	for (i=0;i<n;++i)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}