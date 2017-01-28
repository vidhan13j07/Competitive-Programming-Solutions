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

const int N = 55;
string s[N];
bool vis[N][N];
set< pair< int, pi > > st;
int main()
{
	f(i,0,N) f(j,0,N) vis[i][j] = 0;
	int n, m, k;
	scanf("%d %d %d",&n, &m, &k);
	f(i,0,n)
		cin>>s[i];
	f(i,0,n) f(j,0,m) {
		if(vis[i][j] or s[i][j] == '*') {
			vis[i][j] = 1;
			continue;
		}
		vis[i][j] = 1;
		bool fl = 1;
		queue< pair<int,int> > q;
		q.push( {i,j} );
		int c = 0;
		while(!q.empty()) {
			auto p = q.front();
			q.pop();
			c++;
			if(p.fi + 1 == n or p.fi == 0 or p.se == 0 or p.se + 1 == m)
				fl = 0;
			if(p.se + 1 < m and !vis[p.fi][p.se + 1] and s[p.fi][p.se + 1] == '.') {
				vis[p.fi][p.se + 1] = 1;
				q.push( {p.fi, p.se + 1} );
			}
			if(p.fi + 1 < n and !vis[p.fi + 1][p.se] and s[p.fi + 1][p.se] == '.') {
				vis[p.fi + 1][p.se] = 1;
				q.push( {p.fi + 1, p.se} );
			}
			if(p.fi >= 1 and !vis[p.fi - 1][p.se] and s[p.fi - 1][p.se] == '.') {
				vis[p.fi - 1][p.se] = 1;
				q.push( {p.fi - 1, p.se} );
			}
			if(p.se >= 1 and !vis[p.fi][p.se - 1] and s[p.fi][p.se - 1] == '.') {
				vis[p.fi][p.se - 1] = 1;
				q.push( {p.fi, p.se - 1} );
			}
		}
		if(fl)
			st.insert( {c, {i,j} } );
	}
	/*for(auto it: st)
		trace3(it.fi, it.se.fi, it.se.se);*/
	int kk = (int)(st.size()), ans = 0;
	while(kk > k) {
		auto it = st.begin();
		pi x = (*it).se;
		ans += (*it).fi;
		st.erase(it);
		queue< pair<int,int> > q;
		q.push( {x.fi, x.se} );
		s[x.fi][x.se] = '*';
		while(!q.empty()) {
			pi p = q.front();
			q.pop();
			if(p.fi + 1 < n and s[p.fi + 1][p.se] == '.') {
				q.push( {p.fi + 1, p.se} );
				s[p.fi + 1][p.se] = '*';
			}
			if(p.se + 1 < m and s[p.fi][p.se + 1] == '.') {
				q.push( {p.fi, p.se + 1} );
				s[p.fi][p.se + 1] = '*';
			}
			if(p.fi > 0 and s[p.fi - 1][p.se] == '.') {
				q.push( {p.fi - 1, p.se} );
				s[p.fi - 1][p.se] = '*';
			}
			if(p.se > 0 and s[p.fi][p.se - 1] == '.') {
				q.push( {p.fi, p.se - 1} );
				s[p.fi][p.se - 1] = '*';
			}
		}
		kk--;
	}
	printf("%d\n", ans);
	f(i,0,n)
		cout<<s[i]<<endl;
    return 0;
}