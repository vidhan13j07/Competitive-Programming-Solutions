#include<stdio.h>
#include<math.h>
#define ll long long int
int main()
{
    int t,i;
    scanf("%d", &t);
    for(i=1;i<=t;i++)
    {
        ll n,s;
        scanf("%lld", &n);
        s=sqrt(n);
        if(s*s==n || (s-1)*(s-1)==n || (s+1)*(s+1)==n)
   			printf("Case %i: Yes\n", i);
  		else
   			printf("Case %i: No\n", i);
    }
}