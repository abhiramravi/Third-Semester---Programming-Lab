#include<stdio.h>
int gcd(int, int);
main()
{
	int x, y;
	scanf("%d %d",&x,&y);
	if(y>x)
	printf("%d\n",gcd(x,y));
	else
	printf("%d\n",gcd(y,x));
}
int gcd(int x,int y)
{
	if(y%x==0) return x;
	else return gcd(y%x,x);
}
