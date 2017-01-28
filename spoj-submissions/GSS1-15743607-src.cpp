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
#define max3(a,b,c) max(a,max(b,c))
using namespace std;
const int N=50005;
int ar[N];
class node
{
	public:
		int lef,righ,ans,s;
		void init(int val)
		{
			lef=righ=ans=s=val;
		}
		void merge(node &l,node &r)
		{
			s=l.s+r.s;
			lef=max(l.lef,l.s+r.lef);
			righ=max(r.righ,r.s+l.righ);
			ans=max3(l.ans,r.ans,l.righ+r.lef);
		}
}T[3*N];
void build(int ind,int i,int j)
{
	if(i>j)
		return ;
	if(i==j)
	{
		T[ind].init(ar[i]);
		return ;
	}
	int mid=(i+j)/2;
	build(2*ind+1,i,mid);
	build(2*ind+2,mid+1,j);
	T[ind].merge(T[2*ind+1],T[2*ind+2]);
}
void query(node &result,int ind,int i,int j,int l,int r)
{
	if(i==l and j==r)
	{
		result=T[ind];
		return ;
	}
	int mid=(i+j)/2;
	if(r<=mid)
		query(result,2*ind+1,i,mid,l,r);
	else if(l>mid)
		query(result,2*ind+2,mid+1,j,l,r);
	else
	{
		node le,ri;
		query(le,2*ind+1,i,mid,l,mid);
		query(ri,2*ind+2,mid+1,j,mid+1,r);
		result.merge(le,ri);
	}
}
int main() 
{
	int n,q,a,b;
	scanf("%d",&n);
	f(i,0,n)
		scanf("%d",&ar[i]);
	build(0,0,n-1);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %d",&a,&b);
		node result;
		query(result,0,0,n-1,--a,--b);
		printf("%d\n",result.ans);
	}
	return 0;
}