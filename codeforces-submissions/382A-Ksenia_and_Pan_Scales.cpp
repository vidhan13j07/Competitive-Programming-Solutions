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
const int MAXN = 1e5+5;
char str[MAXN],s[MAXN];
int main() {
	// freopen("TASK.in","r",stdin);freopen("TASK.out","w",stdout);
	precompute();
	scanf("%s",str+1);
	int len=strlen(str+1);
	int c1=0,c2=0;
	bool f=false;
	vector<char> v1,v2;
	for(int i=1;i<=len;i++) {
		if(str[i]=='|') {
			f=true;
			continue;
		}
		if(f) v2.pb(str[i]),c2++;
		else c1++,v1.pb(str[i]);
	}
	scanf("%s",s+1);
	int l = strlen(s+1);
	if(l<abs(c1-c2)) {
		cout<<"Impossible\n";
		return 0;
	}
	if(abs(l-abs(c1-c2))%2!=0) {
		cout<<"Impossible\n";
		return 0;
	}
	int cc=1;
	while(l--) {
		if(sz(v1)<sz(v2)) v1.pb(s[cc++]);
		else v2.pb(s[cc++]);
	}
	for(auto it:v1) printf("%c",it);
	printf("|");
	for(auto it:v2) printf("%c",it);
	printf("\n");
	return 0;
}
