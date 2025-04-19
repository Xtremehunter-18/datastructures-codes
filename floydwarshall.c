#include<stdio.h>
#include<stdlib.h>
#define INF 909

void printmatrix(int mat[10][10],int v)
{
	int i,j;
	for(i=0;i<v;i++)
   {
   	for(j=0;j<v;j++)
   	{
   		printf("%3d",mat[i][j]);
		}
		printf("\n");
	}
}

main()
{
	int v,e,i,j,temp,k;
   int mat[10][10],dist[10][10];
	printf("enter no of vertices and edges:");
	scanf("%d %d",&v,&e);
   printf("enter distance matrix(enter 99 for infinity):");
   for(i=0;i<v;i++)
   {
   	for(j=0;j<v;j++)
   	{
	   	scanf("%d",&temp);
   		if(temp==99)
   		  mat[i][j]=INF;
 		   mat[i][j]=temp;
		}
	}
	printf("original matrix is: \n");
	printmatrix(mat,v);
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			dist[i][j]=mat[i][j];
		}
	}
	
	// logic for warshalls algorithm..
	for(k=0;k<v;k++)
	{
		for(i=0;i<v;i++)
		{
			for(j=0;j<v;j++)
			{
				if(dist[i][k]+dist[k][j]<dist[i][j])
				    dist[i][j]=dist[i][k]+dist[k][j];
			}
		}
	}
	
		for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			mat[i][j]=dist[i][j];
		}
	}
	printf("the shortest distance between every pair of vertices is:\n");
	printmatrix(mat,v);
	printf("\n note that 99 used for note infinity..!");
   return(0);
}

// coded by yash pagar ...

