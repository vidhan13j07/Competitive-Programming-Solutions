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
ll power(ll b)
{
	ll x=1,a=2;
	while(b)
	{
		if(b&1)
			x*=a;
		a*=a;
		b>>=1;
	}
	return x;
}
int main()
{
	int y,ans;
	ll s,p;
	cin>>y>>p;
	s=power(y);
	ans=1;
	while(y)
	{
		s>>=1;
		if(p<s)
			ans=ans^1;
		else
			p=p-s;
		y--;
	}
	if(ans)
		cout<<"red"<<endl;
	else
		cout<<"blue"<<endl;
	return 0;
}