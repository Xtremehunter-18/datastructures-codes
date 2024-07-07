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
snode *atbegin(snode * head,int val)
{
	snode *newnode;
	newnode=NODEALLOC;
	newnode->data=val;
	newnode->next=head;
	return(newnode);
}
snode *atend(snode *tail,int val)
{
	snode *newnode;
	newnode=NODEALLOC;
	newnode->data=val;
	newnode->next=NULL;
	tail->next=newnode;
	return(newnode);
}
 void traversal(snode * head)
 {
 	snode *temp;
 	temp=head;
 	while(temp!=NULL)
 	{
 		printf("%d\t",temp->data);
 		temp=temp->next;
	 }
 }
main()
{
	snode *headadress,*temp;
	int n,c,d;
	printf("enter no of nodes do you want to create:");
	scanf("%d",&n);
	headadress=createlist(n);
	temp=headadress;
	printf("the linked list is:\n");
	traversal(headadress);
	printf("\nwhere do you want to add a node:\n");
	printf("1.at beginning.\n2.at end.");
	printf("\nchoice: ");
	scanf("%d",&c);
	switch(c)
	{
		case 1: printf("please enter data for node:");
		        scanf("%d",&d);
		        temp=atbegin(headadress,d);
		        traversal(temp);
		        printf("node added successfully..");
		        break;
		case 2: while(temp->next!=NULL)
		        {
			       temp=temp->next;
	        	}
		        printf("please enter data for node:");
		        scanf("%d",&d);
		        atend(temp,d);
		        traversal(headadress);
		        printf("node added successfully..");
		        break;
		default:printf("invalid choice..");
		        break;
	}
	return(0);
}

//coded by xtremehunter...
