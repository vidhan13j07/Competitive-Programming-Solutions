#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll x[2],z;
ll gcd(ll a,ll b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
	ll g=gcd(a,b);
	return (a*b)/g;
}
ll cal(ll a,ll b)
{
	z=lcm(a,b);
	x[0]=z/a-1;
	x[1]=z/b-1;
	//cout<<"lcm="<<z<<" no of a="<<x[0]<<" no of b="<<x[1]<<"\n";
}
int main() 
{
	int t,i,j;
	ll a,b,n,rem,y,ans,k;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>n;
		//cout<<a<<" "<<b<<" "<<n<<"\n";
		cal(a,b);
		k=x[0]+x[1]+1;
		y=n/k;
		rem=n%k;
		ans=y*z;
		//cout<<"k="<<k<<" y="<<y<<" rem="<<rem<<" ans="<<ans<<"\n";
		i=1;j=1;
		while(rem>1)
		{
			if(a*i<b*j)
				i++;
			else
				j++;
			rem--;
		}
		if(rem==1)
		{
			if(a*i<b*j)
				ans+=a*i;
			else
				ans+=b*j;
		}
		cout<<ans<<endl;
	}
	return 0;
}