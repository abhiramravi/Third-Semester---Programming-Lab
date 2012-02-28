#include<stdio.h>
#include<stdlib.h>
int lengthofarray(char []);
main()
{	
	int i=0,j=0,k=0,test=0;
	char a[100],b[100],c[100];
	do
	{
		a[i]=getchar();
		i++;
	}
	while(a[i-1]!='\n');
	a[i-1]='\0';	
	i=0;
	while(a[i]!='\0')
	{
		if((a[i]>=65&&a[i]<=90)||(a[i]>=97&&a[i]<=122)) {if(a[i]>=65&&a[i]<=90)a[i]=(char)(a[i]+32); b[j]=a[i];j++;}//printf("a[i] = %c\n",a[i]);
		i++;
	}
	b[j]='\0';
	//for( k=0;k<j;k++)
	//	{
	//		printf("%c\n",b[k]);
	//	}
	//printf("above =b, below =c\n");
	for( k=0;k<j;k++)
	{
		c[k]=b[j-k-1];
		//printf("%c\n",c[k]);
	}
	for(k=0;k<j;k++)
	{
		if(b[k]!=c[k]) {printf("%d\n",0);test=1;break;}
	}
	if(test==0) printf("%d\n",1);
	

}
int lengthofarray(char a[100])
{	
	int i;
	for(i=0;;i++)
	{
		if(a[i]=='\0') return i-1;
	}
}
