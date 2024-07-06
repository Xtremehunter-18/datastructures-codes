#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node * next;
};
// function to create a linked list...
struct node *createlist(int n)
{
	struct node *head,*temp,*newnode;
	int c;
	head=(struct node *)malloc(sizeof(struct node));
	printf("enter data of node 1:");
	scanf("%d",&head->data);
	temp=head;
	temp->next=NULL;
	for(c=2;c<=n;c++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("enter data of node %d:",c);
	    scanf("%d",&newnode->data);
	    newnode->next=NULL;
	    temp->next=newnode;
	    temp=newnode;
	}
	temp=head;
	return(temp);
}
   // function to traverse a linked list...
 void displaylist(struct node * head)
 {
 	struct node * temp;
 	temp=head;
 	printf("the linked list is:\n");
 	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
 }
main()
{
	int n,c;
	struct node *adhead;   //adhead contains the adress of the head of linked list...
	printf("enter total no of nodes:");
	scanf("%d",&n);
	adhead=createlist(n);
	displaylist(adhead);
	return(0);
}

// coded by xtremehunter...
