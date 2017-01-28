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
int main() 
{
	FastIO();
	int x,y,n,k,temp;
	ll s;
	bool flag;
	TC()
	{
		flag=0;
		s=0;
		cin>>n>>k;
		if(n>1000)
			flag=1;
		if(!flag)
		{
			bool cat[n][n];
			f(i,0,n)
				f(j,0,n)
					cat[i][j]=0;
			while(k--)
			{
				cin>>x>>y;
				x--;y--;
				f(i,0,n)
				{
					temp=x+y-i;
					if(temp>=0 and temp<n)
						cat[i][temp]=1;
					temp=i+y-x;
					if(temp>=0 and temp<n)
						cat[i][temp]=1;
				}
			}
			f(i,0,n)
				f(j,0,n)
					if(cat[i][j]==0)
						s++;
		}
		else
		{
			vector < set<int> > v(n);
			ll c=0;
			/*f(i,0,n)
				f(j,0,sc(v[i]))
					cout<<"x"<<endl;*/
			while(k--)
			{
				cin>>x>>y;
				x--;y--;
				f(i,0,n)
				{
					temp=x+y-i;
					//v[i].insert(temp);
					/*if(temp==temp1)
						flag1=0;
					f(j,0,sc(v[i]))
					{
						//cout<<i<<" "<<v[i][j]<<" "<<temp<<" "<<temp1<<endl;
						if(v[i][j]==temp)
							flag1=0;
						if(v[i][j]==temp1)
							flag2=0;
						//cout<<i<<" "<<*j<<" "<<temp<<" "<<temp1<<endl;
					}*/
					if(temp>=0 and temp<n)
						v[i].insert(temp);
					temp=i+y-x;
					if(temp>=0 and temp<n)
						v[i].insert(temp);
					//f(j,0,sc(v[i]))
					//	cout<<i<<" "<<v[i][j]<<endl;
					//for(j=v[i].begin();j!=v[i].end();++i)
					//	cout<<i<<" "<<*j<<" "<<temp<<" "<<temp1<<endl;
				}
			}
			f(i,0,n)
			{
				/*f(j,0,sc(v[i]))
					cout<<i<<" "<<v[i][j]<<endl;*/
				c+=sc(v[i]);
			}
			s=n*n-c;
		}
		cout<<s<<endl;
	}
	return 0;
}
