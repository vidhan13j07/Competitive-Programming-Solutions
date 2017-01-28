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

const int N = 200005;
int ar[N], range[N];
vi v;
int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	f(i,0,n)
		scanf("%d",&ar[i]);
	sort(ar,ar+n,greater<int>());
	f(i,0,N)
		range[i] = 0;
	while(q--) {
		int a,b;
		scanf("%d %d",&a,&b);
		range[a - 1]++;
		range[b]--;
	}
	f(i,1,n + 1)
		range[i] += range[i - 1];
	f(i,0,n + 1)
		if(range[i] > 0)
			v.eb(range[i]);
	sort(v.rbegin(),v.rend());
	ll ans = 0;
	f(i,0,n)
		if(i >= sc(v))
			break;
		else
			ans += ((ll)(v[i]) * (ll)(ar[i]));
	printf("%lld\n",ans);
    return 0;
}