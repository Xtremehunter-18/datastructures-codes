#include<stdio.h>
#include<stdlib.h>
struct product
{
	int pno;
	char pname[20];
	float price;
	struct mgdate
	{
		int day;
		int month;
		int year;
	}mg;
};
typedef struct product prod;
struct node 
{
	prod p;
	struct node * next;
};
typedef struct node snode;
#define NALLOC ((snode *)malloc(sizeof(snode)))
snode *createlist(int n)
{
	int c;
	snode *head,*temp,*newnode;
	head=NALLOC;
	printf("enter details of product 1:\n");
	printf("product no:");
	scanf("%d",&head->p.pno);
	printf("product name:");
	scanf("%s",head->p.pname);
	printf("price:");
	scanf("%f",&head->p.price);
	printf("manufacturing date:\n");
	printf("day:");
	scanf("%d",&head->p.mg.day);
	printf("month:");
	scanf("%d",&head->p.mg.month);
	printf("year:");
	scanf("%d",&head->p.mg.year);
	head->next=NULL;
	temp=head;
	for(c=2;c<=n;c++)
	{
		newnode=NALLOC;
	   printf("enter details of product %d:\n",c);
	   printf("product no:");
	   scanf("%d",&newnode->p.pno);
    	printf("product name:");
   	scanf("%s",newnode->p.pname);
   	printf("price:");
   	scanf("%f",&newnode->p.price);
   	printf("manufacturing date:\n");
   	printf("day:");
   	scanf("%d",&newnode->p.mg.day);
	   printf("month:");
   	scanf("%d",&newnode->p.mg.month);
   	printf("year:");
   	scanf("%d",&newnode->p.mg.year);
   	newnode->next=NULL;
   	temp->next=newnode;
   	temp=newnode;
	}
	return(head);
}
 // function to insert data at begin:
 snode * insertbeg(snode * head)
 {
 	   snode *newnode;
 	   newnode=NALLOC;
 	   printf("enter details of product:\n");
	   printf("product no:");
	   scanf("%d",&newnode->p.pno);
    	printf("product name:");
   	scanf("%s",newnode->p.pname);
   	printf("price:");
   	scanf("%f",&newnode->p.price);
   	printf("manufacturing date:\n");
   	printf("day:");
   	scanf("%d",&newnode->p.mg.day);
	   printf("month:");
   	scanf("%d",&newnode->p.mg.month);
   	printf("year:");
   	scanf("%d",&newnode->p.mg.year);
   	newnode->next=head;
   	return(newnode);
 }
 
 // function to insert data at position:
 void insertbet(snode * head,int p)
 {
 	   int t=1;
 	   snode * temp,*newnode;
 	   temp=head;
 	   while(t<p-1)
 	   {
 	   	temp=temp->next;
 	   	t++;
		 }
      newnode=NALLOC;
		printf("enter details of product:\n");
	   printf("product no:");
	   scanf("%d",&newnode->p.pno);
    	printf("product name:");
   	scanf("%s",newnode->p.pname);
   	printf("price:");
   	scanf("%f",&newnode->p.price);
   	printf("manufacturing date:\n");
   	printf("day:");
   	scanf("%d",&newnode->p.mg.day);
	   printf("month:");
   	scanf("%d",&newnode->p.mg.month);
   	printf("year:");
   	scanf("%d",&newnode->p.mg.year);
   	newnode->next=temp->next;
   	temp->next=newnode;
   	return;
 }
 
 //function to insert data at end:
 void insertend(snode * head)
 {
 	snode *temp,*newnode;
 	temp=head;
 	while(temp->next!=NULL)
 	{
 	   temp=temp->next;	
	}
	   newnode=NALLOC;
		printf("enter details of product:\n");
	   printf("product no:");
	   scanf("%d",&newnode->p.pno);
    	printf("product name:");
   	scanf("%s",newnode->p.pname);
   	printf("price:");
   	scanf("%f",&newnode->p.price);
   	printf("manufacturing date:\n");
   	printf("day:");
   	scanf("%d",&newnode->p.mg.day);
	   printf("month:");
   	scanf("%d",&newnode->p.mg.month);
   	printf("year:");
   	scanf("%d",&newnode->p.mg.year);
   	temp->next=newnode;
   	newnode->next=NULL;
 }
 
 // function to delete furst data:
 snode * deletebeg(snode *head)
 {
 	   snode * temp;
 	   temp=head;
 	   head=head->next;
 	   free(temp);
 	   return(head);
 }
 
 // function to delete data at position:
 void deletebet(snode * head,int p)
 {
    	int t=1;
 	   snode * temp,*temp1;
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
 
 // function to delete at end:
 void deleteend(snode * head)
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
 
 // function to search
 void psearch(snode *head,int m)
 {
 	 snode * temp;
 	 int s=1;
 	 temp=head;
 	 while(1)
 	 {
 	 	if(m==temp->p.pno)
 	 	{
 	 	printf("found at record no %d.\n",s);
 	 	return;
		}
		temp=temp->next;
 	 	s++;
	  }
 }
 
 // function to display list:
 void traversal(snode * head)
 {
 	snode * temp;
 	temp=head;
 	while(temp!=NULL)
 	{
 		printf("product no:%d\n",temp->p.pno);
 		printf("product name is:%s\n",temp->p.pname);
 		printf("price is:%f\n",temp->p.price);
 		printf("manufacturing date is:%d/%d/%d\n",temp->p.mg.day,temp->p.mg.month,temp->p.mg.year);
 		temp=temp->next;
	 }
 }
main()
{
   int n,c,p,pn,i;
   snode * headadress,* headadr;;
   printf("enter total no of products:");
   scanf("%d",&n);
   headadress=createlist(n);
   printf("which operation do you want to do on product list:\n");
   printf("1.display\n");
   printf("2.insert at begin\n");
   printf("3.insert between\n");
   printf("4.insert at end\n");
   printf("5.delete at begin\n");
   printf("6.delete between\n");
   printf("7.delete at end\n");
   printf("8.search\n");
   printf("9.exit\n");
   printf("choice: ");
   scanf("%d",&c);
   switch(c)
   {
   	case 1: printf("the product list is:\n");
   	        traversal(headadress);
   	        break;
      case 2: headadr=insertbeg(headadress);
              printf("the list after insertion is:\n");
              traversal(headadr);
              break;
      case 3: printf("enter position to insert:\n");
              scanf("%d",&p);
		        insertbet(headadress,p);
              printf("the list after insertion is:\n");
              traversal(headadress);
              break;
      case 4: insertend(headadress);
              printf("the list after insertion is:\n");
              traversal(headadress);    
              break;
      case 5: headadr=deletebeg(headadress);
              printf("the list after deletion is:\n");
              traversal(headadr);
              break;
      case 6: printf("enter position to delete:\n");
              scanf("%d",&p);
              deletebet(headadress,p);
              printf("the list after deletion is:\n");
              traversal(headadress);
              break;
      case 7: deleteend(headadress);
              printf("the list after deletion is:\n");
              traversal(headadress);
              break;
      case 8: printf("enter product no:");
              scanf("%d",&pn);
              psearch(headadress,pn);
              break;
      case 9: printf("process exited!!!\n");
              break;
      default : printf("invalid choice...\n");
	}

   return(0);
}

// coded by Xtremehunter...
