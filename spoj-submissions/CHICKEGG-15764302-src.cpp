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
const int N=1e3+5;
ll ar[N];
double quad_eqn(double a, double b, double c)
{ 
  double D = b*b - 4*a*c, x1, x2;
  if (b > 0)
  	x1 = (-b - sqrt(D))/(2*a);
  else
  	x1 = (-b + sqrt(D))/(2*a);
  x2 = c / (a * x1);
  return max(x1, x2);
}
ll egg(ll d, ll x)
{
  ll k = quad_eqn(1, 2*d-1, -2*x);
  while (k*k + (2*d-1)*k <= 2*x)
  	++k;
  while (k*k + (2*d-1)*k  > 2*x)
  	--k;
  return k;
}
ll cal(int n,ll d)
{
	ll s=0;
	f(i,0,n)
		s+=egg(ar[i],d);
	return s;
}
int main() 
{
	int n;
	ll k;
	TC()
	{
		scanf("%d %lld",&n,&k);
		f(i,0,n)
			scanf("%lld",&ar[i]);
		/*ll i=0,j=1e18,mid,x;
		while(i<=j)
		{
			mid=(i+j)/2;
			x=cal(n,mid);
			//cout<<i<<" "<<j<<" "<<mid<<" "<<x<<endl;
			if(x<k)
				i=mid+1;
			else
				j=mid-1;
		}
		printf("%lld\n",mid);*/
		ll lo = 0, hi = 1;
	 	while (cal(n,hi) < k)
	 	{
      		lo = hi; 
      		hi *= 2;
    	}
    	while (lo+1 < hi)
    	{
      		ll mi = (lo + hi) / 2;
      		if (cal(n,mi) < k)
      			lo = mi;
      		else
      			hi = mi;
    	}
    	printf("%lld\n", hi);
	}
	return 0;
}