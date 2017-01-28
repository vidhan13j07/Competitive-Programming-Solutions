#include<stdio.h>
int main()
{
	long long int t,n,k;
	scanf("%lld",&t);
	while(t--)
	  {
	  	scanf("%lld%lld",&n,&k);
	  	if(n>=k&&k!=0)
	  	   printf("%lld %lld\n",n/k,n%k);
	  	else
	  	  printf("0 %lld\n",n);
	  }
	  return 0;
	  
}
