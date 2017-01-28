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

const int N = 105;
string ar[N];
bool vis[N][N];
void dfs(int i, int j, int r, int c) {
	f(dx,-1,2)
		f(dy,-1,2) {
			if(dx == 0 and dy == 0)
				continue;
			if(abs(dx) + abs(dy) != 1)
				continue;
			if(i + dx < 0 or i + dx >= r or j + dy < 0 or j + dy >= c)
				continue;
			if(ar[i + dx][j + dy] == '.' or vis[i + dx][j + dy])
				continue;
			vis[i + dx][j + dy] = 1;
			dfs(i + dx, j + dy, r, c);
		}
}
int main()
{
	int r, c;
	scanf("%d %d",&r, &c);
	f(i,0,r)
		cin>>ar[i];
	memset(vis, 0, sizeof vis);
	int cnt = 0;
	f(i,0,r) f(j,0,c) {
		if(ar[i][j] == '.')
			continue;
		if(vis[i][j])
			continue;
		dfs(i, j, r, c);
		cnt++;
	}
	printf("%d\n", cnt);
    return 0;
}