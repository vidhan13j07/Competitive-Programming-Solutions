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
ll dp[2][N][N];
void pre()
{
	f(i,0,N)
		f(j,0,N)
			dp[0][i][j] = dp[1][i][j] = 0;
	dp[0][1][0] = dp[1][1][0] = 1;
	f(i,2,N)
	{
		f(j,0,i)
		{
			dp[0][i][j] = dp[0][i - 1][j] + dp[1][i - 1][j];
			if(j > 0)
				dp[1][i][j] = dp[1][i - 1][j - 1];
			dp[1][i][j] += dp[0][i - 1][j];
		}
	}
}
int main()
{
	int tc,n,k;
	pre();
	TC()
	{
		scanf("%d %d %d",&tc,&n,&k);
		printf("%d %d\n",tc,dp[0][n][k] + dp[1][n][k]);
	}
    return 0;
}
