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
const int N=1e7+5;
int fac[N];
vi prime;
void pre()
{
	f(i,2,N)
	{
		if(!fac[i])
		{
			fac[i]=i;
			prime.eb(i);
		}
		int j=0;
		while(j<sc(prime) and  i*prime[j]<=N)
		{
			fac[i*prime[j]]=prime[j];
			j++;
		}
	}
}
ll power(ll a,int b)
{
    ll x=1;
    //cout<<a<<" "<<b<<endl;
    while(b)
    {
        if(b&1)
            x*=a;
        a*=a;
        b>>=1;
    }
    //cout<<x<<" resturn "<<endl;
    return x;
}
int main() 
{
    int n;
    ll ans,cnt=0;
	pre();
	TC()
	//for(int i=2000000;i<=2500000;i++)
	{
	    scanf("%d",&n);
	    //n=i;
	    ans=1;
	    while(n>1)
	    {
	        int x=fac[n],c=0;
	        //cout<<n<<"***"<<x<<endl;
	        while(n%x==0)
	        {
	            c++;
	            n/=x;
	        }
	        //cout<<n<<" "<<x<<" "<<c<<endl;
	        if(c!=1)
	        	ans*=((power((ll)x,2*c+1)+1)/(x+1));
	        else
	        {
	        	/*cout<<"x: "<<x<<endl;
	        	cout<<x*x-x+1<<" "<<x*(x-1)+1<<endl;
	        	cout<<"a "<<temp*temp-temp+1<<" "<<temp*(temp-1)+1<<endl;
	        	cout<<"temp "<<temp<<endl;*/
	        	ll temp=(ll)x;
	        	ans*=(temp*temp-temp+1);
	        }
	        //cout<<x<<" "<<ans<<endl;
	    }
	    //cnt+=ans;
	    //ll x=2425001;
	    //ans=1;
	    //ans*=(x*x-x+1);
	    //cout<<ans<<endl;
	    //cout<<x*x-x+1<<" "<<x*(x-1)+1<<endl;
	    printf("%lld\n",ans);
	}
	//cout<<cnt<<endl;
	return 0;
}
