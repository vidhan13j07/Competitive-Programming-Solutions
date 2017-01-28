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
vi v[N];
bool vis[N], mark[N];
int deg[N], a[N];
bool ok = 1;
void dfs(int i) {
	vis[i] = 1;
	for(int j: v[i]) {
		if(!vis[j]) {
			a[j] = 3 - a[i];
			dfs(j);
		}
		else {
			if(a[i] == a[j])
				ok = 0;
		}
	}
}
int main()
{
	int n, m;
	scanf("%d %d",&n, &m);
	memset(deg,0,sizeof(deg));
	memset(vis, 0 ,sizeof(vis));
	while(m--) {
		int x, y;
		scanf("%d %d",&x, &y);
		x--;y--;
		mark[x] = 1;
		mark[y] = 1;
		v[x].eb(y);
		v[y].eb(x);
		deg[x]++;
		deg[y]++;
	}
	f(i,0,n)
		if(!vis[i] and deg[i] > 0) {
			a[i] = 1;
			dfs(i);
		}
	if(!ok)
		printf("-1\n");
	else {
		int cnt = 0;
		f(i,0,n) {
			if(vis[i] and mark[i] and a[i] == 1)
				cnt++;
		}
		printf("%d\n",cnt);
		f(i,0,n)
			if(vis[i] and mark[i] and a[i] == 1)
				printf("%d ",i + 1);
		printf("\n");
		cnt = 0;
		f(i,0,n) {
			if(vis[i] and mark[i] and a[i] == 2)
				cnt++;
		}
		printf("%d\n",cnt);
		f(i,0,n)
			if(vis[i] and mark[i] and a[i] == 2)
				printf("%d ",i + 1);
		printf("\n");
		cnt = 0;
	}
    return 0;
}