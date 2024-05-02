#include<stdio.h>
#include<time.h>
void selectionSort(int arr[], int n)
{
	int i,j,min_idx,temp;
	for(i=0;i<n-1;i++)
	{
		min_idx = i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min_idx])
			{
				min_idx = j;
			}
		}
		temp=arr[min_idx];
		arr[min_idx]=arr[i];
		arr[i]=temp;
	}
}
int main()
{
	int  n;
	printf("Enter Number of Element:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter Element:\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Array before sorting:\n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	clock_t start,end;
	double cpu_time_used;
	
	start = clock();
	selectionSort(arr,n);
	end = clock();
	printf("\nArray after sorting:\n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	cpu_time_used = ((double)(end-start)) / CLOCKS_PER_SEC;
	
	printf("\nTime taken %f for exicute\n",cpu_time_used);
	return 0;
}
