#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define sc(v) v.size()
#define eb emplace_back
#define pb pop_back
#define stl(a,it) for(auto it: a)
#define what_is(x) cerr << #x << " is " << x << endl
#define f(i,a,b) for(int i=a;i<b;i++)
#define contain(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define mk make_pair
#define mem(a) memset(a,0,sizeof(m))
template <class T1, class T2, class Pred = std::less<T2> >
struct sort_pair_second {
    bool operator()(const std::pair<T1,T2>&left, const std::pair<T1,T2>&right) {
        Pred p;
        return p(left.second, right.second);
    }
};
using namespace std;
const ll mod=1000000000;
const int l=2005;
vector <bool> primechk(3999,1);
vector <int> prime;
ll a[l],b[l],s[l];
 
void primecal()
{
	prime.eb(2);
	prime.eb(3);
	for(int i=5,t=2;i<4000;i+=t,t=6-t)
		if(primechk[i])
		{
			prime.eb(i);
			if(i<65)
			{
				for(int j=i*i,k=2*i;j<4000;j+=k)
					primechk[j]=0;
			}
		}
	//cout<<sc(prime)<<endl;
}
 
ll count(int n,int p)
{
	int k=0;
	while(n)
	{
		k+=n/p;
		n/=p;
	}
	return k;
}
 
ll power(int a,int b)
{
	ll x=1;
	while(b)
	{
		if(b&1)
			x*=a;
		if(x>=mod)
			x%=mod;
		a*=a;
		if(a>mod)
			a%=mod;
		b>>=1;
	}
	return x;
}
 
ll comb(int n,int r)
{
	ll ans=1;
	int i=0,k;
	while(i<sc(prime) and prime[i]<=n)
	{
		k=count(n,prime[i])-count(r,prime[i])-count(n-r,prime[i]);
		ans=(ans*power(prime[i],k))%mod;
		i++;
	}
	return ans;
}
 
int main() 
{
	std::ios_base::sync_with_stdio(false);cin.tie(0);
	int t,n,m;
	ll ans;
	primecal();
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		f(i,0,m+1)
			if(!i)
				a[i]=1;
			else
				a[i]=(comb(m+i-1,i))%mod;
		/*f(i,0,m+1)
			cout<<a[i]<<endl;*/
		f(i,1,n+1)
		{
			if(i==1)
				f(j,0,m+1)
					b[j]=a[j];
			else
				f(j,0,m+1)
					b[j]=(a[j]*s[j])%mod;
			/*f(j,0,m+1)
				cout<<b[j]<<" ";
			cout<<endl;*/
			mem(s);
			f(j,0,m+1)
			{
				if(!j)
					s[j]=1;
				s[j]=(s[j-1]+b[j])%mod;
			}
		}
		cout<<s[m]<<endl;
	}
	return 0;
}
/*
10
2000 2000
2000 1999
1999 2000
1998 2000
1999 1999
2000 1998
1998 1998
1997 1997 
2000 1997
1997 2000
*/ 
/*
961081001
531303701
164490000
86862500
80000000
65126101
264455000
776000000
385849851
927080000 
*/
