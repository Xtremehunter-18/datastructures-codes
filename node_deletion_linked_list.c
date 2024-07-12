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
snode *atbegin(snode * head)
{
	snode *temp;
	temp=head;
	head=head->next;
	free(temp);
	return(head);
}
void atend(snode *head)
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
void inbetn(snode *head,int p)
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
main()
{
	snode *headadress;
	int n,pos,c;
	printf("enter no of nodes for linked list, do you want to create:");
	scanf("%d",&n);
	headadress=createlist(n);
	printf("the linked list is:\n");
	traversal(headadress);
	printf("\nwhich node do you want to delete:\n");
	printf("1.at beginning.\n2.at end.\n3.in between:");
	printf("\nchoice: ");
	scanf("%d",&c);
	switch(c)
	{
		case 1: headadress=atbegin(headadress);
		        printf("\nnode deleted successfully as:");
		        traversal(headadress);
		        getche();
		        break;
		case 2: atend(headadress);
		        printf("\nnode deleted  successfully as:");
		        traversal(headadress);
		        getche();
		        break;
		case 3: printf("enter the position for delete a node:");
		        scanf("%d",&pos);
		        inbetn(headadress,pos);
		        printf("\nnode deleted successfully as:");
		        traversal(headadress);
		        getche();
		        break;
		default: printf("invalid choice!!!");
	}
	return(0);
}

//coded by xtremehunter...
