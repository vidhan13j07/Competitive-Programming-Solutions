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
const int N=4005;
int v[N][N];
int ar[N];
pi p[N];
int main() 
{
    int n,m,mi=5000,a,b;
    cin>>n>>m;
    f(i,0,N)
        f(j,0,N)
            v[i][j]=0;
    f(i,0,m)
    {
        cin>>a>>b;
        ar[a]++;
        ar[b]++;
        v[a][b]=1;
        v[b][a]=1;
        p[i].fi=a;p[i].se=b;
    }
    f(i,0,m)
    {
        a=p[i].fi;b=p[i].se;
        f(j,1,n+1)
            if(j==a or j==b)
                continue;
            else if(v[a][j]==1 and v[b][j]==1)
                mi=min(mi,ar[a]+ar[b]+ar[j]-6);
    }
    if(mi==5000)
        cout<<"-1"<<endl;
    else
        cout<<mi<<endl;
    return 0;
}