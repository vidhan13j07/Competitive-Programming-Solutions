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
 
const int N = 1e2 + 5;
int a[N][N], b[N][N], c[N][N], n, m;
bool valid(int i,int j,int k,int l) {
	if(i + k < n and i + k >= 0 and j + l < m and j + l >= 0)
		return true;
	return false;
}
bool dfs(int k, bool fl) {
	bool ok = false;
	f(i,0,n) f(j,0,m) {
		if(a[i][j])
			continue;
	f(y,-k,k + 1)
		f(x,-k,k + 1)
			if(valid(i,j,x,y)) {
				if(x*y < 0 and abs(x - y) > k)
					continue;
				if(x*y > 0 and abs(x + y) > k)
					continue;
				if(x*y == 0 and (abs(x+y) == 0 or abs(x + y) > k))
					continue;
				if(fl)
					if(c[i][j] + 1 < c[i + x][j + y]) {
						c[i + x][j + y] = c[i][j] + 1;
						ok = true;
					}
				else {
					//trace4(i,j,i + x,j + y);
					if(b[i][j] + 1 < b[i + x][j + y]) {
						b[i + x][j + y] = b[i][j] + 1;
						ok = true;
					}
				}
			}
	}
	return ok;
}
int main()
{
	TC() {
		int k1, k2;
		scanf("%d %d %d %d",&n, &m, &k1, &k2);
		f(i,0,n)
			f(j,0,m) {
				scanf("%d",&a[i][j]);
				b[i][j] = 1001;
				c[i][j] = 1001;
			}
		b[0][0] = 0;
		while(dfs(k1,0));
		c[0][m - 1] = 0;
		while(dfs(k2,1));
		int mi = 1001;
		a[0][0] = 1;
		a[0][m - 1] = 1;
		f(j,0,m)
			f(i,0,n) {
				if(a[i][j])
					continue;
				mi = min(mi, max(b[i][j],c[i][j]));
				//trace5(i,j,b[i][j],c[i][j],mi);
			}
		if(mi == 1001)
			mi = -1;
		printf("%d\n", mi);
	}
    return 0;
}
