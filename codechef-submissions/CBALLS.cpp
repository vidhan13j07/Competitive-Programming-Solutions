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
const int N=1e4+5;
int ar[N],chk[N];
vi prime;
void pre()
{
	f(i,0,N)
		chk[i]=0;
	prime.eb(2);
	for(int i=3;i<N;i+=2)
		if(!chk[i])
		{
			prime.eb(i);
			if(i*i<N)
				for(int j=i*i,k=2*i;j<N;j+=k)
					chk[j]=1;
		}
}
int main() 
{
	pre();
	int n,s,k;
	ll ans,min_ans;
	TC()
	{
		scanf("%d",&n);
		assert(1<=n<=10000);
		min_ans=1e9;
		f(i,0,n)
		{
			scanf("%d",&ar[i]);
			assert(1<=ar[i]<=10000);
			//ma=max(ma,ar[i]);
		}
		for(auto p:prime)
		{
			//if(p>ma)
			//	break;
			ans=0,s=0;
			f(i,0,n)
			{
				if(i>0 and ar[i]<=s)
				{
					ans+=s-ar[i];
					continue;
				}
				k=ar[i]%p;
				if(k==0)
					s=ar[i];
				else
				{
					ans+=p-k;
					s=ar[i]+p-k;
				}
				//trace4(ar[i],p,s,ans);
			}
			//trace2(p,ans);
			min_ans=min(min_ans,ans);
		}
		printf("%lld\n",min_ans);
	}
	return 0;
}
