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
vector < double > r(4);
int main() 
{
	FastIO();
	ll t,n,p,m,b;
	long double x,y,num,den,s;
	cin>>t>>n>>p>>m>>b;
	cin>>r[0]>>r[1]>>r[2]>>r[3];
	x=r[0]*r[1];
	y=r[0]-r[1];
//x^2+(yr[i-1])^2+2*x*y*r[i-1]-4*x*y*r[i-1]+4*x*r[i-1]*r[i-1]
//(x-y*r[i-1])^2
	double k=0.0000001;
	if(p>=m)
		p%=m;
	int i=4,c=0;
	for(;;i++)
	{
	    num=pow(x*r[i-1],2);
	    den=(pow(x+r[i-1]*y,2)-4*x*r[i-1]*(y-r[i-1]))*r[i-2];
	    r.eb(num/den);
	    //cout<<r[i]<<" ";
	    if(r[i]<k)
	    	break;
	    if(r[i-1]-r[i]<=k)
	    	c++;
	    //cout<<r[i]<<" "<<r[i-1]<<" "<<r[i]-r[i-1]<<" "<<k<<" "<<c<<endl;
	    if(c==100000000)
	    	break;
	 }
	 /*f(i,0,sc(r))
	 	cout<<r[i]<<" ";
	 cout<<endl;*/
	 //cout<<i<<endl;
	 s=0.0;
	 if(b>i+1)
	 {
	 	cout<<t*r.back()<<endl;
	 	return 0;
	 }
	 while(t--)
	 {
	     n=(p*n)%m+b;
	     if(n>i+1)
	     	s+=r.back();
	     else
	     	s+=r[n-1];
	 }
	cout<<std::fixed<<setprecision(6)<<s<<endl;
	return 0;
}
