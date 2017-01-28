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
const int LN = 20;
int pa[LN][N], le[N], rt[N], depth[N], tim, BIT[N], idx[N];
pi p[N];
vi v[N];

void dfs(int i, int parent, int d) {
	le[i] = ++tim;
	depth[i] = d;
	pa[0][i] = parent;
	f(j,1,LN)
		pa[j][i] = pa[j - 1][pa[j - 1][i]];
	for(auto it: v[i])
		if(depth[it] == -1)
			dfs(it, i, d + 1);
	rt[i] = tim;
}
int lca(int a, int b) {
	if(depth[a] > depth[b])
		swap(a, b);
	for(int i = LN - 1;i >= 0;i--)
		if(depth[b] - (1 << i) >= depth[a])
			b = pa[i][b];
	if(a == b)
		return a;
	for(int i = LN - 1;i >= 0;i--)
		if(pa[i][b] != -1 and pa[i][b] != pa[i][a]) {
			a = pa[i][a];
			b = pa[i][b];
		}
	return pa[0][a];
}
inline void update(int idx, int a) {
	while(idx < N) {
		BIT[idx] += a;
		idx += (idx&(-idx));
	}
}
inline int query(int x) {
	int ret = 0;
	while(x) {
		ret += BIT[x];
		x -= (x&-x);
	}
	return ret;
}
int main()
{
	int n;
	scanf("%d",&n);
	f(i,1,n) {
		scanf("%d %d",&p[i].fi, &p[i].se);
		p[i].fi--;
		p[i].se--;
		depth[i] = -1;
		v[p[i].fi].eb(p[i].se);
		v[p[i].se].eb(p[i].fi);
	}
	tim = 0;
	dfs(0, -1, 0);
	memset(BIT, 0, sizeof BIT);
	int q;
	scanf("%d",&q);
	while(q--) {
		int a, b;
		scanf("%d %d",&a, &b);
		a--;b--;
		update(le[a], 1);
		update(le[b], 1);
		update(le[lca(a, b)], -2);
	}
	f(i,1,n) {
		if(depth[p[i].fi] < depth[p[i].se])
			swap(p[i].fi, p[i].se);
		printf("%d ", query(rt[p[i].fi]) - query(le[p[i].fi] - 1));
	}
    return 0;
}