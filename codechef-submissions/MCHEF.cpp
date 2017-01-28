#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define sc(v) v.size()
#define eb push_back
#define pb pop_back
#define stl(a,it) for(auto it: a)
#define f(i,a,b) for(int i=a;i<b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define TC() int t;cin>>t;while(t--)
#define contain(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define mk make_pair
#define endl "\n"
#define fi first
#define se second 
#define gcd __gcd
#define trace1(x)                cerr <<#x<<": "<<x<<endl;
#define trace2(x, y)             cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
#define mod 1000000007
#define mem(a,b) memset(a,b,sizeof(a))
#define chk(a) if(a>=mod) a%mod;
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vpp vector < pair<int,int> > 
using namespace std;
 
void FastIO()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
}
void die()
{
	cout<<"0"<<endl;
	exit(0);
}
ll power(ll a,ll b)
{
	ll x=1;
	while(b)
	{
		if(b&1)
			x*=a;
		a*=a;
		chk(x);
		chk(a);
		b>>=1;
	}
	return x;
}
//TEMPLATE ENDS HERE
vpp v;
int n,k;
const int N=1e5+5;
const int K=505;
int price[4*N+5];
int lazy[4*N+5];
ll Kn[N][K];
ll ar[N];
ll knapsack()
{
    int l=sc(v);
    f(i,0,l+1)
        f(w,0,k+1)
        {
            if(i==0 or w==0)
                Kn[i][w]=0;
            else if(v[i-1].se<=w)
                Kn[i][w]=max(v[i-1].fi+Kn[i-1][w-v[i-1].se],Kn[i-1][w]);
            else
                Kn[i][w]=Kn[i-1][w];
        }
    /*f(i,0,l+1)
    {
        f(j,0,k+1)
            cout<<K[i][j]<<" ";
        cout<<endl;
    }*/
    return Kn[l][k];
}
 
void build(int cur,int sa,int ea)
{
	//cout<<cur<<" "<<sa<<" "<<ea<<endl;
	if(sa>ea)
		return ;
	if(sa==ea)
	{
		price[cur]=K;
		lazy[cur]=K;
		return ;
	}
	int mid=(sa+ea)/2;
	build(2*cur+1,sa,mid);
	build(2*cur+2,mid+1,ea);
	//price[cur]=K;
}
 
void propagate(int cur,int sa,int ea)
{
	if(price[cur]>lazy[cur])
		price[cur]=lazy[cur];
	if(sa!=ea)
	{
		if(lazy[2*cur+1]>lazy[cur])
			lazy[2*cur+1]=lazy[cur];
		if(lazy[2*cur+2]>lazy[cur])
			lazy[2*cur+2]=lazy[cur];
	}
	lazy[cur]=K;
}
 
void update(int cur,int sa,int ea,int l,int r,int val)
{
	if(sa>ea or sa>r or ea<l)
		return ;
	if(lazy[cur]!=K)
		propagate(cur,sa,ea);
	if(sa>=l and ea<=r)
	{
		if(lazy[cur]>val)
			lazy[cur]=val;
		if(lazy[cur]!=K)
			propagate(cur,sa,ea);
		return ;
	}
	int mid=(sa+ea)/2;
	update(2*cur+1,sa,mid,l,r,val);
	update(2*cur+2,mid+1,ea,l,r,val);
	price[cur]=max(price[2*cur+1],price[2*cur+2]);
}
 
int query(int cur,int sa,int ea,int l,int r)
{
	if(sa>ea or sa>r or ea<l)
		return K;
	if(lazy[cur]!=K)
		propagate(cur,sa,ea);
	if(sa>=l and ea<=r)
		return price[cur];
	int mid=(sa+ea)/2;
	return min(query(2*cur+1,sa,mid,l,r),query(2*cur+2,mid+1,ea,l,r));
}
 
int main() 
{
	FastIO();
    int m,l,r,c;
    ll s,temp;
    TC()
    {
        cin>>n>>k>>m;
        s=0;
        v.clear();
        f(i,0,3*n)
        	lazy[i]=K;
        f(i,0,n)
        {
            cin>>ar[i];
            s+=ar[i];
            if(ar[i]<0)
                v.eb(mk(i,205));
        }
        /*f(i,1,15)
        	cout<<i<<" "<<price[i]<<" "<<lazy[i]<<endl;
        cout<<"after build"<<endl;*/
        build(0,0,n-1);
        /*f(i,1,15)
        	cout<<i<<" "<<price[i]<<" "<<lazy[i]<<endl;
        cout<<"after update"<<endl;*/
        while(m--)
        {
            cin>>l>>r>>c;
            update(0,0,n-1,l-1,r-1,c);
        }
        /*f(i,1,15)
        	cout<<i<<" "<<price[i]<<" "<<lazy[i]<<endl;
        cout<<"after query"<<endl;*/
        f(i,0,sc(v))
        {
        	//cout<<v[i].fi<<" ";
        	v[i].se=query(0,0,n-1,v[i].fi,v[i].fi);
            v[i].fi=abs(ar[v[i].fi]);
            //cout<<v[i].fi<<" "<<v[i].se<<endl;
        }
            /*f(i,0,sc(v))
                cout<<v[i].fi<<" "<<v[i].se<<endl;*/
        /*f(i,0,sc(v))
            cout<<v[i].fi<<" "<<v[i].se<<endl;*/
        temp=knapsack();
        s+=temp;
        //cout<<s<<" "<<temp<<endl;
        cout<<s<<endl;
    }
	return 0;
}
