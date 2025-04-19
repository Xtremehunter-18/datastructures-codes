#include<stdio.h>
#include<stdlib.h>

struct node
{
	int v;
	struct node *next;
};
typedef struct node snode;
#define NALLOC (snode *)malloc(sizeof(snode))

struct list
{
	snode *head;
};
typedef struct list slist;
#define LALLOC (slist *)malloc(sizeof(slist))

struct queue
{
	int f;
	int r;
	int value[20];
};
typedef struct queue que;

void enque(que *q,int n)
{
	q->value[++q->r]=n;
}

int deque(que *q)
{
	return(q->value[++q->f]);
}

int isempty(que *q)
{
	if(q->f==q->r)
	return 1;
	else 
	return 0;
}

main()
{
	int v,e,i,d,s;
   slist *adj[10]={0};
   snode *temp,*srcnode,*destnode;
   printf("enter no vertices and edges of graph:");
   scanf("%d %d",&v,&e);
   for(i=0;i<v;i++)
   {
   	adj[i]=LALLOC;
   	adj[i]->head=NULL;
	}
	for(i=0;i<e;i++)
	{
		printf("enter edge(source and destination):");
		scanf("%d %d",&s,&d);
		if(adj[s]->head==NULL)
		{
			srcnode=NALLOC;
			srcnode->v=s;
			srcnode->next=NULL;
			adj[s]->head=srcnode;
		}
		destnode=NALLOC;
		destnode->v=d;
		destnode->next=NULL;
		temp=adj[s]->head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=destnode;
	}
	printf("list created...\n");
	for(i=0;i<v;i++)
	{
		snode *temp1=adj[i]->head;
		printf("adjacent list of vertex %d is: ",i);
		while(temp1!=NULL)
		{
			printf("%d -> ",temp1->v);
			temp1=temp1->next;
		}
		printf("NULL\n");
	}
	printf("BFS traversal of tree is:");
	{
		int status[v]; 
		for(i=0;i<v;i++)
		    status[i]=1;
		que q;
		snode *t,*temp1;
		int tem;
		q.f=q.r=-1;
		t=adj[0]->head;
		enque(&q,t->v);
		status[0]==2;
		while(!isempty(&q))
		{
			tem=deque(&q);
			printf("%d -> ",tem);
			status[tem]=3;
			temp1=adj[tem]->head;
			while(temp1!=NULL)
			{
				if(status[temp1->v]==1)
				{
					enque(&q,temp1->v);
					status[temp1->v]==2;
				}
				temp1=temp1->next;
			}
		}
		printf("NULL\n");
	}
   return(0);
}

// coded by Xtremehunter...

