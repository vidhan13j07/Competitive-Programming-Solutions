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
const int N = 1e3+5;
const ll mod = 1e9+7;
int ar[N];
ll dp[N][N];
int main()
{
	int n,m,s;
	TC() {
		scanf("%d %d %d",&n,&m,&s);
		f(i,1,m + 1)
			scanf("%d",&ar[i]);
		f(i,0,n + 1)
			f(j,0,m + 1)
				dp[j][i] = 0;
		dp[0][s - 1] = 1;
		f(i,1,m + 1)
			f(j,0,n)
			{
				if(j + ar[i] < n)
				{
					dp[i][j + ar[i]] += dp[i - 1][j];
					if(dp[i][j + ar[i]] >= mod)
						dp[i][j + ar[i]] %= mod;
				}
				if(j >= ar[i])
				{
					dp[i][j - ar[i]] += dp[i - 1][j];
					if(dp[i][j - ar[i]] >= mod)
						dp[i][j - ar[i]] %= mod;
				}
			}	
		f(i,0,n)
			printf("%lld ",dp[m][i]);
		printf("\n");
	}
    return 0;
}
