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
#define trace1(x)                cerr <<#x<<": "<<x<<endl;
#define trace2(x, y)             cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
#define mod 1000000007
#define mem(a,b) memset(a,b,sizeof(a))
#define chk(a) if(a>=mod) a%mod;
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
	ll n,k,temp,remain,s;
	TC()
	{
		cin>>n>>k;
		s=0,remain=k;
		while(n--)
		{
			cin>>temp;
			//cout<<temp<<" ";
			if(temp==remain or temp+1==remain)
			{
			    //cout<<"a";
				s++;
				remain=k;
			}
			else if(temp>remain)
			{
			    //cout<<"b";
				temp-=remain;
				s++;
				s+=(temp/k);
				if(temp%k==0)
					remain=k;
				else if(temp%k==k-1)
				{
					remain=k;
					s++;
				}
				else if(n==0 and temp>0)
				    s++;
				else
					remain=k-(temp+1)%k;
			}
			else
			{
			    //cout<<"c";
				remain-=(temp+1);
				if(n==0 and remain>0){//cout<<"s";
				    s++;}
			}
			//cout<<remain<<" "<<s<<endl;
		}
		//cout<<endl;
		cout<<s<<endl;
	}
	return 0;
}
//3+6+2+1+3+1+1+1
//3+6+2+4+3
