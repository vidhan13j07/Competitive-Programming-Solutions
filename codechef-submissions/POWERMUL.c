#include<stdio.h>
#include<math.h>
long long int calc(int);
long long int calc(int n)
{
	unsigned long long int f=1;
	int i;
	for(i=1;i<=n;i++)
		f*=pow(i,i);
	return f;
}
int main()
{
	int t,N,Q,r,i;
	unsigned long long int M,f,k;
	scanf("%d",&t);
	for(;t>0;t--)
	{
		scanf("%d %lld %d",&N,&M,&Q);
		for(;Q>0;Q--)
		{
			scanf("%d",&r);
			f=calc(N)/(calc(r)*calc(N-r));
			k=f%M;
			printf("%lld\n",k);
		}
	}
	return 0;
}
