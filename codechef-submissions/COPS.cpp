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
//TEMPLATE ENDS HERE
ll ans;
int ar[105];
int main() 
{
	int m,x,y,temp,a,ma,mi;
	TC()
	{
		memset(ar,0,sizeof(ar));
		ans=0;
		scanf("%d %d %d",&m,&x,&y);
		temp=x*y;
		while(m--)
		{
			scanf("%d",&a);
			ma=max(0,a-temp-1);
			mi=min(99,a+temp-1);
			for(int i=ma;i<=mi;i++)
				ar[i]=1;
		}
		f(i,0,100)
			if(ar[i]==0)
				ans++;
		printf("%lld\n",ans);
	}
	return 0;
}
