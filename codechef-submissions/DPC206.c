#include<stdio.h>
long Reverse(long);
int main()
{
	int i,t,count;
	long N,rev;
	scanf("%d",&t);
	if(t>=1 && t<=100)
	{
		for(i=1;i<=t;i++)
		{
			count=0;
			scanf("%ld",&N);
			while(1)
			{
				rev=Reverse(N);
				count++;
				if(N==rev)
					break;
				else
					N=N+rev;
				if(count==1000)
					break;
			}
			printf("%d %ld \n",count-1,N);
		}
	}
	return 0;
}
long Reverse(long N)
{
	int i,dig=0,q=1,temp;
	long rev=0;
	temp=N;
	while(temp>0)
	{
		temp=temp/10;
		dig++;
	}
	for(i=1;i<dig;i++)
		q=q*10;
	while(N>0)
	{
		rev=rev+((N%10)*q);
		q=q/10;
		N=N/10;
	}
	return rev;
}
