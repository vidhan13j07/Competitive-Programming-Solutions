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

int main()
{
	int n, h, k;
	scanf("%d %d %d",&n, &h, &k);
	ll ans = 0,tot = 0,x;
	f(i,0,n) {
		scanf("%lld",&x);
		if(tot + x <= h) {
			ll xx = (tot + x)/k;
			tot = -1*(xx*k - tot - x);
			ans += (ll)(xx);
		}
		else {
			ll kk = h - x;
			tot -= kk;
			ll xx = tot/k;
			tot = -1*(xx*k - tot);
			ans += xx;
			//trace4(kk,xx,tot,ans);
			if(kk >= (k - tot))
			{
				ans++;
				tot = 0;
				kk -= (k - tot);
				x += kk;
			}
			else
			{
				tot += kk;
				xx = tot / k;
				tot = -1*(k*xx - tot);
				if(tot > 0)
					xx++;
				tot = 0;
				ans += (ll)(xx);
				//trace4("C",xx,tot,ans);
			}
			xx = x/k;
			tot = -1*(xx*k - x);
			ans += (ll)(xx);
		}
		//trace4(i,x,tot,ans);
	}
	if(tot > 0) {
		ll xx = tot/k;
		tot = tot - k*xx;
		if(tot > 0)
			xx++;
		//trace2(tot,xx);
		ans += (ll)(xx);
	}
	printf("%lld\n", ans);
    return 0;
}