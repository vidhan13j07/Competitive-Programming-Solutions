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
pi p[N];
vi v[2*N];
int ans[N],freq[2*N],ab[2*N],ar[N];
bool cmp(int i,int j)
{
    return p[i].fi+p[i].se>=p[j].se+p[j].fi;
}
int cal(int i)
{
    i++;
    int ret=-1;
    while(i<N)
    {
        ret=max(ret,ab[i]);
        i+= i&(-i);
    }
    return ret;
}
void update(int i,int val)
{
    i++;
    while(i>0)
    {
        ab[i]=max(ab[i],val);
        i-= i&(-i);
    }
}
int main() 
{
    int n;
    scanf("%d",&n);
    f(i,0,N)
        ab[i]=-1;
    f(i,1,n+1)
    {
        scanf("%d %d",&p[i].fi,&p[i].se);
        int d=p[i].se-p[i].fi+N-5;
        v[d].eb(i);
    }
    f(i,1,n+1)
    {
        scanf("%d",&ar[i]);
        freq[ar[i]+N-5]++;
    }
    f(i,1,n+1)
        if(freq[ar[i]+N-5]!=sc(v[ar[i]+N-5]))
        {
            cout<<"NO\n";
            return 0;
        }
    f(i,0,2*N)
        sort(v[i].begin(),v[i].end(),cmp);
    f(i,1,n+1)
    {
        int x=v[ar[i]+N-5].back();
        int val=cal(p[x].fi);
        if(val>=p[x].se)
        {
            cout<<"NO\n";
            //cout<<x<<" "<<i<<endl;
            return 0;
        }
        update(p[x].fi,p[x].se);
        ans[i]=x;
        v[ar[i]+N-5].pop_back();
    }
    cout<<"YES\n";
    f(i,1,n+1)
        printf("%d %d\n",p[ans[i]].fi,p[ans[i]].se);
    return 0;
}