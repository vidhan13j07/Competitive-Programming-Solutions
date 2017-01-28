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

const int N = 1e5 + 5;
bool r[N], c[N];
int main()
{
	int n, m;
	scanf("%d %d",&n, &m);
	ll ans = (ll)(n), rr = n, cc = n;
	ans *= ans;
	f(i,0,N) {
		r[i] = 0;
		c[i] = 0;
	}
	while(m--) {
		int a, b;
		scanf("%d %d",&a, &b);
		a--;b--;
		if(!c[a]) {
			ans -= rr;
			c[a] = 1;
			cc--;
		}
		if(!r[b]) {
			r[b] = 1;
			ans -= cc;
			rr--;
		}
		printf("%lld ",ans);
	}
    return 0;
}