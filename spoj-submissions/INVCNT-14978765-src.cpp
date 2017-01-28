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
//void FastIO(){ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);}
const int N=200005;
int tree[N];
ll ar[N],ar1[N];
ll read(int x)
{
    ll s=0;
    while(x>0)
    {
        s+=tree[x];
        x-=x&(-x);
    }
    return s;
}
void update(int x,int v)
{
    while(x<=N)
    {
        tree[x]+=v;
        x+=x&(-x);
    }
}
int main() 
{
    //FastIO();
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(tree,0,sizeof(tree));
        f(i,0,n)
        {
            scanf("%lld",&ar[i]);
            ar1[i]=ar[i];
        }
        sort(ar1,ar1+n);
        f(i,0,n)
            ar[i]=int(lower_bound(ar1,ar1+n,ar[i])-ar1)+1;
        ll inv=0;
        for(int i=n-1;i>=0;i--)
        {
            inv+=read(ar[i]-1);
            //cout<<ar[i]<<" ";
            update(ar[i],1);
        }
        printf("%lld\n",inv);
    }
	return 0;
}