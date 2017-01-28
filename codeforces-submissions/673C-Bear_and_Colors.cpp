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

const int N = 5005;
ll ar[N],ans[N],cnt[N];
int main()
{
	int n;
	scanf("%d",&n);
	f(i,1,n + 1)
		scanf("%lld",&ar[i]);
	f(i,1,n + 1)
	{
		ll u = 0;
		f(j,1,n + 1)
			cnt[j] = 0;
		f(j,i,n + 1)
		{
			cnt[ar[j]]++;
			if(cnt[ar[j]] > cnt[u] or (cnt[ar[j]] == cnt[u]  and ar[j] < u))
				u = ar[j];
			ans[u]++;
		}
	}
	f(i,1,n + 1)
		printf("%lld ",ans[i]);
	printf("\n");
    return 0;
}
