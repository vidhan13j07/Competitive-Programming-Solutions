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
const int N = 25;
string s[N], ans, ss[N][N];
bool fl[N][N];
int x, y;
map< pi, char> mp;
map<char, pi > mpp;
inline bool valid(int i, int j, int n, int m) {
	if(i >= 0 and j >= 0 and i < n and j < m and s[i][j] == '.')
		return 1;
	return 0;
}
pair<int,int> traverse(int i, int j, int n, int m) {
	for(char ch: ans) {
		pi p = mpp[ch];
		if(valid(i + p.fi, j + p.se, n, m)) {
			i += p.fi;
			j += p.se;
		}
	}
	return {i,j};
} 
int main()
{
	ans = "";
	int n, m;
	mp[{-1,0}] = 'U';
	mp[{1,0}] = 'D';
	mp[{0,1}] = 'R';
	mp[{0,-1}] = 'L';
	mpp['U'] = {-1,0};
	mpp['L'] = {0,-1};
	mpp['R'] = {0,1};
	mpp['D'] = {1,0};
	scanf("%d %d",&n, &m);
	f(i,0,n) {
		cin>>s[i];
		f(j,0,m) {
			fl[i][j] = 0;
			ss[i][j] = "";
			if(s[i][j] == 'C') {
				x = i;
				y = j;
			}
			if(s[i][j] == '*')
				fl[i][j] = 1;
		}
	}
	fl[x][y] = 1;
	queue< pair< pi, pi > > q;
	q.push({{x,y},{x,y}});
	while(!q.empty()) {
		pi a, b;
		a = q.front().fi;
		b = q.front().se;
		q.pop();
		if(a != b) {
			int dx = b.fi - a.fi;
			int dy = b.se - a.se;
			ss[a.fi][a.se] = mp[{dx,dy}];
			for(char ch: ss[b.fi][b.se])
				ss[a.fi][a.se] += ch;
		}
		f(dx, -1, 2) f(dy, -1, 2) if(valid(a.fi + dx, a.se + dy, n, m) and !fl[a.fi + dx][a.se + dy]) {
			if(abs(dx) + abs(dy) != 1)
				continue;
			q.push(mk(mk(a.fi + dx, a.se + dy), a));
			fl[a.fi + dx][a.se + dy] = 1;
		}
	}
	f(i,0,n) {
		f(j,0,m) {
			if(s[i][j] == '.') {
				pi p = traverse(i, j, n, m);
				//trace5(i, j, p.fi, p.se, ans);
				//cout<<ss[i][j]<<endl;
				ans += ss[p.fi][p.se];
			}
		}
	}
	cout<<ans<<endl;
    return 0;
}
