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
    const ll mod=1e9+7;
    const int N=1e6+5;
    int c[N],d[N];
    ll power(ll a,ll b)
    {
    	ll x=1;
    	while(b)
    	{
    		if(b&1)
    			x*=a;
    		a*=a;
    		if(x>=mod)
    			x%=mod;
    		if(a>=mod)
    			a%=mod;
    		b>>=1;
    	}
    	return x;
    }
    int main() 
    {
    	int t,a,b,m,x,y,n,k;
    	ll ans,lc;
    	scanf("%d",&t);
    	scanf("%d %d",&n,&k);
    	scanf("%d %d %d",&a,&b,&m);
    	f(i,1,t)
    		scanf("%d",&c[i]);
    	f(i,1,t)
    		scanf("%d",&d[i]);
    	f(i,0,t)
    	{
    		if(i>0)
    		{
    			n=ans*a+c[i];
    			k=ans*b+d[i];
    			if(n>=m)
    				n%=m;
    			n++;
    			if(k>=n)
    				k%=n;
    			k++;
    		}
    		ans=n;
    		//cout<<n<<" "<<k<<endl;
    		if(k>=2)
    		{
    			n--;
    			k--;
    			lc=((n-k+1)*(n-k+2))/__gcd(n-k+1,n-k+2);
    			ll temp=n-k+3;
    			while(temp<=(n+1))
    			{
    				lc=(lc*temp)/__gcd(lc,temp);
    				temp++;
    			}
    			ans*=lc;
    			//cout<<ans<<endl;
    			if(ans>=mod)
    				ans%=mod;
    			ans=(ans*power(n+1,mod-2))%mod;
    		}
    		printf("%lld\n",ans);
    		//cout<<"X"<<endl;
    	}
    	return 0;
    }
