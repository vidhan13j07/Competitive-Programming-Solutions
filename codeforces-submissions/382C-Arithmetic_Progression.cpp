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
int ar[N];
int main()
{
	int n;
	cin>>n;
	f(i,0,n)
		cin>>ar[i];
	sort(ar, ar + n);
	if(n == 1) {
		cout<<"-1\n";
		return 0;
	}
	if(ar[0] == ar[n - 1]) {
		cout<<"1\n"<<ar[0]<<endl;
		return 0;
	}
	int d = ar[1] - ar[0];
	vi v;
	if(n == 2) {
		v.eb(ar[0] - d);
		if(!(d&1))
			v.eb(ar[0] + d/2);
		v.eb(ar[1] + d);
		cout<<(sc(v))<<endl;
		for(auto it: v)
			cout<<it<<" ";
		return 0;
	}
	int fl = 0;
	f(i,1,n) {
		if(ar[i] - ar[i - 1] != d) {
			fl++;
			if(ar[i] - ar[i - 1] == 2*d) {
				v.eb(ar[i] - d);
			}
		}
	}
	if(fl == 0) {
		v.eb(ar[0] - d);
		v.eb(ar[n - 1] + d);
	}
	else {
		if(fl > 1 or sc(v) != 1)
			v.clear();
	}
	if(sc(v) == 0) {
		d = ar[n - 1] - ar[n - 2];
		fl = 0;
		f(i,1,n) {
			if(ar[i] - ar[i - 1] != d) {
				fl++;
				if(ar[i] - ar[i - 1] == 2*d) {
					v.eb(ar[i] - d);
				}
			}
		}
		if(fl > 1 or sc(v) != 1)
			v.clear();
	}
	cout<<(sc(v))<<endl;
	for(auto it: v)
		cout<<it<<" ";
    return 0;
}