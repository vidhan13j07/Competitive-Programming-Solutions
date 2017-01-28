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
const int N=1e5;
int val[3*N],ar[N];
void build(int ind,int i,int j)
{
	if(i>j)
		return ;
	if(i==j)
	{
		val[ind]=ar[i];
		return ;
	}
	int mid=(i+j)>>1,lt=ind<<1,rt=lt|1;
	build(lt,i,mid);
	build(rt,mid+1,j);
	val[ind]=val[lt]&val[rt];
}
int query(int ind,int i,int j,int l,int r)
{
	if(i>j or i>r or j<l)
		return -1;
	if(i>=l and j<=r)
		return val[ind];
	int mid=(i+j)>>1,lt=ind<<1,rt=lt|1;
	return (query(lt,i,mid,l,r)&query(rt,mid+1,j,l,r));
}
int main() 
{
	int n,k,ans;
	TC()
	{
		scanf("%d %d",&n,&k);
		f(i,0,n)
			scanf("%d",&ar[i]);
		build(1,0,n-1);
		if(k>=n/2)
		{
			ans=query(1,0,n-1,0,n-1);
			f(i,0,n-1)
				printf("%d ",ans);
			printf("%d\n",ans);
		}
		else
		{
			f(i,0,n)
			{
				int s = (i - k + n) % n;
				int e = (i + k) % n;
				ans = -1;
				if(s < i)
					ans &= query(1, 0, n - 1, s, i);
				else
					ans &= query(1, 0, n - 1, 0, i) & query(1, 0, n - 1, s, n - 1);
				if(e > i)
					ans &= query(1, 0, n - 1, i, e);
				else
					ans &= query(1, 0, n - 1, i, n - 1) & query(1, 0, n - 1, 0, e);
				if(i)
					printf(" ");
				printf("%d",ans);
			}
			printf("\n");
		}
	}
	return 0;
}