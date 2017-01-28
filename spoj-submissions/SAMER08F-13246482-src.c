#include<stdio.h>
int main()
{
	int n;
	long long int ans;
	while(1)
	{
		scanf("%d",&n);	
		if(n==0)
			break;
		ans=(n*(n+1)*(2*n+1)/6);
		printf("%lld\n",ans);
	}
	return 0;
}
