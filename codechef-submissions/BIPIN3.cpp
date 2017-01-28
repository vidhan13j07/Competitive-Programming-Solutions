#include<bits/stdc++.h>
#define sc(v) v.size()
#define eb push_back
#define pb pop_back
#define f(i,a,b) for(int i=a;i<b;i++)
#define TC() int t;scanf("%d",&t);while(t--)
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
const ll mod = 1e9 + 7;
ll power(ll a,int b)
{
	ll x = 1;
	while(b)
	{
		if(b&1)
			x *= a;
		a *= a;
		if(x >= mod)
			x %= mod;
		if(a >= mod)
			a %= mod;
		b >>= 1;
	}
	return x;
}
int main()
{
	ll ans;
	int n,k;
	TC()
	{
		scanf("%d %d",&n,&k);
		ans = power(k - 1, n - 1);
		ans *= k;
		if(ans >= mod)
			ans %= mod;
		printf("%lld\n",ans);
	}
    return 0;
}
