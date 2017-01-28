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
const int N=1e5+5;
const ll mod=1e9+7;
ll power2[N],ar[N],prefixsum[N];
int main() 
{
	int n;
	ll ans;
	power2[0]=1;
	f(i,1,N)
	{
		power2[i]=power2[i-1]*2;
		if(power2[i]>=mod)
			power2[i]%=mod;
	}
	TC()
	{
		scanf("%d",&n);
		f(i,0,n+1)
			scanf("%lld",&ar[i]);
		prefixsum[n]=ar[n];
		ans=0;
		for(int i=n-1,k=1;i>0;i--,k++)
		{
			prefixsum[i]=ar[i]*power2[k];
			if(prefixsum[i]>=mod)
				prefixsum[i]%=mod;
			prefixsum[i]+=prefixsum[i+1];
			if(prefixsum[i]>=mod)
				prefixsum[i]%=mod;
		}
		for(int i=0,k=1;i<n;i++)
		{
			if(i==0 or i==1)
				ans+=prefixsum[i+1]*ar[i];
			else
			{
				ll cnt=prefixsum[i+1]*power2[k];
				if(cnt>=mod)
					cnt%=mod;
				ans+=ar[i]*cnt;
				k++;
			}
			if(ans>=mod)
				ans%=mod;
		}
		ans*=2;
		if(ans>=mod)
			ans%=mod;
		printf("%lld\n",ans);
	}
	return 0;
}
