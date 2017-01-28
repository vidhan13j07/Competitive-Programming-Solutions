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

string s[5];
bool find(pi a, pi b, pi c) {
	if(a.fi < 0 or a.fi >= 4)
		return 0;
	if(b.fi < 0 or b.fi >= 4)
		return 0;
	if(c.fi < 0 or c.fi >= 4)
		return 0;
	if(a.se < 0 or a.se >= 4)
		return 0;
	if(b.se < 0 or b.se >= 4)
		return 0;
	if(c.se < 0 or c.se >= 4)
		return 0;
	return s[a.fi][a.se] == 'x' and s[b.fi][b.se] == 'x' and s[c.fi][c.se] == 'x';
}
bool chk() {
	bool ok = 0;
	f(i,0,4) {
		f(j,0,4) {
			if(find({i, j}, {i, j + 1}, {i, j + 2}))
				ok = 1;
			if(find({i, j}, {i + 1, j}, {i + 2, j}))
				ok = 1;
			if(find({i, j}, {i + 1, j + 1}, {i + 2, j + 2}))
				ok = 1;
			if(find({i, j}, {i - 1, j + 1}, {i - 2, j + 2}))
				ok = 1;
		}
	}
	return ok;
}
int main()
{
	f(i,0,4)
		cin>>s[i];
	bool fl = 0;
	if(chk())
		fl = true;
	f(i,0,4)
		f(j,0,4) {
			if(s[i][j] == '.') {
				s[i][j] = 'x';
				if(chk())
					fl = true;
				s[i][j] = '.';
			}
		}
	printf(fl?"YES":"NO");
    return 0;
}