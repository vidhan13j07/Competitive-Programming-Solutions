#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define sc(v) v.size()
#define eb emplace_back
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
#define trace1(x)                cout <<#x<<": "<<x<<endl;
#define trace2(x, y)             cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
#define mod 1000000007
#define mem(a,b) memset(a,b,sizeof(a))
#define chk(a) if(a>=mod) a%mod;
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
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
priority_queue <int> p;
vi v;
int k=0;
void insertmin(int i)
{
	int root=i/2;
	if(root==0)
	    return ;
	if(v[i]<v[root])
	{
		swap(v[root],v[i]);
		insertmin(root);
	}
}
void remove_max()
{
	int temp=p.top();
	p.pop();
	v.eb(temp);
	int sz=sc(v);
	insertmin(sz-1);
}
void min_heap(int i)
{
    int l=2*i,r=2*i+1,s,sz=sc(v);
    if(l<sz and v[l]<v[i])
        s=l;
    else
        s=i;
    if(r<sz and v[r]<v[s])
        s=r;
    if(s!=i)
    {
        swap(v[s],v[i]);
        min_heap(s);
    }
}
void remove_min()
{
    int temp=p.top();
    p.pop();
    p.push(v[1]);
    v[1]=temp;
    min_heap(1);
}
int main() 
{
	FastIO();
	v.clear();
	v.eb(0);
	int q,n,temp;
	cin>>q;
	while(q--)
	{
		cin>>temp;
		/*f(i,0,sc(v))
			cout<<v[i]<<" ";
		cout<<endl;*/
		if(temp==1)
		{
			cin>>n;
			k++;
			p.push(n);
			if(k%3==0)
			    remove_max();
		}
		else
		{
			if(k<3)
				cout<<"No reviews yet"<<endl;
			else
			{
			    while(p.top()>v[1])
			        remove_min();
			    cout<<v[1]<<endl;
			}
		}
	}
	return 0;
}
