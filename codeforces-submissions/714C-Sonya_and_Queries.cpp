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

const int N = 1<<20;
int ar[N];
int go(string s) {
	int k = 1;
	for(char ch: s) {
		if(ch == '0')
			k = k*2;
		else
			k = k*2 + 1;
	}
	//trace2(s, k);
	return k;
}
int cal(ll n) {
	string s = "";
	while(n) {
		int k = n%10;
		n /= 10;
		s += (k&1)?'1':'0';
	}
	while(sc(s) < 18)
		s += '0';
	return go(s);
}
int main()
{
	int q;
	memset(ar, 0 , sizeof ar);
	scanf("%d",&q);
	while(q--) {
		char ch;
		cin>>ch;
		if(ch == '+') {
			ll tmp;
			scanf("%lld",&tmp);
			int k = cal(tmp);
			//trace2("add", k);
			ar[k]++;
		}
		else if(ch == '-') {
			ll tmp;
			scanf("%lld",&tmp);
			int k = cal(tmp);
			//trace2("del", k);
			ar[k]--;
		}
		else {
			string ss;
			cin>>ss;
			reverse(all(ss));
			while(sc(ss) < 18)
				ss += '0';
			int k = go(ss);
			//trace2("query", k);
			printf("%d\n", ar[k]);
		}
	}
    return 0;
}