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
const ll MAXN = 10000000000000000;
int ar[N];
ll dp[N];
string s[N];
int main()
{
	int n;
	scanf("%d",&n);
	f(i,0,n)
		scanf("%d",ar+i);
	f(i,0,n)
		cin>>s[i];
	vector< pair<string, pi > > vp;
	f(i,0,n) {
		vp.eb({s[i],{i,0}});
		reverse(s[i].begin(), s[i].end());
		if(s[i] != vp.back().fi)
			vp.eb({s[i],{i,ar[i]}});
	}
	sort(all(vp));
	f(i,0,n + 1)
		dp[i] = MAXN;
	int i = 0;
	dp[0] = 0;
	ll ans = 0;
	while(i < sc(vp)) {
		int j = vp[i].se.fi;
		//cout<<dp[j + 1]<<endl;
		dp[j + 1] = min(dp[j + 1], dp[j] + vp[i].se.se);
		//trace5(i, vp[i].fi, j, vp[i].se.se, dp[j + 1]);
		i++;
	}
	if(dp[n] == MAXN)
		cout<<"-1\n";
	else
		cout<<dp[n]<<endl;
    return 0;
}