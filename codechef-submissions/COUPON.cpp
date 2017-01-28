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
auto min(auto a,auto b)
{
	if(a<b)
		return a;
	return b;
}
int main() 
{
	int n,m;
	long long mi;
	TC()
	{
		scanf("%d %d",&n,&m);
		int a[n][m],table[n][m];
		long long m1,m2,ans[n][m];
		f(i,0,n)
			f(j,0,m)
			{
				scanf("%d",&a[i][j]);
				ans[i][j]=1e18;
			}
		f(i,0,n)
			f(j,0,m)
				scanf("%d",&table[i][j]);
		f(i,0,m)
			ans[0][i]=a[0][i];
		f(i,0,n-1)
		{
			ll gmin=ans[i][0],g_ind=0, mi;
			f(k,0,m)
				if(gmin>ans[i][k])
				{
					gmin=ans[i][k];
					g_ind=k;
				}
			f(j,0,m)
			{
				mi=(ll)(a[i+1][j]-table[i][j]);
				mi=mi>0?mi:0;
				ans[i+1][j]=min(gmin+a[i+1][j],ans[i][j]+(ll)(mi));
			}
		}
		/*f(i,1,n)
		{
			m1=1e10,m2=1e10;
			f(j,0,m)
				if(ans[i-1][j]<m1 and ans[i-1][j]<m2)
				{
					m2=m1;
					m1=ans[i-1][j];
				}
				else if(ans[i-1][j]<m2)
					m2=ans[i-1][j];
			f(j,0,m)
				if(ans[i-1][j]==m1)
					v[j]=m2;
				else
					v[j]=m1;
			f(j,0,m)
				if(ar[i][j]<=dist[i-1][j])
					ans[i][j]=ans[i-1][j];
				else
					ans[i][j]=ans[i-1][j]+min(ar[i][j]-dist[i-1][j],v[j]);
		}*/
		/*f(i,0,n)
		{
			f(j,0,m)
				cout<<ar[i][j]<<" ";
			cout<<endl;
		}*/
		mi=ans[n-1][0];
		f(i,1,m)
			mi=min(mi,ans[n-1][i]);
		cout<<mi<<endl;
	}
	return 0;
}
