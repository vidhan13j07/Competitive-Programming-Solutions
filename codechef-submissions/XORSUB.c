#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int a,a1,k,n;
void findSubsets(int[],int);
void findSubsets(int value[n], int i) 
{
        int j;
        if (i < 0)
                return;
	a1=0;
        for (j = 0; j < n; j++)
                if (i & (1 << j)) 
			a1=a1^value[j];
	a1=a1^k;
	if(a1>a)
		a=a1;
        findSubsets(value,i-1);
        return;
}
int main() 
{
        int i,t,count;
        scanf("%d", &t);
	for(;t>0;t--)
	{
		a=0;
		scanf("%d %d",&n,&k);
       		int ar[n];
        	for (i = 0; i < n; i++) 
                	scanf("%d",&ar[i]);
        	count = pow(2, n);
        	findSubsets(ar,count-1);
		printf("%d\n",a);
	}
        return 0;
}
