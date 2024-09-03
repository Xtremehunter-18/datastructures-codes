#include<stdio.h>
#include<stdlib.h>
 struct node 
 {
 	int data;
 	struct node * prev;
 	struct node *next;
 };
 typedef struct node snode;
 #define NALLOC ((snode *)malloc(sizeof(snode)))
 
 //function to create doubly list:
 snode * createlist(int n)
 {
 	snode *head,*newnode,*temp;
 	int c=2;
 	head=NALLOC;
 	printf("enter data for node 1:");
 	scanf("%d",&head->data);
 	head->next=NULL;
 	head->prev=NULL;
 	temp=head;
	for(c=2;c<=n;c++)
	{
		newnode=NALLOC;
		printf("enter data for node %d:",c);
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		newnode->prev=temp;
		temp->next=newnode;
		temp=newnode;
	}
	 printf("\nlist created successfully!");
	return(head);
 }
 
 //function to insert begin
 snode * insertbeg(snode * head)
 {
    snode *newnode,*temp;
    temp=head;
    newnode=NALLOC;
    printf("\nenter value to insert:");
    scanf("%d",&newnode->data);
    newnode->next=temp;
    temp->prev=newnode;
    newnode->prev=NULL;
    head=newnode;
    return(head);
 }
 
 //function to insert between
 void insertbet(snode *head)
 {
 	 int p,c;
 	 snode *newnode,*temp;
 	 temp=head;
 	 printf("\nenter position to insert value:");
 	 scanf("%d",&p);
 	 for(c=1;c<p-1;c++)
 	 {
 	 	temp=temp->next;
	  }
     newnode=NALLOC;
     printf("\nenter value to insert:");
     scanf("%d",&newnode->data);
     newnode->prev=temp;
     (temp->next)->prev=newnode;
     newnode->next=temp->next;
     temp->next=newnode;
 }
 
 // function to insert end
 void insertend(snode * head)
 {
 	snode *temp,*newnode;
 	temp=head;
 	while(temp->next!=NULL)
 	{
 		temp=temp->next;
	 }
	newnode=NALLOC;
	 printf("\nenter value to insert:");
    scanf("%d",&newnode->data);
    temp->next=newnode;
    newnode->next=NULL;
    newnode->prev=temp;
 }
 
 //function to delete begin
 snode * deletebeg(snode * head)
 {
 	 snode *temp;
 	 temp=head;
 	 (temp->next)->prev=NULL;
 	 free(temp);
 	 head=temp->next;
 	 return(head);
 }
 //functino to delete bet
 void deletebet(snode * head)
 {
 	int p,c;
 	snode *temp,*temp1;
 	temp=head;
 	printf("\nenter postion to delete an element:");
 	scanf("%d",&p);
 	for(c=1;c<p;c++)
 	{
 		temp1=temp;
 		temp=temp->next;
	 }
	 temp1->next=temp->next;
	 (temp->next)->prev=temp1;
	 free(temp);
 }
 
 //function to delete end
 void deleteend(snode * head)
 {
 	snode *temp;
 	temp=head;
 	while(temp->next!=NULL)
 	{
 		temp=temp->next;
	 }
	 (temp->prev)->next=NULL;
	 free(temp);
 }
 
 //function to traverse a list
 void traverse(snode * head)
 {
 	snode *temp;
 	temp=head;
 	while(temp!=NULL)
 	{
 		printf("%d  ",temp->data);
 		temp=temp->next;
	}
 }
 
 //function to search element
 void search(snode * head)
 {
 	snode *temp;
 	temp=head;
 	int n,i=1;
 	printf("enter an element to search:");
 	scanf("%d",&n);
	while(temp->next!=NULL)
 	{
 		if(temp->data==n)
 		{
 			printf("found at %d position..",i);
 			exit(1);
		 }
		 temp=temp->next;
 		i++;
	 }
	 printf("\nelement not found...");
 }
main()
{
   int n,c;
   snode *headadress,*head;
   printf("enter total no of nodes:");
   scanf("%d",&n);
   headadress=createlist(n);
   printf("\n");
   printf("\nwhich operation do you want on list:\n");
   printf("1.display\n");
   printf("2.insert at begin\n");
   printf("3.insert between\n");
   printf("4.insert at end\n");
   printf("5.delete at begin\n");
   printf("6.delete between\n");
   printf("7.delete at end\n");
   printf("8.serch\n");
   printf("Enter choice:");
   scanf("%d",&c);
   switch(c)
   {
   	   case 1: printf("\nthe list is: ");
			        traverse(headadress);
   	           break;
         case 2: head=insertbeg(headadress);   	  
			        printf("\nthe list after insertion is: ");
			        traverse(head);
			        break;
         case 3: insertbet(headadress);
                 printf("\nthe list after insertion is: ");
                 traverse(headadress);
                 break;
         case 4: insertend(headadress);
                 printf("\nthe list after insertion is: ");
                 traverse(headadress);
                 break;
         case 5: deletebeg(headadress);
                 head=deletebeg(headadress);
                 printf("\nthe list after deletion is: ");
                 traverse(head);
                 break;
         case 6: deletebet(headadress);
                 printf("\nthe list after deletion is: ");
                 traverse(headadress);
                 break;
         case 7: deleteend(headadress);
                 printf("\nthe list after deletion is: ");
                 traverse(headadress);
                 break;
         case 8: search(headadress);
                 break;
         default: printf("\nInvalid Choice!");
         
	}
   return(0);
}

// coded by Xtremehunter...

