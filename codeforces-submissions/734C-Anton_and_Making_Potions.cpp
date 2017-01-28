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

const int N = 2e5 + 5;
pll a[N];
ll c[N], d[N];
int main()
{
	int m, k;
	ll n, x, s;
	scanf("%lld %d %d %lld %lld",&n, &m, &k, &x, &s);
	f(i,0,m)
		scanf("%lld", &a[i].se);
	f(i,0,m)
		scanf("%lld", &a[i].fi);
	f(i,0,k)
		scanf("%lld", &c[i]);
	f(i,0,k)
		scanf("%lld", &d[i]);
	ll ans = n*x;
	f(i,0,k) 
		if(d[i] <= s) {
			if(n <= c[i]) {
				ans = 0;
				continue;
			}
			ans = min(ans, (n - c[i])*x);
		}
	f(i,0,m)
		if(a[i].fi <= s)
			ans = min(ans, a[i].se*n);
	f(i,1,k)
		c[i] = max(c[i], c[i - 1]);
	sort(a, a + m);
	f(i,0,m) {
		ll req = s - a[i].fi;
		if(req < 0)
			continue;
		int kk = upper_bound(d, d + k, req) - d;
		kk--;
		if(kk < 0)
			continue;
		ll ma = c[kk];
		if(ma >= n) {
			ans = 0;
			continue;
		}
		ll cc = (n - ma)*a[i].se;
		ans = min(ans, cc);
	}
	printf("%lld\n", ans);
    return 0;
}
