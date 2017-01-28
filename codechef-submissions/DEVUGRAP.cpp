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
	std::ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,k,g,s,temp;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		s=0;
		f(i,0,n)
		{
			cin>>temp;
			g=temp%k;
			if(temp<k)
				s+=k-temp;
			else
				s+=min(g,k-g);
		}
		cout<<s<<endl;
	}
	return 0;
}
