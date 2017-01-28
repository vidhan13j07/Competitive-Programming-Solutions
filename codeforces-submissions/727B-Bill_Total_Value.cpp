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

int main()
{
	string s;
	cin>>s;
	ll x = 0, x1 = 0;
	int i = 0;
	while(i < sc(s)) {
		int j = i;
		string ss = "";
		while(j < sc(s) and ((s[j] >= '0' and s[j] <= '9') or s[j] == '.')) {
			ss += s[j];
			j++;
		}
		i = j + 1;
		if(ss == "")
			continue;
		j = 0;
		ll k = 0, k1 = 0;
		if(sc(ss) >= 3 and ss[sc(ss) - 3] == '.') {
			k = 10*(ss[sc(ss) - 2] - '0') + (ss[sc(ss) - 1] - '0');
			f(r,0,3)
				ss.pop_back();
		}
		while(j < sc(ss)) {
			if(ss[j] != '.') {
				k1 = k1*10 + ss[j] - '0';
			}
			j++;
		}
		x += k1;
		x1 += k;
		//trace5(i, k1, k, x, x1);
	}
	ll e = x1/100;
	x1 %= 100;
	x += e;
	vector<char> v;
	while(x1) {
		v.eb(('0' + x1%10));
		x1 /= 10;
	}
	if(sc(v) == 1) {
		v.eb('0');
	}
	if(sc(v) > 0)
		v.eb('.');
	if(x == 0) 
		v.eb('0');
	i = 0;
	while(x) {
		if(i > 0 and i%3 == 0)
			v.eb('.');
		v.eb(('0' + x%10));
		x /= 10;
		i++;
	}
	reverse(all(v));
	for(auto it: v)
		cout<<it;
    return 0;
}