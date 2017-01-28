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
int main()
{
	int ans,t;
	cin>>t;
	ll y,p;
	while(t--)
	{
		cin>>y>>p;
		ans=1;
		while(p>1)
		{
			if(p%2==0)
				ans=ans^1;
			p=(p+1)/2;
		}
		if(ans)
			cout<<"Male"<<endl;
		else
			cout<<"Female"<<endl;
	}
	return 0;
}