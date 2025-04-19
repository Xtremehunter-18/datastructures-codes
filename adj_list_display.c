#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct listnode
{
	int vertex;
	struct listnode *next;
};
typedef struct listnode lnode;
#define NALLOC (lnode *)malloc(sizeof(lnode))
struct list
{
	lnode *head;
};
typedef struct list  slist;
#define LALLOC (slist *)malloc(sizeof(slist))

int main()
{
	int v,e,s,d,i;
	lnode *srcnode,*destnode,*temp;
	slist *adj[MAX]={0};
	printf("enter no. of vertices and edges of graph:");
	scanf("%d %d",&v,&e);
	for(i=0;i<v;i++)
	{
		adj[i]=LALLOC;
		adj[i]->head=NULL;
	}
	for(i=0;i<e;i++)
	{
		printf("enter edge (source node and destination node):");
		scanf("%d %d",&s,&d);
		if(adj[s]->head==NULL)
		{
			srcnode=NALLOC;
			srcnode->vertex=s;
			srcnode->next=NULL;
			adj[s]->head=srcnode;
		}
		destnode=NALLOC;
		destnode->vertex=d;
		destnode->next=NULL;
		temp=adj[s]->head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=destnode;
  }
  printf("list created..!\n");
  printf("the list is:\n");
  for(i=0;i<v;i++)
  {
     lnode *temp1=adj[i]->head;
     printf("adjacent vertices to vertex %d are:",i);
	  	while(temp1!=NULL)
	  	{
	  		printf("%d -> ",temp1->vertex);
	  		temp1=temp1->next;
	   }
	   printf("NULL\n");
	  }
  }

// coded by Xtremehunter...

