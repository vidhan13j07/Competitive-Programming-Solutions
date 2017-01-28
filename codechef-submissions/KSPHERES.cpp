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
const int N=1e3+5;
const ll mod=1e9+7;
ll dp[N][N],l[N],r[N],s[N];
int main() 
{
	int n,m,c,temp;
	f(i,0,N)
	{
		f(j,0,N)
			dp[i][j]=0;
		l[i]=0;
		r[i]=0;
	}
	scanf("%d %d %d",&n,&m,&c);
	f(i,0,n)
	{
		scanf("%d",&temp);
		l[temp]++;
	}
	f(i,0,m)
	{
		scanf("%d",&temp);
		r[temp]++;
	}
	f(i,1,c+1)
	{
		s[i-1]=l[i]*r[i];
		if(i>1)
			dp[i-1][0]=dp[i-2][0]+s[i-1];
		else
			dp[i-1][0]=s[i-1];
	}
	f(i,1,c+1)
	{
		f(j,1,i+1)
		{
			dp[i][j]=dp[i-1][j]+s[i]*dp[i-1][j-1];
			if(dp[i][j]>=mod)
				dp[i][j]%=mod;
		}
	}
	f(i,1,c+1)
		printf("%lld ",dp[c][i]);
	printf("\n");
	return 0;
}
