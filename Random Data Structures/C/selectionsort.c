#include<stdio.h>
#include<conio.h>

int main()
{
	int a[10],i,j,n,loc,temp;
	printf("Enter the number of elements:\n");
	scanf("%d",&n);
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
	    loc=i;
	    for(j=(i+1);j<n;j++)
	    {
	    	if(a[loc]>a[j])
	    	loc=j;
		}
		if(loc!=i)
		{
			temp=a[i];
			a[i]=a[loc];
			a[loc]=temp;
		}
	}
	printf("\nThe sorted array in ascending order is:\n");
	for(i=0;i<n;i++)
	{
		printf("%d \t",a[i]);
	}
}
