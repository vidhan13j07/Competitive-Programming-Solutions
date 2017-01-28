#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define sc(v) v.size()
#define eb push_back
#define pb pop_back
#define stl(a,it) for(auto it: a)
#define what_is(x) cerr << #x << " is " << x << endl
#define f(i,a,b) for(int i=a;i<b;i++)
#define contain(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define mk make_pair
#define max(a,b,c,d) max(a,max(b,max(c,d)))
using namespace std;
int main()
{
	int t,n,k,s,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		int ar[n];
		s=0;
		m=100001;
		f(i,0,n)
		{
			cin>>ar[i];
			m=min(m,abs(ar[i]));
		}
		sort(ar,ar+n);
		f(i,0,n)
			if(k and ar[i]<0)
			{
				s+=abs(ar[i]);
				k--;
			}
			else
				s+=ar[i];
		if(k)
		{
			if(k&1)
				s-=2*m;
		}
		cout<<s<<endl;
	}
	return 0;
}