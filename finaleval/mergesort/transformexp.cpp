#include <assert.h>
#include <ctype.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <memory.h>

using namespace std;

const int MAX_SIZE = 20000;
static char input[MAX_SIZE];
struct Scanner
{
	Scanner()
	{
		int sz = fread(input, 1, sizeof(input), stdin);
		curPos = input;
	}
	int nextInt()
	{
		int gap = input + MAX_SIZE - curPos;
		if (gap < 100)
		{
			memcpy(input, curPos, gap);
			fread(input + gap, 1, sizeof(input) - gap, stdin);
			curPos = input;
		}
	 
		while (*curPos < '0') curPos++;
		int res = 0;
		 
		while (*curPos >= '0')
		{
			res = res * 10 + (*curPos) - '0';
			curPos++;	
		}
		return res;
	}
	char* curPos;
};
 
int main(int argc, char* argv[])
{
#ifndef ONLINE_JUDGE
 
freopen("test.in", "r", stdin);
#endif
 
Scanner sc;
int t = sc.nextInt();int n,i,j;
while(t--)
{
	//scanf("%d",&n);
	n=sc.nextInt();
	int ar[n][n]
	;
	for(i=0;i<n;i++)
	for(j=0;j<=i;j++)
	//scanf("%d",&ar[i][j]);
	ar[i][j]=sc.nextInt();
	
	for(i=n-1;i>0;i--)
	for(j=0;j<i;j++)
	ar[i-1][j]+=ar[i][j]>ar[i][j+1]?ar[i][j]:ar[i][j+1];
	
	printf("%d",ar[0][0]);
	printf("\n");
	}
	return 0;
}
 
