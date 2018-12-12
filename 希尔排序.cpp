#include<stdio.h>
int main()
{
	int i,j,n;
	int arr[50005];
	int gap;
	scanf("%d",&n);
	for (i=0;i<n;++i)
	{
		scanf("%d",&arr[i]);
	}
	for (gap=n>>1;gap>0;gap>>=1)
	{
		for(i=gap;i<n;i++)
		{
			j = i -gap;
			int temp = arr[i];
			while(temp<arr[j] && j>=0)
			{
				arr[j+gap] = arr[j];
				j-=gap;
			}
			arr[j+gap]=temp;
		}
	}
	for (i=0;i<n;++i)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}