#include<bits/stdc++.h>
    #define ll long long int
    #define sf(a) scanf("%d",&a)
    #define sfl(a) scanf("%lld",&a)
    #define pf(a) printf("%d\n",a)
    #define pfl(a) printf("%lld\n",a)
    #define sc(v) v.size()
    #define eb push_back
    #define pb pop_back
    #define stl(a,it) for(auto it: a)
    #define f(i,a,b) for(int i=a;i<b;i++)
    #define TC() int t;sf(t);while(t--)
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
    const int N=1e5+5;
    const int mod=1e9+7;
    int p[N],q[N];
    ll fac[N];
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
    ll calrank(int n,int *q,bool fl)
    {
        ll r=1;
        for(int i=0,k=n-1;i<n-1;i++,k--)
        {
        	r+=fac[k]*q[i];
        	//if(r>=mod)
        	//	r%=mod;
        	f(j,i+1,n)
        		if(q[j]>q[i])
        			q[j]-=1;
        	
        }
        /*f(i,0,n)
        	cout<<q[i]<<" ";
        cout<<endl;*/
        /*if(!fl)
        {
        	if(inv[0]%2==1)
        		r++;
        }*/
        return r;
    }
    int dfs(int *ar,int i,bool *vis)
    {
        if(vis[i])
            return 0;
        vis[i]=1;
        return 1+dfs(ar,ar[i],vis);
    }
    int main() 
    {
        int n,k;
        fac[0]=1;
        f(i,1,N)
        	fac[i]=(fac[i-1]*i)%mod;
        TC()
        {
            scanf("%d %d",&n,&k);
            bool visp[N],visq[N];
            f(i,0,n)
            {
                scanf("%d",&p[i]);
                p[i]--;
                visp[i]=0;
                visq[i]=0;
            }
            f(i,0,n)
            {
                scanf("%d",&q[i]);
                q[i]--;
            }
            bool fl=1;
            if(k==1)
            {
                f(i,0,n)
                    if(p[i]!=q[i])
                    {
                        fl=0;
                        break;
                    }
                if(fl)
                    printf("1\n");
            }
            else if(k==n)
            {
                int temp=0;
                while(temp<n and q[temp]!=p[0])
                    temp++;
                f(i,0,n)
                {
                    if(p[i]!=q[temp])
                    {
                        fl=0;
                        break;
                    }
                    temp++;
                    if(temp==n)
                        temp=0;
                }
                if(fl)
                    printf("%d\n",q[0]+1);
            }
            else if(k==2)
            {
                ll ans=calrank(n,q,1);
                printf("%lld\n",ans);
            }
            else
            {
                /*int temp[n],c=0,j,p0,p1;
                f(i,0,n)
                    temp[p[i]]=i;
                f(i,0,n)
                {
                    p0=q[i];
                    p1=p[i];
                    if (p0!=p1)
                    {
                        j=temp[p0];
                        p[i]=p0;
                        p[j]=p1;
                        temp[p0]=j;
                        temp[p1]=i;
                        c++;
                    }
                }
                cout<<c<<endl;
                if(c%2==1)
                    fl=0;*/
                int c1=0,c2=0;
                f(i,0,n)
                {
                	int temp=dfs(p,i,visp);
                	if(temp>0)
                		c1+=(temp-1)%2;
                }
                f(i,0,n)
                {
                	int temp=dfs(q,i,visq);
                	if(temp>0)
                		c2+=(temp-1)%2;
                }
                if(c1%2!=c2%2)
                	fl=0;
                else
                {
                    ll ans=calrank(n,q,0);
                  	//ans=(ans*power(2,mod-2))%mod;
                  	ans=(ans+1)/2;
                    printf("%lld\n",ans);
                }
            }
            if(!fl)
                printf("-1\n");
        }
    	return 0;
    }
