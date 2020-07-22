#include<stdio.h>
#include<conio.h>

int main()
{
	int a[10],i,j,n,temp;
	printf("Enter the number of elements of the array:\n");
	scanf("%d"&n);
	
	printf("Enter the elements of the array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("The unsorted array is:\n");
	for(i=0;i<n;i++)
	{
		printf("%d \t",a[i]);
	}
	
	for(i=0;i<(n-1);i++)
	{
		for(j=0;j<(n-i-1);j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	
	printf("\nThe sorted array in ascending order is:\n");
	for(i=0;i<n;i++)
	{
		printf("%d \t",a[i]);
	}
}
