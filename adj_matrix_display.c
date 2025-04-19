#include<stdio.h>
#include<stdlib.h>

void createmat(int mat[10][10],int v,int e)
{
   int i,j,k;
	for(i=0;i<v;i++)
   {
      for(j=0;j<v;j++)	
      { 
          mat[i][j]=0;
		}
	}
	for(i=1;i<=e;i++)
	{
		printf("enter edge no %d in the format(node1 node1):",i);
		scanf("%d %d",&j,&k);
		mat[j][k]=mat[k][j]=1;
	}
}

void displaymat(int mat[10][10],int v)
{
	int i,j;
	{
	  for(i=0;i<v;i++)
	  {
	  	  for(j=0;j<v;j++)
	  	  {
	  	      printf("%d ",mat[i][j]);
		  }
		  printf("\n");
	  }
   }
}

void degofvertex(int mat[10][10],int v)
{
	  int n,s=0,i;
	  printf("which vertex's degree so you want to find: ");
	  scanf("%d",&n);
	  for(i=0;i<v;i++)
	  {
	  	s=s+mat[i][n];
	  }
	  printf("degree of vertex %d is :%d",n,s);
}
int main()
{
	int mat[10][10];
	int i,j,v,e;
	printf("enter no of vertices and edges of graph:");
	scanf("%d %d",&v,&e);
	createmat(mat,v,e);
   printf("adjacent matrix is: \n");
   displaymat(mat,v);
   degofvertex(mat,v);
}

// coded by yash pagar...
