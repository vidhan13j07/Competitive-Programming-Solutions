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
int main() 
{
	std::ios_base::sync_with_stdio(false);cin.tie(0);
	int t,n,mi;
	cin>>t;
	vector < pair<int,int> > v;
	while(t--)
	{
		cin>>n;
		v.clear();
		int ar[n+1][n+1];
		f(i,1,n+1)
			f(j,1,n+1)
				cin>>ar[i][j];
		f(i,1,n+1)
			f(j,i+1,n+1)
			{
				mi=210;
				f(k,1,n+1)
				{
					if(k==i or k==j)
						continue;
					mi=min(mi,ar[i][k]+ar[k][j]);
				}
				if(ar[i][j]!=mi)
					v.eb(mk(i,j));
			}
		f(i,0,sc(v))
			cout<<v[i].first<<" "<<v[i].second<<endl;
	}
	return 0;
}