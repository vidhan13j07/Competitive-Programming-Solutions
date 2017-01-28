#include <iostream>
    #include<bits/stdc++.h>
    #define ll long long int
    #define li long int
    #define min(a,b) a<b?a:b
    #define max(a,b) a>b?a:b
    #define mod 1000000007
    using namespace std;
    li dp[24][10000000];
    void process(ll n)
    {
        ll i,j;
        for(j=1;(1<<j)<=n;j++)
        {
            for(i=0;i+(1<<j)-1<n;i++)
            {
                if(dp[j-1][i]<=dp[j-1][i+(1<<(j-1))])
                    dp[j][i]=dp[j-1][i];
                else
                    dp[j][i]=dp[j-1][i+(1<<(j-1))];
            }
        }
    }
    ll solve(ll i,ll j)
    {
    	i=min(i,j);
    	j=max(i,j);
        ll k=31-__builtin_clz(j-i+1);
        if(dp[k][i]<=dp[k][j-(1<<k)+1])
            return dp[k][i];
        else
            return dp[k][j-(1<<k)+1];
    }
    int main() 
    {
    	ll temp,i,n,k,q,a,b,c,d,e,f,r,s,t,m,l1,la,lc,lm,da,dc,dm,d1,sum=0,pro=1;
    	scanf("%lld %lld %lld",&n,&k,&q);
    	scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %ld",&a,&b,&c,&d,&e,&f,&r,&s,&t,&m,&dp[0][0]);
    	scanf("%lld %lld %lld %lld %lld %lld %lld %lld",&l1,&la,&lc,&lm,&d1,&da,&dc,&dm);
    	a=a%m;
    	b=b%m;
    	c=c%m;
    	d=d%m;
    	e=e%m;
    	f=f%m;
    	temp=t;
    	for(i=1;i<n;i++)
    	{
    		temp=(temp*t)%s;
    		if(temp<=r)
    			dp[0][i]=(a*dp[0][i-1]*dp[0][i-1]+b*dp[0][i-1]+c)%m;
    		else
    			dp[0][i]=(d*dp[0][i-1]*dp[0][i-1]+e*dp[0][i-1]+f)%m;
    	}
    	process(n);
    	while(q--)
    	{
    		l1=((la*l1)+lc)%lm;
    		d1=((da*d1)+dc)%dm;
    		r=min(l1+k+d1,n);
    		temp=solve(l1,r-1);
    		sum+=temp;
    		pro=(pro*temp)%mod;
    	}
    	printf("%lld\n%lld\n",sum,pro);
    	return 0;
    }
