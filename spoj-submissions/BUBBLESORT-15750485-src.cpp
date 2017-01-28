#include<bits/stdc++.h>
#define ll long long int
#define sc(v) v.size()
#define eb push_back
#define pb pop_back
#define stl(a,it) for(auto it: a)
#define f(i,a,b) for(int i=a;i<b;i++)
#define TC() int t;cin>>t;while(t--)
#define contain(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define mk make_pair
#define fi first
#define se second 
#define trace1(x)                cout <<#x<<": "<<x<<endl;
#define trace2(x, y)             cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
using namespace std;
const int N=1<<15+5;
const ll mod=1e7+7;
int ar[N];
int a[N],b[N];
void update(int a)
{
	for(;a<=N;a+=(a&(-a)))
		ar[a]++;
}
int query(int a)
{
	int ans=0;
	for(;a;a-=(a&(-a)))
		ans+=ar[a];
	return ans;
}
int main() 
{
	int n,tc=0;
	ll ans;
	TC()
	{
		scanf("%d",&n);
		tc++;
		ans=0;
		memset(ar,0,sizeof(ar));
		f(i,0,n)
		{
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		sort(b,b+n);
		f(i,0,n)
		{
			int rank=(lower_bound(b,b+n,a[i])-b);
			a[i]=rank+1;
		}
		for(int i=n-1;i>=0;i--)
		{
			ans+=query(a[i]-1);
			update(a[i]);
			if(ans>=mod)
				ans%=mod;
		}
		printf("Case %d: %lld\n",tc,ans);
	}
	return 0;
}