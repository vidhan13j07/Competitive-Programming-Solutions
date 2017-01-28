#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define m 1000007
using namespace std;
ll cal(ll n)
{
	return ((n*(n+1))/2)%m;
}
int main() 
{
	ll t,n,ans;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=2*cal(n)+cal(n-1);
		cout<<ans%m<<endl;
	}
	return 0;
}