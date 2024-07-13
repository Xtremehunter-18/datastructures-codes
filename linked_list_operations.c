#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node * next;
};
typedef struct node snode;
#define NODEALLOC ((snode *)malloc(sizeof(snode)))
snode * createlist(int n)
{
	int c;
	snode *newnode,*temp,*head;
	head=NODEALLOC;
	printf("enter value for node 1:");
	scanf("%d",&head->data);
	head->next=NULL;
	temp=head;
	for(c=2;c<=n;c++)
	{
		newnode=NODEALLOC;
		printf("enter data for node %d:",c);
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		temp->next=newnode;
		temp=newnode;
	}
	return(head);
}

snode *insertbeg(snode * head,int val)
{
	snode *newnode;
	newnode=NODEALLOC;
	newnode->data=val;
	newnode->next=head;
	return(newnode);
}

void insertend(snode *head,int val)
{
	
	snode *newnode,*temp;
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	newnode=NODEALLOC;
	newnode->data=val;
	newnode->next=NULL;
	temp->next=newnode;
}

void insertbet(snode *head,int p,int value)
{
	snode *temp,*newnode;
	int c=1;
	temp=head;
	for(c=1;c<p-1;c++)
	{
		temp=temp->next;
	}
	newnode=NODEALLOC;
	newnode->data=value;
	newnode->next=temp->next;
	temp->next=newnode;
	return;
}

snode *delbeg(snode * head)
{
	snode *temp;
	temp=head;
	head=head->next;
	free(temp);
	return(head);
}
void delend(snode *head)
{
	snode *temp,*temp1;
	temp=head;
	while(temp->next!=NULL)
	{
		temp1=temp;
		temp=temp->next;
	}
	temp1->next=NULL;
	free(temp);
}
void delbet(snode *head,int p)
{
	snode *temp,*temp1;
	int t=1;
	temp=head;
	while(t<p)
	{
		temp1=temp;
		temp=temp->next;
		t++;
	}
	temp1->next=temp->next;
	free(temp);
}
	
	 void traversal(snode * head)
 {
 	snode *temp;
 	temp=head;
 	printf("\n");
 	while(temp!=NULL)
 	{
 		printf("%d\t",temp->data);
 		temp=temp->next;
	 }
 }
 
 void search(snode * head,int val)
 {
 	snode *temp;
 	int c=1;
 	temp=head;
 	while(temp->next!=NULL)
 	{
 		if(val==temp->data)
 		{
 			printf("found at %d position.",c);
 			return;
		 }
		 temp=temp->next;
		 c++;
	 }
 }
 main()
{
 	int n,c,t,pos;
 	snode * headadress;
 	printf("enter number of nodes of list:");
 	scanf("%d",&n);
 	headadress=createlist(n);
 	printf("which operation do you want on list?\n");
 	printf("1.display list:\n");
 	printf("2.insert node at begining:\n");
 	printf("3.insert node at end:\n");
 	printf("4.insert node at position:\n");
 	printf("5.delete node at begining:\n");
 	printf("6.delete node at end:\n");
 	printf("7.delete node at position:\n");
 	printf("8.search an element:\n");
 	printf("9.exit:\n");
 	printf("\nchoice:");
 	scanf("%d",&c);
 	switch(c)
 	{
 		case 1: traversal(headadress);
 		        break;
 		case 2: printf("enter a value:");
 		        scanf("%d",&t);
 		        headadress=insertbeg(headadress,t);
 		        printf("node added successfully as:\n");
 		        traversal(headadress);
 		        break;
 		case 3: printf("enter a value:");
 		        scanf("%d",&t);
 		        insertend(headadress,t);
 		        printf("node added successfully as:\n");
 		        traversal(headadress);
 		        break;
 		case 4: printf("enter the value:");
 		        scanf("%d",&t);
		        printf("enter the position:");
 		        scanf("%d",&pos);
 		        insertbet(headadress,pos,t);
 		        printf("node added successfully as:\n");
 		        traversal(headadress);
 		        break;
 		case 5: headadress=delbeg(headadress);
 		        printf("node deleted successfully as:\n");
 		        traversal(headadress);
 		        break;
 		case 6: delend(headadress);
 		        printf("node deleted successfully as:\n");
 		        traversal(headadress);
 		        break;
 		case 7: printf("enter the position:");
 		        scanf("%d",&pos);
 		        delbet(headadress,pos);
 		        printf("node deleted successfully as:\n");
 		        traversal(headadress);
 		        break;
 		case 8: printf("enter the value:");
 		        scanf("%d",&t);
 		        search(headadress,t);
 		        break;
 		case 9: printf("Process Exited...");
		        break;
 		default: printf("invalid choice!");
	 }
	 return(0);
 }
 
 //coded by xtremehunter...
