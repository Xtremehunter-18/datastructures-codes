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
	int *a,i,j,n,key,t;  
	printf("enter size of the array:\n");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	printf("enter %d elements of the array:\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<n;i++)
	{
		j=i;
		while(a[j-1]>a[j]&&(j-1)>=0)
		{
		    t=a[j];
		    a[j]=a[j-1];
		    a[j-1]=t;
			j--;
		}
	}
	printf("sorted array is:\n");
	printarr(a,n);
	return(0);
}
	
