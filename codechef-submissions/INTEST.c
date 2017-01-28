#include<stdio.h>
int main()
{
	long n,k,i,num; 
	int count=0;
	scanf("%ld %ld",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%ld",&num);
			if(num%k==0)
				count++;
	}
	printf("%d \n",count);
	return 0;
}
