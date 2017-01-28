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
	vector<ll> v(3);
	scanf("%lld %lld %lld",&v[0], &v[1], &v[2]);
	sort(all(v));
	if(v[0] == v[2])
		cout<<"0";
	else if(v[1] == v[2])
		cout<<(v[1] - v[0] - 1);
	else if(v[0] == v[1]) {
		if(v[2] - v[0] == 1) {
			cout<<"0";
		}
		else {
			cout<<(2*(v[2] - v[0] - 1));
		}
	}
	else {
		cout<<(v[2] - v[0] - 1 + v[2] - v[1] - 1);
	}
    return 0;
}