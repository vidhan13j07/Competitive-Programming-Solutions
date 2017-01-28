#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define sc(v) v.size()
#define eb emplace_back
#define pb pop_back
#define stl(a,it) for(auto it: a)
#define what_is(x) cerr << #x << " is " << x << endl
#define f(i,a,b) for(int i=a;i<b;i++)
#define mk make_pair
using namespace std;
int main() 
{
	std::ios_base::sync_with_stdio(false);cin.tie(0);
	int t,j;
	ll a,b;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>a>>b;
		cout<<"Scenario #"<<i<<":"<<endl;
		int ar[b];
		for(j=0;j<b;j++)
			cin>>ar[j];
		sort(ar,ar+b);
		for(j=b-1;j>=0 and a>0;j--)
			a-=ar[j];
		if(a<=0)
			cout<<b-j-1<<endl;
		else
			cout<<"impossible"<<endl;
		cout<<endl;
	}
	return 0;
}