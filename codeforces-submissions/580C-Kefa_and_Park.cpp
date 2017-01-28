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
const int N=1e5+5;
vi v[N];
bool vis[N];
int ar[N],n,m,s[N],ans;
int dfs(int i,int c,bool ok)
{
    if(vis[i])
        return 0;
    vis[i]=1;
    if(ar[i])
        c++;
    else
        c=0;
    if(c>m)
        ok=0;
    if(!ok)
        return 1;
    int temp=0;
    f(j,0,sc(v[i]))
        temp+=dfs(v[i][j],c,ok);
    //trace5(i,temp,ok,c,ans);
    if(!temp and ok and c<=m)
        ans++;
    return 1;
}
int main() 
{
    int a,b;
    cin>>n>>m;
    f(i,1,n+1)
        cin>>ar[i],vis[i]=0,s[i]=0;
    f(i,1,n)
    {
        cin>>a>>b;
        v[a].eb(b);
        v[b].eb(a);
    }
    ans=0;
    int temp=dfs(1,0,1);
    /*f(i,0,n+1)
        cout<<s[i]<<" ";
    cout<<endl;
    f(i,2,n+1)
        if(s[i]!=-1 and s[i]<=m)
            ans++;*/
    cout<<ans<<endl;
    return 0;
}