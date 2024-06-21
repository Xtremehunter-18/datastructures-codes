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
void merg(int x[],int m,int l,int h)
{
	int i,j,k,b[100];
	i=l;
	j=m+1;
	k=l;
	while(i<=m && j<=h)
	{
		if(x[i]<x[j])
		{
			b[k]=x[i];
			i++;
			k++;
		}
		else
		{
			b[k]=x[j];
			j++;
			k++;
		}
    }
		while(i<=m)
		{
			b[k]=x[i];
			k++;
			i++;
		}
			while(j<=h)
		{
			b[k]=x[j];
			k++;
			j++;
		}
	for(i=l;i<=h;i++)
	{
		x[i]=b[i];
	}
	
}
void merges(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		merges(a,low,mid);
		merges(a,mid+1,high);
		merg(a,mid,low,high);
	}
}

main()
{
	int *a,n,i;
	printf("enter size of the array:\n");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	printf("enter %d elements:\n",n);
	for(i=0;i<n;i++)
	   scanf("%d",&a[i]);
	merges(a,0,n-1);
	printarr(a,n);
}
