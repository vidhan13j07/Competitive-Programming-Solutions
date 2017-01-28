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
pair<pi, ll> p[N];
int ar[N];
bool fl[N];
int main()
{
	int n, m, k;
	scanf("%d %d %d",&n, &m, &k);
	memset(fl, 0, sizeof(fl));
	f(i,0,m)
		scanf("%d %d %lld",&p[i].fi.fi,&p[i].fi.se,&p[i].se);
	f(i,0,k) {
		scanf("%d",&ar[i]);
		fl[ar[i]] = 1;
	}
	ll mi = 1e18;
	bool ok = 0;
	f(i,0,m) {
		if(fl[p[i].fi.fi] and fl[p[i].fi.se])
			continue;
		if(!fl[p[i].fi.fi] and !fl[p[i].fi.se])
			continue;
		mi = min(mi, p[i].se);
		ok = 1;
	}
	if(ok)
		cout<<mi;
	else
		cout<<"-1";
    return 0;
}