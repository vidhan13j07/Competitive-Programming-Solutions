#include<stdio.h>
int main()
{
	int t,n,p,i,k;
	long long int s;
	scanf("%d",&t);
	for(;t>0;t--)
	{
		scanf("%d",&n);
		int ar[n];
		for(i=0;i<n;i++)
			scanf("%d",&ar[i]);
		s=0;
		scanf("%d",&k);
		for(;k>0;k--)
		{
			scanf("%d",&p);
			p--;
			s+=ar[p];
		}
		printf("%lld\n",s);
	}
	return 0;
}
