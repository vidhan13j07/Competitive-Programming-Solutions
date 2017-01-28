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
ll val[3*N],lazy[3*N];
void chk_lazy(int ind,int i,int j)
{
	if(lazy[ind]==0)
		return ;
	val[ind]+=lazy[ind];
	int mid=(i+j)/2,lt=2*ind,rt=lt+1;
	if(i!=j)
	{
		lazy[lt]+=((lazy[ind]/(j-i+1))*(mid-i+1));
		lazy[rt]+=((lazy[ind]/(j-i+1))*(j-mid));
	}
	lazy[ind]=0;
}
void update(int ind,int i,int j,int l,int r,ll v)
{
	chk_lazy(ind,i,j);
	if(i>j or i>r or j<l)
		return ;
	int mid=(i+j)/2,lt=2*ind,rt=lt+1;
	if(i>=l and j<=r)
	{
		val[ind]+=v*(j-i+1);
		//cout<<ind<<" "<<i<<" "<<j<<" "<<lt<<" "<<rt<<" "<<l<<" "<<r<<endl;
		if(i!=j)
		{
			lazy[lt]+=v*(mid-i+1);
			lazy[rt]+=v*(j-mid);
		}
		return ;
	}
	update(lt,i,mid,l,r,v);
	update(rt,mid+1,j,l,r,v);
	val[ind]=val[lt]+val[rt];
}
ll query(int ind,int i,int j,int l,int r)
{
	if(i>j or i>r or j<l)
		return 0;
	chk_lazy(ind,i,j);
	if(i>=l and j<=r)
		return val[ind];
	int mid=(i+j)/2,lt=2*ind,rt=lt+1;
	return (query(lt,i,mid,l,r)+query(rt,mid+1,j,l,r));
}
int main() 
{
	int n,q,l,r,ch;
	ll v;
	TC()
	{
		scanf("%d %d",&n,&q);
		f(i,0,3*N)
		{
			val[i]=0;
			lazy[i]=0;
		}
		while(q--)
		{
			scanf("%d %d %d",&ch,&l,&r);
			l--;r--;
			if(ch==0)
			{
				scanf("%lld",&v);
				update(1,0,n-1,l,r,v);
			}
			else
				printf("%lld\n",query(1,0,n-1,l,r));
			/*f(i,1,2*n)
				trace3(i,val[i],lazy[i]);
			cout<<endl;*/
		}
	}
	return 0;
}