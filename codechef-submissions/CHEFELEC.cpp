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
ll ar[N];
int main()
{
	TC() {
		int n;
		string s;
		scanf("%d",&n);
		cin>>s;
		f(i,0,n)
			scanf("%d", ar+i);
		int cnt = 0, ind = 0;
		f(i,0,n) cnt += (s[i] == '1');
		if(cnt == 1) {
			printf("%d\n",(ar[n - 1] - ar[0]));
			continue;
		}
		int i = 0,j = n - 1;
		ll ans = 0;
		while(s[i] == '0')
			i++;
		while(s[j] == '0')
			j--;
		ans += (ar[i] - ar[0]) + (ar[n - 1] - ar[j]);
		vi v;
		f(k,i,j + 1)
			if(s[k] == '1')
				v.eb(k);
		f(i,0,sc(v) - 1) {
			int x = v[i], y = v[i + 1];
			ll mi = 1e12;
			f(j,x,y) {
				mi = min(mi, ar[j] - ar[x] + ar[y] - ar[j + 1]);
				//trace2(v[j],v[j + 1]);
				//trace5(j, ar[j], ar[x], ar[y], ar[j + 1]);
			}
			//trace4(i, x, y, mi);
			ans += mi;
		}
		printf("%lld\n",ans);
	}
    return 0;
}
