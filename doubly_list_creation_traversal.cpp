#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node * next;
	struct node * prev;
};
 typedef struct node snode;
 #define NALLOC ((struct node *)malloc(sizeof(snode)))
 // function for creation of doubly linked list...
 snode *createlist(int n)
 {
 	int i;
 	snode *head,*newnode, *temp;
 	head=NALLOC;
 	printf("enter data of node 1:");
 	scanf("%d",&head->data);
 	head->prev=NULL;
 	head->next=NULL;
 	temp=head;
 	for(i=2;i<=n;i++)
 	{
 		newnode=NALLOC;
 		printf("enter data for node %d :",i);
 		scanf("%d",&newnode->data);
 		temp->next=newnode;
 		newnode->next=NULL;
 		newnode->prev=temp;
 		temp=newnode;
	 }
	 printf("list created successfully..\n");
	 return(head);
 }
 // function for traverse list forward...
 void ftraversal(snode *head)
 {
 	snode *temp;
 	temp=head;
 	printf("the list in forward order is: ");
 	while(temp!=NULL)
 	{
 		printf("%d  ",temp->data);
 		temp=temp->next;
	 }
}
// function to travel list backward...
void btraversal(snode * head)
{
	snode *temp;
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	printf("\nthe list in backward order is:");
	while(temp!=NULL)
	{
		printf("%d  ",temp->data);
		temp=temp->prev;
	}
}
main()
{
	snode *headadress;
	int n;
	printf("enter no of nodes of doubly list:");
	scanf("%d",&n);
	headadress=createlist(n);
	ftraversal(headadress);
	btraversal(headadress);
	return(0);
}
