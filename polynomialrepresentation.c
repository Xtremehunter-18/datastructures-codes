#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int coef;
	int pow;
	struct node *next;
};
typedef struct node snode;
#define NALLOC ((snode *)malloc(sizeof(snode)))

//function to create the list:
snode * createlist( int n)
{
	int c;
	snode *temp, *newnode ,*head;
	head=NALLOC;
	printf("Enter coef of term 1 with sign:");
	scanf("%d",&head->coef);
	printf("enter power of term 1:");
	scanf("%d",&head->pow);
	head->next=NULL;
	temp=head;
	for(c=2;c<=n;c++)
	{
		newnode=NALLOC;
		printf("Enter coef of term %d with sign:",c);
	   scanf("%d",&newnode->coef);
	   printf("enter power of term %d:",c);
	   scanf("%d",&newnode->pow);
	   temp->next=newnode;
	   newnode->next=NULL;
	   temp=newnode;
	}
	
	return(head);
}

// function to display the polynomial:
void display(snode * head)
{
	snode *temp;
	temp=head;
	while(temp!=NULL)
	{
		if(temp->pow==0)
		{
			printf("(%d)",temp->coef);
			exit(0);
		}
		printf("(%dx^%d)+",temp->coef,temp->pow);
		temp=temp->next;
	}
	printf("\npolynomial created successfully..");
}
main()
{
	int n;
	snode * head;
	printf("enter terms of polynomials:");
	scanf("%d",&n);
	head=createlist(n);
	printf("polynomial is: ");
	display(head);
   return(0);
}
// coded by Xtremehunter...
