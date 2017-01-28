#include<bits/stdc++.h>
#define sc(v) v.size()
#define eb push_back
#define pb pop_back
#define f(i,a,b) for(int i=a;i<b;i++)
#define TC() int t;cin>>t;while(t--)
#define all(x) x.begin(),x.end()
#define mk make_pair
#define fi first
#define se second
#define trace2(x, y)             cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

map< pair<ll,ll>, ll > mp;
inline ll lca(ll i,ll j){
	while(i != j) {
		if(i > j)
			i = i/2;
		else
			j = j/2;
	}
	return i;
}
int main()
{
	int q;
	ll u, v, w;
	scanf("%d",&q);
	while(q--) {
		int ch;
		scanf("%d %lld %lld",&ch, &u, &v);
		ll lc = lca(u, v);
		if(ch == 1) {
			scanf("%lld",&w);
			while(u != lc) {
				ll temp = u/2;
				mp[ {u,temp} ] += w;
				mp[ {temp,u} ] += w;
				u = temp;
			}
			while(v != lc) {
				ll temp = v/2;
				mp[ {v,temp} ] += w;
				mp[ {temp,v} ] += w;
				v = temp;
			}
		}
		else {
			ll ans = 0;
			while(u != lc) {
				ll tmp = u/2;
				if(mp.find( {u,tmp} ) != mp.end())
					ans += mp[ {u,tmp} ];
				u = tmp;
			}
			while(v != lc) {
				ll temp = v/2;
				if(mp.find( {v,temp} ) != mp.end())
					ans += mp[ {v,temp} ];
				v = temp;
			}
			printf("%lld\n",ans);
		}
	}
    return 0;
}