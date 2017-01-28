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

const int N = 3e5 + 5;
int ar[N], done[N];
pi p[N];
vector< pi > v;
int main()
{
	int n, q, ma = 0, c = 0, r = 0, k = 0;
	scanf("%d %d",&n, &q);
	memset(ar, 0, sizeof(ar));
	memset(done, -1, sizeof(done));
	while(q--){
		int a, b;
		scanf("%d %d",&p[k].fi, &p[k].se);
		a = p[k].fi, b = p[k].se;
		if(a == 1){
			ar[b]++;
			c++;
			v.eb({k, b});
		}
		else if(a == 2) {
			r += ar[b];
			ar[b] = 0;
			done[b] = k;
		}
		else if(a == 3) {
			if(b > ma) {
				while(ma < b) {
					if(v[ma].fi > done[v[ma].se] and ar[v[ma].se] > 0) {
						ar[v[ma].se]--;
						c--;
					}
					ma++;
				}	
			}
		}
		printf("%d\n", (c - r));
		k++;
	}
    return 0;
}