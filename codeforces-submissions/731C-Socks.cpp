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
int ar[N], color[N];
vi v[N], vv[N];
bool vis[N];
map<int,int> mp[N];
void dfs(int i, int c) {
	vis[i] = 1;
	color[i] = c;
	for(auto it: v[i])
		if(!vis[it])
			dfs(it, c);
}
int main()
{
	int n, m, k;
	scanf("%d %d %d",&n, &m, &k);
	f(i,0,n)
		scanf("%d", ar+i);
	while(m--) {
		int l, r;
		scanf("%d %d",&l, &r);
		l--;r--;
		v[l].eb(r);
		v[r].eb(l);
	}
	memset(vis, 0, sizeof vis);
	int c = 0;
	f(i,0,n) 
		if(!vis[i]) {
			dfs(i, c);
			c++;
		}
	f(i,0,n)
		vv[color[i]].eb(i);
	f(i,0,n)
		mp[color[i]][ar[i]]++;
	int ans = 0;
	f(i,0,c) {
		int ct = 0;
		for(auto it: mp[i])
			ct = max(ct, it.se);
		ans += vv[i].size() - ct;
	}
	printf("%d\n", ans);
    return 0;
}