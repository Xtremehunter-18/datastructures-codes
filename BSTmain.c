#include<stdio.h>
#include"BSToperations.h"
main()
{
   TNODE *root;
   int ch,c,d,e,k,m,n,s,key,oldkey,newkey;
   init(&root); //for initialising the tree..
   root=createbst(root); //createbst will make a binary search tree..
   do{
   printf("\nwhich operation do you want on tree?\n");
   printf("1.traverse preorder\n");
   printf("2.traverse inorder\n");
   printf("3.traverse postorder\n");
   printf("4.traverse level order\n");
   printf("5.insert a key\n");
   printf("6.search a key\n");
   printf("7.find leafnodes\n");
   printf("8.find nonleafnodes\n");
   printf("9.find totalnodes\n");
   printf("10.replace a key\n");
   printf("11.invert tree\n");
   printf("12.find max element:\n");
   printf("13.delete a key\n");
   printf("14.find min element:\n");
   printf("15.find sum of all elements:\n");
   printf("16.exit\n");
   printf("enter a choice:");
   scanf("%d",&ch);
   switch(ch)
   {
   	case 1:  printf("preorder traversal of tree is: ");
   	         recpreorder(root);
   	         break;
      case 2:  printf("inorder traversal of tree is: ");
   	         recinorder(root);
   	         break;
      case 3:  printf("postorder traversal of tree is: ");
   	         recpostorder(root);
   	         break;
      case 4:  printf("level order traversal of tree is: ");
   	         levelorder(root);
   	         break;
      case 5:  printf("enter a key to insert: ");
               scanf("%d",&k);
   	         root=insertkey(root,k);
   	         printf("key inserted..\n");
   	         break;
      case 6:  printf("enter a key to search: ");
               scanf("%d",&k);
               searchkey(root,k);
   	         break;
      case 7:  c=leafnodes(root);
               printf("total leafnodes are: %d",c);
               break;
      case 8:  d=nonleafnodes(root);
               printf("total nonleafnodes are: %d",d);
               break;
      case 9:  e=totalnodes(root);
               printf("total nodes are: %d",e);
               break;
      case 10: printf("enter old key of tree and new key to replace :");
               scanf("%d%d",&oldkey,&newkey);
               root=replace(root,oldkey,newkey);
               printf("key replaced\n");
               break;
      case 11: root=inverttree(root);
               printf("tree inverted..\n");
               break;
      case 12: m=findmax(root);
               printf("maximum element in tree is:%d\n",m);
               break;
      case 13: printf("enter a key to delete:");
               scanf("%d",&key);
               root=deletekey(root,key);
               printf("key deleted...\n");
               break;
      case 14: n=findmin(root);
               printf("minimum element in tree is:%d\n",n);
               break;
      case 15: s=sumofnodes(root);
               printf("sum of all element in tree is:%d\n",s);
               break;
      case 16: printf("process exited...\n");
               break;
	}
}while (ch!=16);
   return(0);
}

// coded by Xtremehunter...

