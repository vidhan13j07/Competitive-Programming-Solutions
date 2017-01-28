#include<bits/stdc++.h>
#define ll long long int
#define sc(v) v.size()
#define eb push_back
#define pb pop_back
#define fl(HD,a) for(auto HD: a)
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
const int N=155;
int ar[N][N];
ll sum[N];
int main() 
{
	int n,m,s,ans;
	TC()
	{
		scanf("%d %d %d",&n,&m,&s);
		ans=0;
		f(i,0,n)
			f(j,0,m)
				scanf("%d",&ar[i][j]);
		f(i,0,n)
		{
			f(j,0,m)
				sum[j]=0;
			f(j,i,n)
			{
				f(k,0,m)
					sum[k]+=ar[j][k];
				f(x,0,m)
				{
					ll sm=0;
					f(k,x,m)
					{
						sm+=sum[k];
						if(sm<=s)
							ans++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
