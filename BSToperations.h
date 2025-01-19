#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *l;
   struct node *r;
};


typedef struct node TNODE;
#define NALLOC (struct node*)malloc(sizeof(struct node))

struct queue
{
	TNODE *items[20];
	int f,r;
};
typedef struct queue QUE;

int isempty(QUE *q)
{
	if(q->r==q->f)
	return 1;
	else
	return 0;
}

void add(QUE *q, TNODE *val)
{
	q->items[++q->r]=val;
}

TNODE *del(QUE *q)
{
	return(q->items[++q->f]);
}

int c=0,d=0,e=0,s=0;

void init(TNODE **root)
{
	*root=NULL;
}

TNODE *createbst(TNODE *root) 
{
    TNODE *temp,*newnode;
    int val;
    char ch;
    do
    {
    	newnode=NALLOC;
    	printf("enter value: ");
    	scanf("%d",&val);
    	newnode->data=val;
    	newnode->l=newnode->r=NULL;
	 if(root==NULL)
	 {
	 	root=newnode;
	 }
	 else 
	 {
	 temp=root;
	 while(temp!=NULL)
	 {
	 	if(val<temp->data)
	 	{
	 		 if(temp->l==NULL)
	 		 {
	 	    	temp->l=newnode;
	 	    	break;
			  }
	      else
		   temp=temp->l;
		 }
		 else	if(val>temp->data)
		 {
		 	  if(temp->r==NULL)
		 	  {
		 		temp->r=newnode;
		 		break;
			  }
			  else
			 temp=temp->r;
		 }
		 else 
		 {
		 	printf("key already exist..\n");
		 	break;
		 }
	  }
	 }
	 printf("Any more value? Y/N:");
	 scanf("%s",&ch);
   }while(ch=='Y');
   return root;	 	
}
  
  void recpreorder(TNODE *root)  //1
  {
  	if(root)
  	{
  	   printf("%d - ",root->data);
  	   recpreorder(root->l);
  	   recpreorder(root->r);
   }
  }
  
  void recinorder(TNODE *root)   //2
  {
  	if(root)
  	{
  	    recinorder(root->l);
  	    printf("%d - ",root->data);
  	    recinorder(root->r);
   }
  }
  
void recpostorder(TNODE *root)  //3
  {
  	if(root)
  	{
  	    recpostorder(root->l);
  	    recpostorder(root->r);
  	    printf("%d - ",root->data);
   }
  }
  
  void levelorder(TNODE *root)  //4
  {
  	  TNODE *temp=root;
  	  QUE q;
  	  q.f=q.r=-1;
  	  if(root)
  	  {
  	     	add(&q,temp);
  	     	while(!isempty(&q))
  	     	{
  	     	   temp=del(&q);
				printf("%d ",temp->data);
				if(temp->l!=NULL)
				 add(&q,temp->l);
		      if(temp->r!=NULL)
		        add(&q,temp->r);
	      }
	  }
  }

  TNODE *insertkey(TNODE *root,int key)  //5
{
	TNODE *newnode;
	if(root==NULL)
	{
		newnode=NALLOC;
	   newnode->data=key;
	   newnode->l=NULL;
	   newnode->r=NULL;
		root=newnode;
		return root;
	}
	else if(key<root->data)
	{
	  root->l=insertkey(root->l,key);
   }
	else if(key>root->data)
	{
		root->r=insertkey(root->r,key);
	} 
	else
	{
	 printf("key already exist..\n");
	 return NULL;
	}
}
  
  void searchkey(TNODE *root, int key)  //6
  {
  	  TNODE *temp;
	  temp=root;
	  while(temp!=NULL)
	  {
	  	 if(key==temp->data)
  	  {
  	     printf("key found");
  	     return;
	  }
	  else if(key<temp->data)
	  	 {
	  	 	temp=temp->l;
		 }
		 else
		 {
		 	temp=temp->r;
		 }
	  }
	  printf("key not found!");
  }
  
  int leafnodes(TNODE *root)   //7
  {
  	  TNODE *temp=root;
  	  if(temp)
  	  {
  	     if(temp->l==NULL&&temp->r==NULL)	
  	        c++;
  	     c=leafnodes(temp->l);
  	     c=leafnodes(temp->r);
     }
     return c;
  }
  
  int nonleafnodes(TNODE *root)  //8
  {
  	  TNODE *temp=root;
  	  if(temp)
  	  {
  	     if(temp->l!=NULL||temp->r!=NULL)	
  	        d++;
  	     d=nonleafnodes(temp->l);
  	     d=nonleafnodes(temp->r);
     }
     return d;
  }
  
  int totalnodes(TNODE *root)  //9
  {
  	  TNODE *temp=root;
  	  if(temp)
  	  {
  	  	  e++;
  	  	  e=totalnodes(root->l);
  	  	  e=totalnodes(root->r);
	  }
		 return e;
  }
  
  TNODE *replace(TNODE *root,int oldkey,int newkey)  //10
  {
  	  TNODE *temp=root;
  	  if(oldkey==temp->data)
  	  {
  	      temp->data=newkey;
         return root;	
	  }
	  else if(oldkey<temp->data)
	  {
	  	   root->l=replace(root->l,oldkey,newkey);
	  }
	  else if(oldkey>temp->data)
	  {
	  	   root->r=replace(root->r,oldkey,newkey);
	  }
	  else
	  {
	  	      printf("old key does not exist..");
	  }
  }
  
  TNODE *inverttree(TNODE *root)  //11
  {
  	TNODE *temp;
  	if(root)
  	{
  	    temp=root->l;
  	    root->l=root->r;
  	    root->r=temp;
  	    inverttree(root->l);
  	    inverttree(root->r);
   }
   return root;
  }
   
   int findmax(TNODE *root)  //12
  {
  	 TNODE *temp=root;
  	 while(temp->r!=NULL)
  	 {
 	   temp=temp->r;
    }
    return temp->data;
  }
   
   TNODE *deletekey(TNODE *root,int val)  //13
   {
   	TNODE *temp;
   	if(root)
   	{
   		if(val<root->data)
   		   root->l=deletekey(root->l,val);
		   else if(val>root->data)
		      root->r=deletekey(root->r,val);
         else
         {
         	 if(root->l!=NULL && root->r!=NULL)
         	 {    
				      int t;
         	 	   t=findmax(root->l);
         	 	   root->data=t;
         	 	   root->l=deletekey(root->l,t);
				 }
				 else if(root->l!=NULL)
				 {
				 	temp=root;
				 	root=root->l;
				 	free(temp);
				 }
				 else if(root->r!=NULL)
				 {
				 	temp=root;
				 	root=root->r;
				 	free(temp);
				 }
				 else
				   root=NULL;
			}
			
		}
		return root;
	}
  
  
  int findmin(TNODE *root)  //14
  {
  	 TNODE *temp=root;
  	 while(temp->l!=NULL)
  	 {
 	   temp=temp->l;
    }
    return temp->data;
  }
  
  int sumofnodes(TNODE *root)  //15
  {
  	TNODE *temp=root;
  	if(temp)
  	{
  	s=s+temp->data;
  	s=sumofnodes(temp->l);
  	s=sumofnodes(temp->r);
   }
   	return s;
  }
