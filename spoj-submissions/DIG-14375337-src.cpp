#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define sc(v) v.size()
#define eb emplace_back
#define pb pop_back
#define stl(a,it) for(auto it: a)
#define what_is(x) cerr << #x << " is " << x << endl
#define f(i,a,b) for(int i=a;i<b;i++)
#define contain(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define mk make_pair
using namespace std;
const ll m=1000000007;
ll multiply(ll a,ll b)
{
	return (a*b)%m;
}
ll power(ll a,ll b)
{
	ll x=1;
	while(b)
	{
		if(b&1)
			x=(x*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return x;
}
int main() 
{
	std::ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,s,inv;
	int t;
	inv=power(24,m-2);
	//cout<<inv<<endl;
	cin>>t;
	while(t--)
	{
		s=1;
		cin>>n;
		//cout<<"start"<<endl;
		if(n>=4)
		{
			f(i,0,4)
				s=multiply(s,n-i);
			s=multiply(s,inv);
		}
		else
			s=0;
		cout<<s<<endl;
	}
	return 0;
}