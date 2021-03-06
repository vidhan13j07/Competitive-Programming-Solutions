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
int ar[N], le[N], rt[N];
int main()
{
	int n, q;
	scanf("%d %d",&n, &q);
	f(i,0,n) scanf("%d", ar+i);
	le[0] = 0;
	rt[n - 1] = n - 1;
	f(i,1,n)
	    le[i] = (ar[i] <= ar[i - 1])?le[i - 1]:i;
    for(int i = n - 2;i >= 0;i--)
        rt[i] = (ar[i] <= ar[i + 1])?rt[i + 1]:i;
	while(q--) {
		int l, r;
		scanf("%d %d",&l, &r);
		l--;r--;
		printf((rt[l] >= le[r])?"Yes\n":"No\n");
	}
    return 0;
}
