#include<bits/stdc++.h>
#define ll long long int
#define sc(v) v.size()
#define eb emplace_back
#define pb pop_back
#define stl(a,it) for(auto it: a)
#define f(i,a,b) for(int i=a;i<b;i++)
#define TC() int t;cin>>t;while(t--)
#define contain(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define mk make_pair
#define endl "\n"
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
void FastIO(){ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);}
//TEMPLATE ENDS HERE
const int N=1e5+5;
const ll MAX=1e9;
ll ar[N];
class seg
{
    public:
        int ma,mi;
}node[3*N];
void build(int cur,int i,int j)
{
    if(i>j)
        return ;
    if(i==j)
    {
        node[cur].ma=ar[i];
        node[cur].mi=ar[i];
        return ;
    }
    int mid=(i+j)/2;
    build(2*cur,i,mid);
    build(2*cur+1,mid+1,j);
    node[cur].ma=max(node[2*cur].ma,node[2*cur+1].ma);
    node[cur].mi=min(node[2*cur].mi,node[2*cur+1].mi);
}
ll minquery(int cur,int i,int j,int l,int r)
{
    if(i>r or j<l or i>j)
        return MAX;
    if(i>=l and j<=r)
        return node[cur].mi;
    int mid=(i+j)/2;
    return min(minquery(2*cur,i,mid,l,r),minquery(2*cur+1,mid+1,j,l,r));
}
ll maxquery(int cur,int i,int j,int l,int r)
{
    if(i>r or j<l or i>j)
        return 0;
    if(i>=l and j<=r)
        return node[cur].ma;
    int mid=(i+j)/2;
    return max(maxquery(2*cur,i,mid,l,r),maxquery(2*cur+1,mid+1,j,l,r));
}
int main() 
{
    FastIO();
    int n,q,l,r;
    ll mini;
    double maxi,ans1,ans2;
    cin>>n;
    f(i,0,n)
        cin>>ar[i];
    build(1,0,n-1);
    //f(i,1,50)
        //cout<<i<<" "<<node[i].mi<<" "<<node[i].ma<<endl;
    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        mini=minquery(1,0,n-1,l,r);
        maxi=double(2.0*mini+maxquery(1,0,n-1,l,r)-mini)/2.0;
        ans1=double(maxquery(1,0,n-1,0,l-1)+mini);
        ans2=double(maxquery(1,0,n-1,r+1,n-1)+mini);
        //cout<<mini<<" "<<maxi<<" "<<ans1<<" "<<ans2<<endl;
        if(ans2>ans1)
            ans1=ans2;
        if(ans1>maxi)
            maxi=ans1;
        cout<<std::fixed<<setprecision(1)<<maxi<<endl;
    }
	return 0;
}
