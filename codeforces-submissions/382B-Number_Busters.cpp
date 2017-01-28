#include<bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define eps 1e-9
#define fast_cin ios_base::sync_with_stdio(false)

const int MOD = 1e9+7;

typedef long long ll;
typedef pair<int,int> pii;

ll POWER[65];
ll power(ll a, ll b) {ll ret=1;while(b) {if(b&1) ret*=a;a*=a;if(ret>=MOD) ret%=MOD;if(a>=MOD) a%=MOD;b>>=1;}return ret;}
ll inv(ll x) {return power(x,MOD-2);}

void precompute() {
	POWER[0]=1;
	for(int i=1;i<63;i++) POWER[i]=POWER[i-1]<<1LL;
}
const int MAXN = 1e3+5;
bool vis[MAXN];
int main() {
	// freopen("TASK.in","r",stdin);freopen("TASK.out","w",stdout);
	precompute();
	int a,b,w,x,c;
	cin>>a>>b>>w>>x>>c;
	vector<int> B, A;
	int idx;
	int val;
	while(1) {
		if(vis[b]) {
			idx=b;
			val=a;
			break;
		}
		vis[b]=true;
		B.pb(b);
		A.pb(a);
		if(b>=x) b-=x;
		else a--,b=w-(x-b);
	}
	vector<int> repA,repB;
	bool f=false;
	ll strt,nd;
	int strtIdx;
	for(int i=0;i<sz(A);i++) {
		if(B[i]==idx) {
			strt = A[i];
			strtIdx = i;
			f=true;
		}
		if(f) repA.pb(A[i]),repB.pb(B[i]);
	}
	ll change = strt - val;
	ll ans=0;
	f=false;
	for(int i=0;i<sz(A);i++) {
		if(c<=A[i]) {
			f=true;
			break;
		}
		ans++;
		c--;
	}
	if(f or c<=val) {
		cout<<ans<<endl;
		return 0;
	}
	ll lo = 0, hi = 1e15;
	ll ret=-1;
	while(lo<=hi) {
		ll mid = lo+(hi-lo+1)/2;
		ll rot = mid/sz(repA);
		ll newA = val - change*rot;
		rot = mid%sz(repA);
		newA -= (A[strtIdx]-A[strtIdx+rot]);
		ll newC = c-mid;
		if(newC<=newA) ret=mid,hi=mid-1;
		else lo=mid+1;
	}
	cout<<ans+ret<<endl;
	return 0;
}
