#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define KEY 10
struct student
{
	char name[20];
	int standard;
};
 typedef struct student stud;
 #define SALLOC (stud *)malloc(sizeof(stud))
 
 char *str="null";
 int hash(int rno)
 {
 	return (rno%KEY);
 }
 
 void insert(stud s[KEY],int r)
 {
 	r=hash(r);
 	if(s[r].standard==-1)
 	{
 		printf("enter standard:");
	   scanf("%d",&s[r].standard);
 		printf("enter name: ");
 		scanf("%s",s[r].name);
	   return;
	 }
	 else
	 {
	 	r=r+1;
	 	insert(s,r);
	 }
 }
 
 void display(stud s[KEY])
 {
 	int i=1;
 	printf("rno      name       std\n");
 	for(i=1;i<KEY;i++)
 	{
 		printf("%d        %s        %d\n",i,s[i].name,s[i].standard);
	 }
 }
 
 void search(stud s[KEY])
 {
  printf("enter roll no to search:");
  int n;
  scanf("%d",&n);
  n=hash(n);
  printf("name is:%s\n",s[n].name);
  printf("standard is:%d",s[n].standard);
 }
 
int main()
{
   stud s[KEY];
	int i,r,n;
   for(i=1;i<=KEY;i++)
   {
   	s[i].standard=-1;
   	strcpy(s[i].name,str);
	}
	printf("how many records do you want to insert?");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("enter roll no:");
	scanf("%d",&r);
	insert(s,r);
	}
	printf("record inserted..!\n");
	printf("data is:\n");
	display(s);
	search(s);
}

// coded by yash pagar ...
