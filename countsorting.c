#include<stdio.h>
#include<stdlib.h>
void printarr(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
int findmax(int a[],int n)
{
	int i=0,m;
	m=a[i];
	for(i=0;i<n;i++)
	{
		if(a[i]>m)
		m=a[i];
	}
	return(m);
}
void counts(int a[],int n)
{
	int *count,max,b[n],i,k,j;
	max=findmax(a,n);
	printf("max is %d\n",max);
	count=(int *)malloc((max+1)*sizeof(int));
	for(i=0;i<=max;i++)
	{
	count[i]=0;
	}
	for(i=0;i<n;i++)
	{
	count[a[i]]++;
	}
	for(i=1;i<=max;i++)
	{
		count[i]=count[i]+count[i-1];
	}
	for(i=n-1;i>=0;i--)
	{
	    b[count[a[i]]-1]=a[i];
	    count[a[i]]--;
	}
	
	for(i=0;i<n;i++)
	{
		a[i]=b[i];
	}
	
}
main()
{
	int *a,n,i;
	printf("enter size of the given array:\n");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	printf("enter elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	counts(a,n);
	printarr(a,n);
}
