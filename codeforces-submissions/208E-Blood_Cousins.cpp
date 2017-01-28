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
vi v[N], level[N];
int depth[N], start[N], finish[N], pa[LN][N], lvl;
void dfs(int i, int d, int parent) {
	start[i] = ++lvl;
	depth[i] = d;
	level[d].eb(lvl);
	pa[0][i] = parent;
	for(auto it: v[i])
		if(depth[it] == -1)
			dfs(it, d + 1, i);
	finish[i] = lvl;
}
int main()
{
	int n;
	scanf("%d",&n);
	f(i,0,n) {
		int tmp;
		scanf("%d",&tmp);
		tmp--;
		v[tmp].eb(i);
		v[i].eb(tmp);
		f(j,0,LN)
			pa[j][i] = -1;
		depth[i] = -1;
	}
	lvl = 0;
	f(i,0,n)
		if(depth[i] == -1)
			dfs(i, 0, -1);
	f(i,1,LN)
		f(j,0,n)
			if(pa[i - 1][j] != -1)
				pa[i][j] = pa[i - 1][pa[i - 1][j]];
	f(i,0,n)
		sort(all(level[i]));
	/*f(i,0,n)
		trace4(i, start[i], depth[i], finish[i]);
	f(i,0,n) {
		printf("%d: ", i);
		for(auto it: level[i])
			printf("%d ", it);
		printf("\n");
	}*/
	int q;
	scanf("%d",&q);
	while(q--) {
		int u, vv;
		scanf("%d %d",&u, &vv);
		u--;
		if(depth[u] < vv) {
			printf("0 ");
			continue;
		}
		int tmp = depth[u];
		for(int i = LN - 1;i >= 0;i--)
			if(vv&(1<<i))
				u = pa[i][u];
		//trace3(u, tmp, vv);
		int x = upper_bound(all(level[tmp]), finish[u]) - lower_bound(all(level[tmp]), start[u]);
		printf("%d ", x - 1);
	}
    return 0;
}