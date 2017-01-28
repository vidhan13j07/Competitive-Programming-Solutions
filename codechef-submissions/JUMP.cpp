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
        const int N=300005;
        ll dp[N],p[N],h[N];
        int a[N];
        ll distance(int i,int j)
        {
        	ll temp=abs(h[i]-h[j]);
        	return temp*temp;
        }
        int main() 
        {
        	int n;
        	scanf("%d",&n);
        	f(i,0,n)
        	{
        		scanf("%d",&p[i]);
        		dp[i]=1e18;
        	}
        	f(i,0,n)
        		scanf("%d",&a[i]);
        	f(i,0,n)
        		scanf("%d",&h[i]);
        	dp[0]=a[0];
        	f(i,1,n)
        		f(j,0,i)
        		{
        			if(p[i]<=p[j])
        				continue;
        			dp[i]=min(dp[i],a[i]+dp[j]+distance(i,j));
        		}
        	printf("%lld\n",dp[n-1]);
        	return 0;
        }
