#include<stdio.h>
#include<string.h>
struct city 
{
	char cityname[30];
	int stdcode;
};
struct city c[100];
int readfile()
{
	FILE *fp;
	int i=0;
	int n=0;
	fp=fopen("cities.txt","r");
	while(!feof(fp))
	{
		fscanf(fp,"%s%d",c[i].cityname,&c[i].stdcode);
		n++;
		i++;
	}
	fclose(fp);
	return(n);
}
int linsearch(int n,char key[])
{
	int i=0;
	for(i=0;i<n;i++)
	{
		if(strcmp(c[i].cityname,key)==0)
		  return(i);
	}
	return(-1);
}
main()
{
	char key[20];
	int n,j;
	printf("enter the cityname to find:");
	gets(key);
	n=readfile();
	j=linsearch(n,key);
	if(j>=0)
	{
		printf("city found at %d position.\n",j+1);
		printf("its std code is:%d",c[j].stdcode);
	}
	else 
	printf("city not found...");
	return(0);
}
