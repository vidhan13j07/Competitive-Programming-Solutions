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

const int N = 105;
int ar[N];
pi p[N];
vector< pair<int,int> > v;
int main()
{
	int n;
	scanf("%d",&n);
	f(i,0,n)
		scanf("%d", ar+i);
	int j = 0;
	while(j < n) {
		/*f(i,0,n)
			printf("%d ",ar[i]);
		printf("\n");*/
		f(i,0,n)
			p[i] = mk(ar[i],i);
		sort(p,p+n);
		if(j == p[j].se) {
			j++;
			continue;
		}
		/*cout<<j<<" "<<p[j].se<<endl;
		f(i,0,n)
			printf("%d ",ar[i]);
		printf("\n");*/
		int k = p[j].se;
		/*if((k-j) == 1) {
			v.eb(mk(k-1,k));
			swap(ar[k],ar[k-1]);
			j++;
			continue;
		}
		if((k-j+1)&1) {
			v.eb(mk(k,k+1));
			k++;
		}*/
		//swap(ar[k - 1],ar[k]);
		while(k > j) {
			v.eb(mk(k-1,k));
			swap(ar[k],ar[k-1]);
			k--;
		}
		j++;
	}
	/*f(i,0,n)
		printf("%d ",ar[i]);
	printf("\n");*/
	f(i,0,sc(v))
		printf("%d %d\n",v[i].fi+1,v[i].se+1);
    return 0;
}