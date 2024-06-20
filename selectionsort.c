#include<stdio.h>
#include<stdlib.h>
void printarr(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d  ",a[i]);
	}
}
main()
{
	int *a,i,j,mind,n,temp;  //mind is the variable for minimum variable index...
	printf("enter size of the array:\n");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	printf("enter %d elements of the array:\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(j=0;j<n;j++)
	{
	mind=j;
		for(i=j;i<n;i++)
		{
			if(a[i]<a[mind])
			mind=i;
		}
		temp=a[j];
		a[j]=a[mind];
		a[mind]=temp;
		
	}
	printf("sorted array is:\n");
	printarr(a,n);
	return(0);
}
