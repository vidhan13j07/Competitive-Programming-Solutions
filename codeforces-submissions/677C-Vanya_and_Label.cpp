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

const int N = 64;
const ll mod = 1e9 + 7;
ll dp[N];
int main()
{
	f(i,0,N) 
		dp[i] = 0;
	f(i,0,N)
		f(j,0,N)
			f(k,0,N)
				if((j&k) == i)
					dp[i]++;
	ll ans = 1;
	string s;
	cin>>s;
	f(i,0,sc(s)) {
		int x;
		char ch = s[i];
		if (ch >= '0' and ch <= '9')
			x = ch - '0';
		else if (ch >= 'A' and ch <= 'Z')
			x = ch - 'A' + 10;
		else if (ch >= 'a' and  ch <= 'z')
			x = ch - 'a' + 36;
		else if (ch == '-')
			x = 62;
		else if(ch == '_')
			x = 63;
		ans *= dp[x];
		if(ans >= mod)
			ans %= mod;
	}
	printf("%lld\n", ans);
    return 0;
}