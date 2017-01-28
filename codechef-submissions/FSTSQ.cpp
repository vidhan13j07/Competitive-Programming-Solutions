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
    const int N=3e6+5;
    const ll mod=1e9+7;
    int ar[N];
    int main() 
    {
    	int n,d,sq,temp,c,k;
    	ll ans;
    	TC()
    	{
    		scanf("%d %d",&n,&d);
    		sq=d*d;
    		ans=0;
    		c=0;
    		int i;
    		for(i=0;i<n-1;i++)
    		{
    			ar[i]=(sq+c)%10;
    			c=(sq+c)/10;
    		}
    		sq+=c;
    		while(sq)
    		{
    			ar[i]=sq%10;
    			sq/=10;
    			i++;
    		}
    		int le=i;
    		int j=le-1;
    		c=0;
    		temp=0;
    		k=0;
    		for(i=0;i<n;i++)
    		{
    			k+=ar[i];
    			temp+=ar[j--];
    			ans=23*ans+(k+c)%10;
    			if(ans>=mod)
    				ans%=mod;
    			c=(k+c)/10;
    		}
    		k=temp;
    		if(d>3)
    		{
    			ans=23*ans+(k+c)%10;
    			if(ans>=mod)
    				ans%=mod;
    			c=(k+c)/10;
    		}
    		j=le-n;
    		for(i=n-1;i>0;i--)
    		{
    			k-=ar[j++];
    			ans=23*ans+(k+c)%10;
    			if(ans>=mod)
    				ans%=mod;
    			c=(k+c)/10;
    		}
    		while(c)
    		{
    			ans=23*ans+c%10;
    			c/=10;
    			if(ans>=mod)
    				ans%=mod;
    		}
    		printf("%lld\n",ans);
    	}
    	return 0;
    }
