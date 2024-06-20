#include<stdio.h>
#include<stdlib.h>
void printarr(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
int partition(int a[],int low,int high)
    {
	     int pivot,i,j,temp;
	     pivot=a[low];
	     i=low+1;
	     j=high;
	   do
	   {
	     	while(a[i]<=pivot)
	     	{	
	     	   i++;
			}
	     	while(a[j]>pivot)
	     	{
	     	    j--;
			}
	     	if(i<j)
			 {	
	     	    temp=a[i];
	     	    a[i]=a[j];
	     	    a[j]=temp;
			 }
	    } while(i<j);
		 
		 temp=a[low];
		 a[low]=a[j];
		 a[j]=temp;
		 return(j);
	}
void quicksort(int a[],int low,int high)
{
	int partindex;
	if(low<high)
	{
	partindex=partition(a,low,high);
	quicksort(a,low,partindex-1);
	quicksort(a,partindex+1,high);
	}
}
main()
{
	int *a,n,i;
	printf("enter size of the array:\n");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	printf("enter values in array:\n");
	for(i=0;i<n;i++)
	{
	   scanf("%d",&a[i]);
	}
	quicksort(a,0,n-1);
	printf("sorted array is:\n");
	printarr(a,n);
	return(0);
}
