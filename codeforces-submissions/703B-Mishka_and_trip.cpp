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
bool fl[N];
ll c[N];
int main()
{
	int n, kk, id;
	scanf("%d %d",&n, &kk);
	f(i,0,n) { 
		scanf("%lld",c+i);
		fl[i] = 0;
	}
	f(i,0,kk) { 
		scanf("%d",&id);
		fl[id - 1] = 1;
	}
	ll ans = 0;
	f(i,0,n)
		if(i == 0)
			ans += c[i]*c[n - 1];
		else
			ans += c[i]*c[i - 1];
	ll k = 0;
	f(i,0,n)
		if(!fl[i])
			k += c[i];
	f(i,0,n) {
		if(fl[i]) {
			ll tmp = k;
			if(i == 0) {
				if(!fl[n - 1])
					tmp -= c[n - 1];
				if(!fl[i + 1])
					tmp -= c[i + 1];
			}
			else if(i == n - 1) {
				if(!fl[0])
					tmp -= c[0];
				if(!fl[i - 1])
					tmp -= c[i - 1];
			}
			else {
				if(!fl[i - 1])
					tmp -= c[i - 1];
				if(!fl[i + 1])
					tmp -= c[i + 1];
			}
			ans += c[i]*tmp;
			k += c[i];
			fl[i] = 0;
		}
	}
	printf("%lld\n", ans);
    return 0;
}