#include<bits/stdc++.h>
#define ll long long int
#define sc(v) v.size()
#define eb emplace_back
#define pb pop_back
#define f(i,a,b) for(int i=a;i<b;i++)
#define TC() int t;cin>>t;while(t--)
#define mk make_pair
#define fi first
#define se second 
#define trace1(x)                cout <<#x<<": "<<x<<endl;
#define trace2(x, y)             cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
using namespace std;
ll ar[10];
ll cal(ll n)
{
	if(n<10)
		return n;
	ll cnt=0;
	while(n)
	{
		cnt+=n%10;
		n/=10;
	}
	return cal(cnt);
}
int main() 
{
	ll a1,d,l,r,cnt,a;
	TC()
	{
		scanf("%lld %lld %lld %lld",&a1,&d,&l,&r);
		d=cal(d);
		a=a1+(l-1)*d;
		r=r-l+1;
		l=0;
		cnt=0;
		ar[0]=-1;
		//cout<<l<<" "<<r<<endl;
		while(l<10)
		{
			a=cal(a);
			if(a==ar[0])
				break;
			ar[l]=a;
			cnt+=ar[l];
			a+=d;
			l++;
		}
		ll temp=r/l;
		//cout<<cnt<<" ";
		cnt=temp*cnt;
		//cout<<cnt<<" "<<l<<" "<<r<<" ";
		l=l*temp;
		//cout<<l<<endl;
		int i=0;
		while(l<r)
		{
			cnt+=ar[i];
			i++;
			l++;
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
