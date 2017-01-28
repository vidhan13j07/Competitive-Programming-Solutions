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
template <class T1, class T2, class Pred = std::less<T2> >
struct sort_pair_second {
    bool operator()(const std::pair<T1,T2>&left, const std::pair<T1,T2>&right) {
        Pred p;
        return p(left.second, right.second);
    }
};
using namespace std;
vector < pair<int,ll> > v;
int main() 
{
	std::ios_base::sync_with_stdio(false);cin.tie(0);
	int t,n,k;
	ll x,y,ma,mi;
	cin>>t;
	while(t--)
	{
		cin>>n;
		v.clear();
		int ar[n];
		f(i,0,n)
		{
			cin>>k;
			ma=0;
			mi=1e10;
			f(j,0,k)
			{
				cin>>x>>y;
				ma=max(ma,y);
				mi=min(mi,y);
			}
			v.eb(mk(i,ma-mi));
		}
		sort(v.begin(),v.end(),sort_pair_second<int,ll>());
		//f(i,0,n)
		//	cout<<v[i].first<<" "<<v[i].second<<endl;
		f(i,0,sc(v))
			ar[v[i].first]=i;
		f(i,0,n)
			cout<<ar[i]<<" ";
		cout<<endl;
	}
	return 0;
}
