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

const int N = 3e5 + 5;
int ans[N];
set<int> st;
int main()
{
	int n, m, l, r, x;
	scanf("%d %d",&n, &m);
	f(i,1,n + 1) {
		st.insert(i);
		ans[i] = 0;
	}
	while(m--) {
		scanf("%d %d %d",&l, &r, &x);
		set<int>::iterator it = st.lower_bound(l);
		vi toerase;
		while(it != st.end() and *it <= r) {
			if(*it != x) {
				ans[*it] = x;
				toerase.eb(*it);
			}
			it++;
		}
		for(auto i: toerase)
			st.erase(i);
	}
	f(i,1,n + 1) cout<<ans[i]<<" ";
	cout<<endl;
    return 0;
}