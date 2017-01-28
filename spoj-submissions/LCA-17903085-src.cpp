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

const int N = 1e3 + 5;
const int LN = 11;
vi v[N];
bool vis[N];
int depth[N], p[LN][N];
void dfs(int i, int parent, int d) {
	vis[i] = 1;
	depth[i] = d;
	p[0][i] = parent;
	for(auto it: v[i])
		if(!vis[it])
			dfs(it, i, d + 1);
}
int lca(int a, int b) {
	if(depth[a] > depth[b])
		swap(a, b);
	for(int i = LN - 1;i >= 0;i--)
		if(depth[b] - (1<<i) >= depth[a])
			b = p[i][b];
	if(a == b)
		return a;
	for(int i = LN - 1;i >= 0;i--)
		if(p[i][a] != -1 and p[i][a] != p[i][b]) {
			a = p[i][a];
			b = p[i][b];
		}
	return p[0][a];
}
int main()
{
	int tc = 1;
	TC() {
		int n;
		printf("Case %d:\n", tc++);
		scanf("%d",&n);
		f(i,0,N) {
			depth[i] = 0;
			f(j,0,LN)
				p[j][i] = -1;
			vis[i] = 0;
			v[i].clear();
		}
		f(i,0,n) {
			int k;
			scanf("%d",&k);
			while(k--) {
				int x;
				scanf("%d",&x);
				x--;
				v[i].eb(x);
				v[x].eb(i);
			}
		}
		dfs(0, -1, 0);
		f(i,1,LN)
			f(j,0,n)
				if(p[i - 1][j] != -1)
					p[i][j] = p[i - 1][p[i - 1][j]];
		int q;
		scanf("%d",&q);
		while(q--) {
			int u, v;
			scanf("%d %d",&u, &v);
			u--;v--;
			printf("%d\n", (lca(u, v) + 1));
		}
	}
    return 0;
}