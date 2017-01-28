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
ll ar[N];
set< pair<int,int> > st;
multiset<ll> mt;
int main()
{
	int n;
	scanf("%d",&n);
	ar[0] = 0;
	f(i,1,n + 1) {
		scanf("%lld",ar+i);
		ar[i] += ar[i - 1];
	}
	st.insert( {n, 1} );
	mt.insert(ar[n]);
	f(i,0,n - 1) {
		int tmp;
		scanf("%d",&tmp);
		set< pi >::iterator it = st.lower_bound( {tmp, 0} );
		pi p = *it;
		swap(p.fi, p.se);
		st.erase(it);
		ll s = ar[p.se] - ar[p.fi - 1];
		mt.erase(mt.find(s));
		if(p.fi == p.se) {
			printf("%lld\n", *mt.rbegin());
			continue;
		}
		if(p.fi == tmp) {
			st.insert( {p.se, p.fi + 1} );
			mt.insert(ar[p.se] - ar[p.fi]);
		}
		else if(p.se == tmp) {
			st.insert( {p.se - 1, p.fi} );
			mt.insert(ar[p.se - 1] - ar[p.fi - 1]);
		}
		else {
			st.insert( {tmp - 1, p.fi} );
			st.insert( {p.se, tmp + 1} );
			mt.insert(ar[tmp - 1] - ar[p.fi - 1]);
			mt.insert(ar[p.se] - ar[tmp]);
		}
		printf("%lld\n", *mt.rbegin());
	}
	printf("0\n");
    return 0;
}
