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

const int N = 200000;
int seg[3*N], ar[N];
void build(int node,int i,int j,int flag)
{
	if(i>j)
		return ;
	if(i == j)
	{
		seg[node] = ar[i];
		return ;
	}
	int mid = (i + j)/2;
	build(2*node+1,i,mid,flag^1);
	build(2*node+2,mid+1,j,flag^1);
	if(flag)
		seg[node] = seg[2*node+1] | seg[2*node+2];
	else
		seg[node] = seg[2*node+1] ^ seg[2*node+2];
}
void update(int node,int i,int j,int l,int val,int flag)
{
	if(i > j or i > l or j < l)
		return ;
	if(i == l and j == l)
	{
		seg[node] = val;
		//trace4(node,i,l,val);
		return ;
	}
	int mid = (i + j)/2;
	update(2*node+1,i,mid,l,val,flag^1);
	update(2*node+2,mid+1,j,l,val,flag^1);
	if(flag)
		seg[node] = seg[2*node+1] | seg[2*node+2];
	else
		seg[node] = seg[2*node+1] ^ seg[2*node+2];
	//trace5(node,seg[2*node+1],seg[2*node+2],flag,seg[node]);
}
int main()
{
	int n, m, flag, temp, pos;
	scanf("%d %d",&n, &m);
	f(i,0,(1<<n)) scanf("%d", ar+i);
	if(n&1)
		flag = 1;
	else
		flag = 0;
	build(0,0,(1<<n)-1,flag);
	while(m--)
	{
		scanf("%d %d",&pos, &temp);
		update(0,0,(1<<n)-1,pos-1,temp,flag);
		printf("%d\n",seg[0]);
	}
    return 0;
}