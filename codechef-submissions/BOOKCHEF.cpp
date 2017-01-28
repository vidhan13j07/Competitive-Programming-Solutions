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
const int N = 1e4 + 5;
int ar[N];
set<int> st;
vector< pair<int,string> > x, y;
int main()
{
	int n, m;
	cin>>n>>m;
	f(i,0,n) {
		int tmp;
		cin>>tmp;
		st.insert(tmp);
	}
	f(i,0,m) {
		int a, b;
		string s;
		cin>>a>>b>>s;
		if(st.find(a) != st.end())
			x.eb({b, s});
		else
			y.eb({b, s});
	}
	sort(x.rbegin(), x.rend());
	sort(y.rbegin(), y.rend());
	for(auto it: x)
		cout<<it.se<<endl;
	for(auto it: y)
		cout<<it.se<<endl;
    return 0;
}
