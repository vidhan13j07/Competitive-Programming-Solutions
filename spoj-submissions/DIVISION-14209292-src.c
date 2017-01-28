#include<stdio.h>
#define m 1000000007
#define inv 333333336
#define ull unsigned long long int
ull pow(ull n)
{
	ull x=1,p=2;
    while(n)
    {
        if(n&1)
            x=(x*p)%m;
        p=(p*p)%m;
        n>>=1;
    }
    return x;
}
int main()
{
	ull n;
	while(scanf("%lld",&n)!=EOF)
	{
		if(n%2)	
			printf("%lld\n",((pow(n)+1)*inv)%m);
		else
			printf("%lld\n",((pow(n)+2)*inv)%m);
	}
	return 0;
}