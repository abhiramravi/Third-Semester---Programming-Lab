#include<stdio.h>
main()
{
	float a;
	int b;
	char c;
	char d [100];
	int e;
	
	scanf("%f %d %c %s %x",&a,&b,&c,d,&e);
	printf("%x\n%s\n%c\n%d\n%4.2f\n",e,d,c,b,a);
	
}
