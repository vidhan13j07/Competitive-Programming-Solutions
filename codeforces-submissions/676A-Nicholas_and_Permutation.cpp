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
	int n;
	cin>>n;
	int ar[n];
	pair<int,int> p[n];
	f(i,0,n) {
		cin>>ar[i];
		p[i] = {ar[i],i};
	}
	int ans = 0;
	sort(p,p + n);
	int ind = p[0].se,ind1 = p[n - 1].se;
	if(ind == 0 or ind1 == n - 1 or ind == n - 1 or ind1 == 0)
		ans = n - 1;
	else {
		ans = max(ans,ind);
		ans = max(ans,n - ind - 1);
		ans = max(ans,ind1);
		ans = max(ans,n - 1 - ind1);
	}
	cout<<ans<<endl;
    return 0;
}