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

vector< pair<ll,ll> > v;
bool chk(ll a, ll b, ll c) {
	//trace3(a, b, c);
	if(a*a + b*b == c*c)
		return 1;
	if(a*a + c*c == b*b)
		return 1;
	if(b*b + c*c == a*a)
		return 1;
	return 0;
}
void divisors(ll n) {
	ll x = 1;
	while(x*x <= n) {
		if(n%x == 0) {
			v.eb({x,n/x});
		}
		x++;
	}
}
bool hypo(ll n) {
	ll k = sqrt(n/2.0);
	for (int i = 1; i <= k; i++) {
        ll tmp = sqrt((double)(n - i * i));
        if ((tmp * tmp) == (n - i * i)) {
        	cout<<(tmp*tmp - i*i)<<" "<<(2 * tmp * i);
            return 1;
        }
    }
	return 0;
}
int main()
{
	ll n;
	scanf("%lld",&n);
	if(n <= 2){ cout<<"-1\n";return 0;}
	divisors(n);
	for(auto it: v) {
		ll k = it.fi + it.se;
		if(k%2 == 0) {
			k /= 2;
			ll d = -1;
			if(it.fi > k)
				d = it.fi - k;
			if(d >= 0 and chk(d*d+k*k, 2*d*k, n)) {
				cout<<(2*d*k)<<" "<<(d*d+k*k);
				return 0;
			}
			d = -1;
			if(it.se > k)
				d = it.se - k;
			if(d >= 0 and chk(d*d+k*k, 2*d*k, n)) {
				cout<<(2*d*k)<<" "<<(d*d+k*k);;
				return 0;
			}
		}
		if(n%2 == 0) {
			if(it.fi%2 == 0) {
				ll k = it.fi/2;
				ll d = it.se;
				if(chk(n, k*k+d*d, abs(k*k - d*d))) {
					cout<<(abs(k*k-d*d))<<" "<<(k*k + d*d);
					return 0;
				}
			}
			if(it.se%2 == 0) {
				ll k = it.se/2;
				ll d = it.fi;
				if(chk(n, k*k+d*d, abs(k*k - d*d))) {
					cout<<(abs(k*k-d*d))<<" "<<(k*k + d*d);
					return 0;
				}
			}
		}
	}
	if(hypo(n))
		return 0;
	cout<<"-1";
    return 0;
}