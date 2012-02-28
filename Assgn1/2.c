#include<stdio.h>
#include<math.h>
main()
{
	int pot=1,n,mindiff,power=0;
	scanf("%d",&n);
	mindiff=abs(n-pot);
	while(1)
	{
		pot*=3;
		power++;
		if(abs(n-pot)<mindiff) mindiff=abs(n-pot);
		else
		{
			if((pot+(pot/3))/2==n) printf("%d\n",power);
			else printf("%d\n",power-1);
			break;
		}
	}
}
