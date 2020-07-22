#include<stdio.h>
#include<conio.h>

int main()
{
	int a[10],i,j,n,temp;
	printf("Enter the number of elements:\n");
	scanf("%d",&n);
	printf("Enter the elements of the array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("The unsorted array is:");
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	for(i=1;i<n;i++)
	{
		j=i;
		while(j>0&&a[j-1]>a[j])
		{
			temp=a[j];
			a[j]=a[j-1];
			a[j-1]=temp
			j=j-1;
		}
	}
	printf("The sorted array in ascending order is:\n");
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}
