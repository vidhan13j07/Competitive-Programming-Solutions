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

vi v;
ll a, b;
bool fl;
void dfs(ll x) {
	if(fl)
		return;
	if(x == b) {
		printf("YES\n");
		cout<<(sc(v) + 1)<<endl;
		for(auto it: v)
			cout<<it<<" ";
		cout<<b<<endl;
		fl = 1;
		return ;
	}
	v.eb(x);
	if(2*x <= b)
		dfs(2*x);
	if(10*x <= b)
		dfs(10*x + 1);
	v.pop_back();
}
int main()
{
	cin>>a>>b;
	fl = 0;
	dfs(a);
	if(!fl)
		cout<<"NO";
    return 0;
}