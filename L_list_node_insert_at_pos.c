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


void traversal(snode * head)
 {
 	snode *temp;
 	temp=head;
 	while(temp!=NULL)
 	{
 		printf("%d   ",temp->data);
 		temp=temp->next;
	 }
 }

void atposition(snode *head,int p,int value)
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
main()
{
	int pos,d, n;
	snode *headnode;
	printf("enter no. of nodes:");
	scanf("%d",&n);
	headnode=createlist(n);
	printf("the list is: ");
	traversal(headnode);
	printf("\nat which position do you want to add a node:");
	scanf("%d",&pos);
	printf("which value do you want to insert?");
	scanf("%d",&d);
	atposition(headnode,pos,d);
	printf("new linked list is: ");
	traversal(headnode);
	return 0;
}
