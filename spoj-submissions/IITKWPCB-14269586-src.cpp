#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll gcd(ll a, ll b)
{
	if(b)
		return gcd(b,a%b);
	else
		return a;
}
int main()
{
	int t;
	cin>>t;
	ll a,b;
	while(t--)
	{
		cin>>a;
		b=a/2;
		if(a&1==0)
			b--;
		while(gcd(a,b)!=1)
			b--;
		cout<<b<<endl;
	}
	return 0;
}