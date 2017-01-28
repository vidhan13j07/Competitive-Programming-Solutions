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
int cnt[N];
bool vis[N];
vi v[N];
int main() 
{
    int n,m,a,b;
    ll ma=0;
    scanf("%d %d",&n,&m);
    f(i,1,n+1)
    {
        cnt[i]=1;
        vis[i]=0;
        v[i].clear();
    }
    f(i,0,m)
    {
        scanf("%d %d",&a,&b);
        v[a].eb(b);
        v[b].eb(a);
    }
    f(i,1,n+1)
    {
        for(auto it:v[i])
            if(vis[it])
                cnt[i]=max(cnt[i],cnt[it]+1);
        vis[i]=1;
        //trace3(i,cnt[i],v[i].size());
        ma=max(ma,(ll)cnt[i]*v[i].size());
    }
    printf("%lld\n",ma);
    return 0;
}