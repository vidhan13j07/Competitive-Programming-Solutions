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
const int N = 1e6 + 5;
int sp[N], ar[N];
bool v[N];
vi vv;
map<int,int> mp;
void pre() {
	for(int i = 2;i < N;i += 2)
		sp[i] = 2;
	memset(v, 0, sizeof v);
	for(ll i = 3;i < N;i += 2) {
		if(!v[i]) {
			sp[i] = i;
			for(ll j = i;(j*i) < N;j += 2) {
				if(!v[j*i]) {
					sp[j*i] = i;
					v[j*i] = 1;
				}
			}
		}
	}
}
void cal(int n) {
	while(n > 1) {
		int d = sp[n], c = 0;
		while(n%d == 0) {
			c++;
			n /= d;
		}
		if(c&1)
			mp[d]++;
	}
}
int cal1(int n) {
	int x = sc(vv);
	while(n > 1) {
		int d = sp[n], c = 0;
		while(n%d == 0) {
			n /= d;
			c++;
		}
		if(c&1) {
			if(binary_search(all(vv), d))
				x--;
			else
				x++;
		}
	}
	return x;
}
int main()
{
	pre();
	TC() {
		int n;
		scanf("%d",&n);
		mp.clear();
		vv.clear();
		f(i,0,n) {
			scanf("%d", ar+i);
			cal(ar[i]);
		}
		for(auto it: mp)
			if(it.se > n - it.se)
				vv.eb(it.fi);
		int ans = 0;
		f(i,0,n)
			if(ar[i] == 1)
				ans += sc(vv);
			else
				ans += cal1(ar[i]);
		printf("%d\n", ans);
	}
    return 0;
}
