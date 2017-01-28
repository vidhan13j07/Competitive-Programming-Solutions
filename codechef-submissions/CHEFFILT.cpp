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
const int N=1025;
const int M=1e5+5;
const ll mod=1e9+7;
int hsh[N];
ll dp[2][N],power[M];
int cal(char s[12])
{
	int mask=0;
	f(i,0,10)
		if(s[i]=='+' or s[i]=='w')
			mask |= (1<<i);
	return mask;
}
int main() 
{
	char pix[12];
	int n,mask;
	power[0]=1;
	f(i,1,M)
	{
		power[i]=power[i-1]*2;
		if(power[i]>=mod)
			power[i]%=mod;
	}
	TC()
	{
		f(i,0,N)
			dp[0][i]=dp[1][i]=hsh[i]=0;
		scanf("%s",pix);
		mask=cal(pix);
		//cout<<mask<<endl;
		dp[0][mask]++;
		scanf("%d",&n);
		f(i,0,n)
		{
			scanf("%s",pix);
			hsh[cal(pix)]++;
		}
		int index=0;
		for(int i=0;i<1024;i++)
		{
			int ind=1 ^ index;
			if(hsh[i]==0)
				continue;
			//trace2(i,hsh[i]);
			ll x1=power[hsh[i]-1];
			for(int j=0;j<1024;j++)
			{
				dp[ind][j]=dp[index][j]+dp[index][j ^ i];
				dp[ind][j]*=x1;
				if(dp[ind][j]>=mod)
					dp[ind][j]%=mod;
				//dp[ind][j]+=dp[index][j]*(x1-1);
				//if(dp[ind][j]>=mod)
				//	dp[ind][j]%=mod;
				//if(dp[ind][j]>0)
				//	cout<<i<<" "<<hsh[i]<<" "<<x1<<" "<<j<<" "<<dp[ind][j]<<endl;
			}
			index=ind;
		}
		printf("%lld\n",dp[index][0]);
	}
	return 0;
}
