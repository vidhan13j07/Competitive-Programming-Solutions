#include<stdio.h>
long long int pro(long long int,long long int);
int main()
{
	long long int t,n,k,ans;
	scanf("%lld",&t);
	for(;t>0;t--)
	{
		scanf("%lld %lld",&n,&k);
		ans=(pro(n-3,n)-pro(k-3,k))/6;
		printf("%lld\n",ans);
	}
	return 0;
}
long long int pro(long long int l,long long int h)
{
	long long int fac=1;
	for(l=l+1;l<=h;l++)
		fac*=l;
	return fac;
}
