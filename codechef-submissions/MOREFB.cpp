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
#define m 99991
template <class T1, class T2, class Pred = std::less<T2> >
struct sort_pair_second {
    bool operator()(const std::pair<T1,T2>&left, const std::pair<T1,T2>&right) {
        Pred p;
        return p(left.second, right.second);
    }
};
using namespace std;
 
//vector <ll> v;
ll mod=33330;
 
/*void pre()
{
	ll c;
	v.eb(1);
	v.eb(1);
	f(i,1,33330)
	{
		c=(v[i-1]+v[i])%m;
		v.eb(c);
	}
	mod=sc(v);
}*/
 
ll fibonacci(ll n)
{
    ll fib[2][2]= {{1,1},{1,0}},ret[2][2]= {{1,0},{0,1}},tmp[2][2]= {{0,0},{0,0}};
    int i,j,k;
    while(n)
    {
        if(n&1)
        {
            memset(tmp,0,sizeof tmp);
            for(i=0; i<2; i++) for(j=0; j<2; j++) for(k=0; k<2; k++)
                        tmp[i][j]=(tmp[i][j]+(ret[i][k]*fib[k][j])%m)%m;
            for(i=0; i<2; i++) for(j=0; j<2; j++) ret[i][j]=tmp[i][j];
        }
        memset(tmp,0,sizeof tmp);
        for(i=0; i<2; i++) for(j=0; j<2; j++) for(k=0; k<2; k++)
                    tmp[i][j]=(tmp[i][j]+(fib[i][k]*fib[k][j])%m)%m;
        for(i=0; i<2; i++) for(j=0; j<2; j++) fib[i][j]=tmp[i][j];
        n/=2;
    }
    return (ret[0][1]);
} 
 
bool choose(int a[], int ar[], int n, int r,long long int *sum)
{
	*sum=0;
	int i=r;
	while(i>=0 and ar[i]==n-r+i)
		i--;
	if(i<0)
		return false;
	ar[i]=ar[i]+1;
	*sum=*sum+a[ar[i]];
	for(int j=i+1;j<=r;++j)
	{
		ar[j]=ar[i]+j-i;
		*sum=(*sum+a[ar[j]])%mod;
	}
	i--;
	while(i>=0)
	{
		*sum=(*sum+a[ar[i]])%mod;
		i--;
	}
	return true;
}
 
int main() 
{
	std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//pre();
	int n,k;
	ll sum=0;
	cin>>n>>k;
	int a[n];
	int b[k];
	int i=0;
	while(i<n)
	{
		cin>>a[i];
		if(a[i]>=mod)
			a[i]%=mod;
		if(i<k)
		{
			b[i]=i;
			sum+=a[i];
		}
		i++;
	}
	/*f(i,0,n)
		cout<<a[i]<<" ";
	cout<<endl;*/
	ll fibsum=0;
	do{
	//	cout<<sum<<" ";
		if(sum>=mod)
			sum%=mod;
		fibsum+=fibonacci(sum);
		if(fibsum>=m)
			fibsum%=m;
	}while(choose(a,b,n-1,k-1,&sum));
//	cout<<endl;
	cout<<fibsum<<endl;
	return 0;
}
